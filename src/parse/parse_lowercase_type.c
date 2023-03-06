/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lowercase_type.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:29:13 by yujelee           #+#    #+#             */
/*   Updated: 2023/03/06 20:12:43 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	parse_sphere(char **info, t_meta *meta)
{
	int	idx;

	idx = get_index(meta);
	meta->objs[idx].num = idx;
	meta->objs[idx].type = SP;
	meta->objs[idx].coor = make_coor(info[1], 0, 0);
	meta->objs[idx].ratio = (put_double(info[2], 0, 0)) / 2;
	meta->objs[idx].rgb = make_rgb(info[3]);
}

void	parse_plane(char **info, t_meta *meta)
{
	int	idx;

	idx = get_index(meta);
	meta->objs[idx].num = idx;
	meta->objs[idx].type = PL;
	meta->objs[idx].coor = make_coor(info[1], 0, 0);
	meta->objs[idx].vec = make_vec(info[2], -1, 1);
	meta->objs[idx].rgb = make_rgb(info[3]);
}

void	parse_cylinder(char **info, t_meta *meta)
{
	int	idx;

	idx = get_index(meta);
	meta->objs[idx].num = idx;
	meta->objs[idx].type = CY;
	meta->objs[idx].coor = make_coor(info[1], 0, 0);
	meta->objs[idx].vec = make_vec(info[2], -1, 1);
	meta->objs[idx].cylin = make_cylin(info[3], info[4]);
	meta->objs[idx].rgb = make_rgb(info[5]);
}
