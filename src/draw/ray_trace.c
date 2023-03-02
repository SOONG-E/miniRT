#include "miniRT.h"

static int	ray_color(t_ray ray, t_meta meta)
{
	double	t;

	ray.obj_draw = init_record();
	if (is_hit(meta, ray, &ray.obj_draw) == TRUE)
		return(color_to_int(0, phong_lighting(meta, ray)));
	t = 0.5 * (ray.unit_vec.y + 1.0);
	return (color_to_int(t, init_vec((1.0 - t) + t * 0.5, (1.0 - t) + 0.7 * t, 1.0)));
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
			put_pixel(mlx, i, j, ray_color(r, meta));
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
	u = vec_unit(vec_cross(init_vec(0, 1, 0), w));
	v = vec_cross(w, u);
	bg.theta = (((double)meta.cam.fov * M_PI) / 180);
	bg.vp_height = 2.0 * tan(bg.theta / 2.0);
	bg.verti = vec_mul(v, bg.vp_height);
	bg.hori = vec_mul(u, bg.vp_height * (16.0 / 9.0)); 
	ll_corner = get_lowerleft_corner(meta.cam.coor, bg, w);
	put_color(mlx, meta, bg, ll_corner);
}

void	ray_tracing(t_meta *meta)
{
	pixel_put(&(meta->mlx), *meta);
	mlx_put_image_to_window(meta->mlx.mlx_ptr, meta->mlx.win_ptr, meta->mlx.img.img_ptr, 0, 0);
}
