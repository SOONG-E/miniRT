#include "miniRT.c"

int	key_event(int key, t_mlx *mlx)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		exit(0);
	}
	return (0);
}

int	exit_hook(void)
{
	exit(0);
}
