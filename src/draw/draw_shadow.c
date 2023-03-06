/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shadow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:28:46 by yujelee           #+#    #+#             */
/*   Updated: 2023/03/06 16:28:47 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	is_hit_light(t_meta meta, t_ray ray, t_rec *rec)
{
	int	idx;

	idx = -1;
	while (++idx < meta.obj_num)
	{
		if (meta.hits[meta.objs[idx].type](meta.objs[idx], ray, rec) == TRUE)
			return (TRUE);
	}
	return (FALSE);
}

int	in_shadow(t_meta meta, t_ray light_ray, double light_len)
{
	t_rec	rec;

	rec.t_max = light_len;
	if (is_hit_light(meta, light_ray, &rec) == TRUE)
		return (TRUE);
	return (FALSE);
}
