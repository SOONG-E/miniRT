#include "miniRT.h"

int	is_hit(t_meta meta, t_ray ray, t_record *rec)
{
	int	result;
	int	idx;

	result = FALSE;
	idx = -1;
	while (++idx < meta.obj_num)
	{
		if (meta.hits[meta.objs->type](meta.objs[idx], ray, rec) == TRUE)
			result = TRUE;
	}
	return result;
}

//최종적으로 각 픽셀이 가지게 되는 색 리턴
int	ray_color(t_ray ray, t_meta meta)
{
	double	t;

	ray.obj_draw = init_record();
	if (is_hit(meta, ray, &ray.obj_draw) == TRUE)
		return(color_to_int(0, vec_mul(vec_add(ray.obj_draw.normal, init_vec(1, 1, 1)), 0.5)));
	t = 0.5 * (ray.unit_vec.y + 1.011); //투명도
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
