/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:37:17 by yujelee           #+#    #+#             */
/*   Updated: 2023/03/06 21:37:18 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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

static void	change_vec(int key, t_vec *vec)
{
	double	mat[3][3];
	t_vec	dir;

	dir = get_rotate_dir(key);
	rotation_matrix(dir, degree_to_radian(15), mat);
	*vec = apply_rotation_matrix(*vec, mat);
}

static void	set_mode(int key, t_meta *meta)
{
	if (meta->ctrl.category == KEY_L)
		return ;
	if (key == KEY_M)
	{
		meta->ctrl.md = KEY_M;
		return ;
	}
	meta->ctrl.md = KEY_D;
}

void	control_obj(int key, t_meta *meta, int *flag)
{
	*flag = TRUE;
	if (key == KEY_M || key == KEY_D)
	{
		set_mode(key, meta);
		*flag = FALSE;
		return ;
	}
	if (meta->ctrl.md == KEY_M && meta->ctrl.category == KEY_C)
		change_coor(key, &(meta->cam.coor));
	else if (meta->ctrl.md == KEY_M && meta->ctrl.category == KEY_L)
		change_coor(key, &(meta->ctrl.light->coor));
	else if (meta->ctrl.md == KEY_M && meta->ctrl.category == KEY_O)
		change_coor(key, &(meta->ctrl.obj->coor));
	else if (meta->ctrl.md == KEY_D && meta->ctrl.category == KEY_C)
		change_vec(key, &(meta->cam.vec));
	else if (meta->ctrl.md == KEY_D && meta->ctrl.category == KEY_O)
		change_vec(key, &(meta->ctrl.obj->vec));
	else
		*flag = FALSE;
}
