#include "miniRT.h"

static t_vec	get_lowerleft_corner(t_vec origin, t_vec hori, t_vec verti)
{
	double	focal_length;

	focal_length = 1.0;

	return (init_vec(origin.x + (-hori.x / 2) + (-verti.x / 2) + (0)
		,origin.y + (-hori.y / 2) + (-verti.y / 2) + (0) 
		,origin.z + (-hori.z / 2) + (-verti.z / 2) + (-focal_length)));
}

static void	put_color(t_mlx *mlx, t_meta meta, t_bg bg, t_vec ll_corner)
{
	t_ray	r;
	double	u;
	double	v;
	int		i;
	int		j;

	r.coor = init_vec(0, 0, 0); //이거 카메라 좌표로 변경해야하나요???
	j = HEIGHT - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < WIDTH)
		{
			u = (double)i / (WIDTH - 1);
			v = 1 - (double)j / (HEIGHT - 1);
			r.unit_vec = vec_unit(init_vec(ll_corner.x + u * bg.hori.x + v * bg.verti.x - meta.cam.coor.x,
			ll_corner.y + u * bg.hori.y + v * bg.verti.y - meta.cam.coor.y,
			ll_corner.z + u * bg.hori.z + v * bg.verti.z - meta.cam.coor.z));
			put_pixel(mlx, i, j, ray_color(r, meta));
			++i;
		}
		--j;
	}
}

void	draw_background(t_mlx *mlx, t_meta meta)
{
	t_bg	bg;
	t_vec	ll_corner;

	bg.hori = init_vec(VP_WIDTH, 0, 0);
	bg.verti = init_vec(0, VP_HEIGHT, 0);
	ll_corner = get_lowerleft_corner(meta.cam.coor, bg.hori, bg.verti);
	put_color(mlx, meta, bg, ll_corner);
}