#include "miniRT.h"

//최종적으로 각 픽셀이 가지게 되는 색 리턴
static int	ray_color(t_ray ray, t_meta meta, int j)
{
	// double	t;
(void)j;
	ray.obj_draw = init_record();
	if (is_hit(meta, ray, &ray.obj_draw) == TRUE)
		return(color_to_int(0, phong_lighting(meta, ray)));
	// t = 0.5 * (HEIGHT - 1 - j + 1.0); //투명도
	return (color_to_int(0, init_vec(1, 1, 1)));
	// return (color_to_int(t, init_vec((1.0 - t) + t * 0.5, (1.0 - t) + 0.7 * t, 1.0)));
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
			r.unit_vec = vec_sub(vec_add(vec_add(ll_corner, vec_mul(bg.hori, u)), vec_mul(bg.verti, v)), r.coor);
			r.unit_vec = vec_unit(r.unit_vec);
			put_pixel(mlx, i, j, ray_color(r, meta, j));
			++i;
		}
		++j;
	}
}

static void	pixel_put(t_mlx *mlx, t_meta meta)
{
	t_vec	w;
	t_vec	u;
	t_vec	v;
	t_bg	bg;
	t_vec	ll_corner;

	w = vec_unit(vec_mul(meta.cam.vec, -1));
	// w = vec_unit(vec_sub(meta.cam.coor, meta.cam.vec));
	u = vec_unit(vec_cross(init_vec(0, 1, 0), w));
	v = vec_cross(w, u);
	printf("w : %f %f %f \nv : %f %f %f \nz : %f %f %f \n ", w.x, w.y , w.z, v.x, v.y, v.z, u.x, u.y, u.z);
	bg.hori = vec_mul(u, VP_WIDTH); 
	bg.verti = vec_mul(v, VP_HEIGHT);
	ll_corner = get_lowerleft_corner(meta.cam.coor, bg, w);
	put_color(mlx, meta, bg, ll_corner);
}

void	ray_tracing(t_meta meta)
{
	t_mlx	mlx;

	window_init(&mlx);
	pixel_put(&mlx, meta);
	open_screen(mlx);
}
