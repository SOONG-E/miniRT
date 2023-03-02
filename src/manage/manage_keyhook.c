#include "miniRT.h"

int	key_event(int key, t_meta *meta)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_window(meta->mlx.mlx_ptr, meta->mlx.win_ptr);
		exit_hook(meta);
	}
	return (0);
}

int	exit_hook(t_meta *meta)
{
	free_objs(meta->objs);
	exit(0);
}
