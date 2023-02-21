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
	double	t;

	unit_direction = vec_unit(r.vec);
	t = 0.5 * (unit_direction.y + 1.0);
	return (color_to_int(t, init_vec((1.0 - t) + t * 0.5, (1.0 - t) + 0.7 * t, 1.0)));
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
