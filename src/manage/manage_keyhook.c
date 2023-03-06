#include "miniRT.h"

int	key_event(int key, t_meta *meta)
{
	if (key == KEY_ESC)
		exit_hook(meta);
	return (0);
}

int	exit_hook(t_meta *meta)
{
	mlx_destroy_image(meta->mlx.mlx_ptr, meta->mlx.img.img_ptr);
	mlx_destroy_window(meta->mlx.mlx_ptr, meta->mlx.win_ptr);
	free_resources(meta);
	exit(0);
}

int	binding_key_events(int key, t_meta *meta)
{
	int	flag;

	flag = FALSE;
	if (meta->ctrl.category != -1 && key == KEY_Z)
		meta->ctrl.category = -1;
	if (meta->ctrl.category != -1 && key == KEY_TAB)
		select_obj(meta);
	if (meta->ctrl.category == -1)
	{
		set_category(key, meta);
		meta->ctrl.md = KEY_M;
	}
	else
		control_obj(key, meta, &flag);
	if (flag == TRUE)
		ray_tracing(meta);
	return (TRUE);
}