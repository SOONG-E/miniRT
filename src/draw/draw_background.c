#include "miniRT.h"

static t_vec	get_lowerleft_corner(t_vec origin, t_vec hori, t_vec verti, t_cam cam)
{
	double	focal_length;

	focal_length = cam.fov / 180.0;
	t_vec corner = vec_sub(origin, vec_div(hori, 2.0));
	corner = vec_sub(corner, vec_div(verti, 2.0));
	corner = vec_sub(corner, init_vec(0.0, 0.0, focal_length));
	return (corner);
}

static void	put_color(t_mlx *mlx, t_meta meta, t_bg bg, t_vec ll_corner)
{
	t_ray	r;
	double	u;
	double	v;
	int		i;
	int		j;

	r.coor = meta.cam.coor;
	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			u = (double)i / (WIDTH - 1);
			v = 1.0 - ((double)j / (HEIGHT - 1));
			t_vec horizontal = vec_mul(bg.hori, u);
			t_vec vertical = vec_mul(bg.verti, v);
			t_vec dir = vec_add(ll_corner, horizontal);
			dir = vec_add(dir, vertical);
			dir = vec_sub(dir, r.coor);
			r.unit_vec = vec_unit(dir);
			put_pixel(mlx, i, j, ray_color(r, meta));
			++i;
		}
		++j;
	}
}

void	draw_background(t_mlx *mlx, t_meta meta)
{
	t_bg	bg;
	t_vec	ll_corner;

	bg.hori = init_vec(VP_WIDTH, 0, 0);
	bg.verti = init_vec(0, VP_HEIGHT, 0);
	ll_corner = get_lowerleft_corner(meta.cam.coor, bg.hori, bg.verti, meta.cam);
	put_color(mlx, meta, bg, ll_corner);
}