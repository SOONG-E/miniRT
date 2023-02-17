#include "miniRT.h"

t_rgb ray_color(t_cam r) {
    t_vec	unit_direction;
	double	t;
	
	unit_direction = vec_unit(r.vec);
    t = 0.5 * (unit_direction.y + 1.0);
	return (init_rgb((1.0 - t) * 1.0 + t * 0.5, (1.0 - t) * 1.0 + t * 0.7, (1.0 - t) * 1.0 + t * 1.0));
}

void	draw_background(t_mlx *mlx, t_meta meta)
{
	(void)meta;
	double	viewport_height;
	double	viewport_width;
	double	focal_length;
	t_vec	origin;
	t_vec	hori;
	t_vec	verti;
	t_vec	ll_corner;

	viewport_height = 2.0;
	viewport_width = (16.0 / 9.0) * viewport_height;
	focal_length = 1.0;

	origin = init_vec(0, 0, 0);
	hori = init_vec(viewport_width, 0, 0);
	verti = init_vec(0, viewport_height, 0);
	ll_corner = init_vec(origin.x + (-hori.x / 2) + (-verti.x / 2) + (0)
		,origin.y + (-hori.y / 2) + (-verti.y / 2) + (0) 
		,origin.z + (-hori.z / 2) + (-verti.z / 2) + (-focal_length));

	t_cam	r;
	r.coor = init_vec(0, 0, 0);
	double	u;
	double	v;

	for (int j = HEIGHT-1; j >= 0; --j) {
		for (int i = 0; i < WIDTH; ++i) {
        	u = (double)i / (WIDTH-1);
        	v = (double)j / (HEIGHT-1);
			r.vec = init_vec(ll_corner.x + u*hori.x + v*verti.x - origin.x,
			ll_corner.y + u*hori.y + v*verti.y - origin.y,
			ll_corner.z + u*hori.z + v*verti.z - origin.z);
			put_pixel(mlx, i, j, write_color(r.vec));
		}
	}
	mlx_hook(mlx->win_ptr, 2, 1L << 0, &key_event, &mlx);
	mlx_hook(mlx->win_ptr, 17, 0, &exit_hook, 0);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
	mlx_loop(mlx->mlx_ptr);
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
}
