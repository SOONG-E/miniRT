#include "miniRT.h"

void	pixel_put(t_mlx *mlx, t_meta meta)
{
	// = meta.cam.coor
	t_vec	origin;
	t_vec	horizontal;
	t_vec	vertical;
	t_vec	lower_left_corner;
	t_cam	ray;
	double	u;
	double	v;

	horizontal = init_vec(WIDTH, 0, 0);
	vertical = init_vec(0, HEIGHT, 0);
	lower_left_corner = 
		init_vec(origin.x + (- horizontal.x / 2) + (-vertical.x / 2) + (0)
		 ,origin.coor.y + (- horizontal.y / 2) + (-vertical.y / 2) + (0) 
		 ,origin.cam.coor.z + (- horizontal.z / 2) + (-vertical.z / 2) + (-1.0));
	i = HEIGHT - 1;
	while (i >= 0)
	{
		j = 0
		while (j < WIDTH)
		{
			u = j / (WIDTH - 1);
			v = i / (HEIGHT - 1);
			ray.o
		}
	}
	mlx_hook(mlx->win_ptr, 2, 1L << 0, &key_event, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, &exit_hook, 0);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
	mlx_loop(mlx);
}

void	ray_tracing(t_meta meta)
{
	t_mlx	mlx;

	window_init(&mlx);
	pixel_put(&mlx);
}
