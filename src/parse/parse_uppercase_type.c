/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_uppercase_type.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:29:17 by yujelee           #+#    #+#             */
/*   Updated: 2023/03/06 16:29:18 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <stdio.h>

void	parse_ambi_light(char **info, t_meta *meta)
{
	check_available(meta, A);
	meta->ambi.ratio = put_double(info[1], 0.0, 1.0);
	meta->ambi.rgb = vec_mul(make_rgb(info[2]), meta->ambi.ratio);
	meta->flag |= 0b100;
}

void	parse_camera(char **info, t_meta *meta)
{
	check_available(meta, C);
	meta->cam.coor = make_coor(info[1], 0, 0);
	meta->cam.vec = make_vec(info[2], -1, 1);
	meta->cam.fov = (int)put_double(info[3], 0, 180);
	meta->flag |= 0b10;
}

static t_light	*create_new_light(char **info, int count)
{
	t_light	*out;

	out = (t_light *)malloc(sizeof(t_light));
	if (out == NULL)
		ft_exit("system function fail");
	out->coor = make_coor(info[1], 0, 0);
	out->ratio = put_double(info[2], 0.0, 1.0);
	out->next = NULL;
	if (count == 3)
	{
		out->color = init_vec(out->ratio, out->ratio, out->ratio);
		return (out);
	}
	out->color = vec_mul(make_rgb(info[3]), out->ratio);
	return (out);
}

static void	add_new_light(char **info, t_light *head, int count)
{
	while (head->next != NULL)
		head = head->next;
	head->next = create_new_light(info, count);
}

void	parse_light(char **info, t_meta *meta, int count)
{
	if (count != 3 && count != 4)
		ft_exit("check num of information");
	if (meta->light == NULL)
	{
		meta->light = create_new_light(info, count);
		meta->flag |= 0b1;
		return ;
	}
	add_new_light(info, meta->light, count);
}
