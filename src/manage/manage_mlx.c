#include "miniRT.h"

void	put_pixel(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->img.data + (y * mlx->img.length + x * (mlx->img.bpp / 8));
	*(unsigned int *)dst = color;
}

static void	change_coor(int key, t_vec *coor)
{
	if (key == KEY_ARROW_UP)
		coor->z -= 1;
	else if (key == KEY_ARROW_DOWN)
		coor->z += 1;
	else if (key == KEY_ARROW_LEFT)
		coor->x -= 1;
	else if (key == KEY_ARROW_RIGHT)
		coor->x += 1;
	else if (key == KEY_SHIFT)
		coor->y += 1;
	else if (key == KEY_CTRL)
		coor->y -= 1;
}

static int	binding_key_events(int key, t_meta *meta)
{
	if (meta->mode != -1 && key == KEY_Z)
	{
		meta->mode = -1;
		return (TRUE);
	}
	if (meta->mode == -1)
	{
		if (key == KEY_L)
			meta->mode = KEY_L;
		else if (key == KEY_C)
			meta->mode = KEY_C;
		return (TRUE);
	}
	else if (meta->mode == KEY_L)
		change_coor(key, &(meta->light.coor));
	else if (meta->mode == KEY_C)
		change_coor(key, &(meta->cam.coor));
	ray_tracing(meta);
	return (TRUE);
}

void open_screen(t_mlx *mlx, t_meta *meta)
{
	mlx_key_hook(mlx->win_ptr, binding_key_events, meta);
	mlx_hook(mlx->win_ptr, 2, 1L << 0, &key_event, meta);
	mlx_hook(mlx->win_ptr, 17, 0, &exit_hook, meta);
	mlx_loop(mlx->mlx_ptr);
}

void	window_init(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "sangminiRT");
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	mlx->img.data = mlx_get_data_addr(mlx->img.img_ptr,
			&mlx->img.bpp, &mlx->img.length, &mlx->img.endian);
}