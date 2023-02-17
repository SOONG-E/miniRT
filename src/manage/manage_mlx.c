#include "miniRT.h"

void	put_pixel(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->img.data + (y * mlx->img.length + x * (mlx->img.bpp / 8));
	*(unsigned int *)dst = color;
}

void	window_init(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "sangminiRT");
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	mlx->img.data = mlx_get_data_addr(mlx->img.img_ptr,
			&mlx->img.bpp, &mlx->img.length, &mlx->img.endian);
}