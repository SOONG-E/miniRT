#include "miniRT.h"

t_vec ray_at(t_cam ray, double t)
{
	t_vec	out;

	out.x = ray.coor.x + ray.vec.x * t;
	out.y = ray.coor.y + ray.vec.y * t;
	out.z = ray.coor.z + ray.vec.y * t;
	return (out);
}

int	ray_color(t_cam r)
{
	t_vec	unit_direction;
	t_vec	color;
	t_vec	tmp;
	t_vec	N;
	double	t;
	double	t1;
	t_record	sp1;
	t_record	sp2;

	//sp1, 2
	sp1.center = init_vec(0, 0, -1);
	sp2.center = init_vec(0, -100.5, -1);
	sp1.r = 0.5;
	sp2.r = 100;
	t = hit_sphere(sp1.center, 0.5, r);
	t1 = hit_sphere(sp2.center, 100, r);
	if (t > 0.0)
	{
		tmp = ray_at(r ,t);
		N = vec_unit(init_vec(tmp.x - 0, tmp.y - 0, tmp.z - (-1)));
		color = vec_mul(init_vec(N.x + 1, N.y + 1, N.z + 1), 0.5);
		return (write_color(t, color));
	}
	else if (t1 > 0.0)
	{
		//tmp = ray_at(r ,t1);
		//N = vec_unit(init_vec(tmp.x - 0, tmp.y - 0, tmp.z - (-1)));
		//color = vec_mul(init_vec(N.x + 1, N.y + 1, N.z + 1), 0.5);
		color = init_vec(0.5, 1, 0.5);
		return (write_color(t1, color));
	}
	unit_direction = vec_unit(r.vec);
	t = 0.5 * (unit_direction.y + 1.0);
	return (write_color(t, init_vec((1.0 - t) + t * 0.5, (1.0 - t) + 0.7 * t, 1.0)));
}

/* int	ray_color(t_cam r)
{
	t_vec	unit_direction;
	t_vec	color;
	t_vec	tmp;
	t_vec	N;
	double	t;
	t_vec	center = init_vec(0, 0, -1);

	t = hit_sphere(center, 0.5, r);
	if (t != -1)
	{
		tmp = ray_at(r ,t);
		N = vec_unit(init_vec(tmp.x - 0, tmp.y - 0, tmp.z - (-1)));
		color = vec_mul(init_vec(N.x + 1, N.y + 1, N.z + 1), 0.5);
		return (write_color(t, color));
	}
	unit_direction = vec_unit(r.vec);
	t = 0.5 * (unit_direction.y + 1.0);
	return (write_color(t, init_vec((1.0 - t) + t * 0.5, (1.0 - t) + 0.7 * t, 1.0)));
} */

t_vec	get_lowerleft_corner(t_vec origin, t_vec hori, t_vec verti)
{
	double	focal_length;

	focal_length = 1.0;

	return (init_vec(origin.x + (-hori.x / 2) + (-verti.x / 2) + (0)
		,origin.y + (-hori.y / 2) + (-verti.y / 2) + (0) 
		,origin.z + (-hori.z / 2) + (-verti.z / 2) + (-focal_length)));
}

void	put_color(t_mlx *mlx, t_bg bg, t_vec origin, t_vec ll_corner)
{
	t_cam	r;
	double	u;
	double	v;
	int		i;
	int		j;

	r.coor = init_vec(0, 0, 0);
	j = HEIGHT - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < WIDTH)
		{
			u = (double)i / (WIDTH - 1);
			v = (double)j / (HEIGHT - 1);
			r.vec = init_vec(ll_corner.x + u * bg.hori.x + v * bg.verti.x - origin.x,
			ll_corner.y + u * bg.hori.y + v * bg.verti.y - origin.y,
			ll_corner.z + u * bg.hori.z + v * bg.verti.z - origin.z);
			put_pixel(mlx, i, j, ray_color(r));
			++i;
		}
		printf("%f, %f, %d\n", u, v, j);
		--j;
	}
}

/* void	put_color(t_mlx *mlx, t_bg bg, t_vec origin, t_vec ll_corner)
{
	t_cam	r;
	double	u;
	double	v;
	int		i;
	int		j;

	r.coor = init_vec(0, 0, 0);
	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			u = (double)i / (WIDTH - 1);
			v = (double)j / (HEIGHT - 1);
			r.vec = init_vec(ll_corner.x + u * bg.hori.x + v * bg.verti.x - origin.x,
			ll_corner.y + u * bg.hori.y + v * bg.verti.y - origin.y,
			ll_corner.z + u * bg.hori.z + v * bg.verti.z - origin.z);
			put_pixel(mlx, i, j, ray_color(r));
			++i;
		}
		printf("%f, %f\n", u, v);
		++j;
	}
} */

void	draw_background(t_mlx *mlx, t_meta meta)
{
	t_bg	bg;
	t_vec	ll_corner;

	bg.hori = init_vec(VP_WIDTH, 0, 0);
	bg.verti = init_vec(0, VP_HEIGHT, 0);
	ll_corner = get_lowerleft_corner(meta.cam.coor, bg.hori, bg.verti);
	put_color(mlx, bg, meta.cam.coor, ll_corner);
}

void open_screen(t_mlx mlx)
{
	mlx_hook(mlx.win_ptr, 2, 1L << 0, &key_event, &mlx);
	mlx_hook(mlx.win_ptr, 17, 0, &exit_hook, 0);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img.img_ptr, 0, 0);
	mlx_loop(mlx.mlx_ptr);
}

void	pixel_put(t_mlx *mlx, t_meta meta)
{
	draw_background(mlx, meta);
}

void	ray_tracing(t_meta meta)
{
	t_mlx	mlx;

	window_init(&mlx);
	pixel_put(&mlx, meta);
	open_screen(mlx);

}
