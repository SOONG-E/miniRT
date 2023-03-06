/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_basic_vec.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:29:22 by yujelee           #+#    #+#             */
/*   Updated: 2023/03/06 16:29:23 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec	vec_add(t_vec v1, t_vec v2)
{
	t_vec	out;

	out.x = v1.x + v2.x;
	out.y = v1.y + v2.y;
	out.z = v1.z + v2.z;
	return (out);
}

t_vec	vec_sub(t_vec v1, t_vec v2)
{
	t_vec	out;

	out.x = v1.x - v2.x;
	out.y = v1.y - v2.y;
	out.z = v1.z - v2.z;
	return (out);
}

t_vec	vec_mul(t_vec v1, double t)
{
	t_vec	out;

	out.x = v1.x * t;
	out.y = v1.y * t;
	out.z = v1.z * t;
	return (out);
}

t_vec	vec_div(t_vec v1, double t)
{
	t_vec	out;

	out.x = v1.x * 1 / t;
	out.y = v1.y * 1 / t;
	out.z = v1.z * 1 / t;
	return (out);
}

t_vec	vecs_mul(t_vec v1, t_vec v2)
{
	t_vec	out;

	out.x = v1.x * v2.x;
	out.y = v1.y * v2.y;
	out.z = v1.z * v2.z;
	return (out);
}
