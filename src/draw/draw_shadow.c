#include "miniRT.h"

t_ray	init_ray(t_vec orig, t_vec dir)
{
	t_ray	new;

	new.coor = orig;
	new.unit_vec = dir;
	return (new);
}

int	in_shadow(t_meta meta, t_ray light_ray, double light_len)
{
	t_record	rec;
	rec.t_max = light_len;
	int	result;
	int	idx;

	result = FALSE;
	idx = -1;
	while (++idx < meta.obj_num)
	{
		if (meta.hits[meta.objs->type](meta.objs[idx], light_ray, &rec) == TRUE)
			result = TRUE;
	}
	return result;
}