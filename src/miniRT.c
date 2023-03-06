/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:29:31 by yujelee           #+#    #+#             */
/*   Updated: 2023/03/06 21:36:04 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	print_manual(void)
{
	printf("press L for controlling lights\n");
	printf("press C for controlling camera\n");
	printf("press O for controlling objects\n");
	printf("press Z for reselecing category\n");
	printf("press M for moving object\n");
	printf("press D for changing direction of object\n");
	printf("control key : ←, ↑, →, ↓, shift, ctrl \n");
}

int	main(int ac, char **av)
{
	t_meta	meta;

	if (ac != 2)
		ft_exit("miniRT need only one argument");
	parse_line(av[1], &meta);
	ray_tracing(&meta);
	print_manual();
	open_screen(&(meta.mlx), &meta);
	return (0);
}
