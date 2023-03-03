#include "miniRT.h"

int	key_event(int key, t_meta *meta)
{
	if (key == KEY_ESC)
	{
		exit_hook(meta);
	}
	return (0);
}

int	exit_hook(t_meta *meta)
{
	mlx_destroy_image(meta->mlx.mlx_ptr, meta->mlx.img.img_ptr);
	mlx_destroy_window(meta->mlx.mlx_ptr, meta->mlx.win_ptr);
	free_resources(meta);
	exit(0);
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

static void	change_vec(int key, t_vec *coor)
{
	if (key == KEY_ARROW_UP)
		coor->z -= 0.05;
	else if (key == KEY_ARROW_DOWN)
		coor->z += 0.05;
	else if (key == KEY_ARROW_LEFT)
		coor->x -= 0.05;
	else if (key == KEY_ARROW_RIGHT)
		coor->x += 0.05;
	else if (key == KEY_SHIFT)
		coor->y += 0.05;
	else if (key == KEY_CTRL)
		coor->y -= 0.05;
	*coor = clamp(*coor, -1, 1);
}

int	binding_key_events(int key, t_meta *meta)
{
	if (meta->mode != -1 && key == KEY_Z)
	{
		meta->mode = -1;
		return (TRUE);
	}
	if (meta->mode == -1)
	{
		if (key == KEY_D)
			meta->mode = KEY_D;
		else if (key == KEY_C)
			meta->mode = KEY_C;
		return (TRUE);
	}
	else if (meta->mode == KEY_D)
		change_vec(key, &(meta->cam.vec));
	if (meta->mode == KEY_C)
		change_coor(key, &(meta->cam.coor));
	ray_tracing(meta);
	return (TRUE);
}