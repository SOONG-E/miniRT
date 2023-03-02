#include "miniRT.h"

int	in_shadow(t_meta meta, t_ray light_ray, double light_len)
{
	t_record	rec;
	int	result;
	int	idx;

	rec.t_max = light_len;
	result = FALSE;
	idx = -1;
	while (++idx < meta.obj_num)
	{
		if (meta.hits[meta.objs[idx].type](meta.objs[idx], light_ray, &rec) == TRUE)
		{
			result = TRUE;
		}
	}
	return result;
}

int	light_shadow(t_meta meta, t_ray ray, t_light light)
{
	t_vec	light_dir;
	double	light_len;
	t_ray	light_ray;

	light_dir = vec_sub(light.coor, ray.obj_draw.p);
	light_len = vec_length(light_dir);
	light_ray.coor = vec_add(ray.obj_draw.p, vec_mul(ray.obj_draw.normal, T_MIN));
	light_ray.unit_vec = light_dir;
	if (in_shadow(meta, light_ray, light_len) == TRUE)
		return (TRUE);
	return (FALSE);
}