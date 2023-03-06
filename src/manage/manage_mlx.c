/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:28:58 by yujelee           #+#    #+#             */
/*   Updated: 2023/03/06 21:33:06 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	put_pixel(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->img.data + (y * mlx->img.length + x * (mlx->img.bpp / 8));
	*(unsigned int *)dst = color;
}

void	open_screen(t_mlx *mlx, t_meta *meta)
{
	mlx_key_hook(mlx->win_ptr, binding_key_events, meta);
	mlx_hook(mlx->win_ptr, 2, 1L << 0, &key_event, meta);
	mlx_hook(mlx->win_ptr, 17, 0, &exit_hook, meta);
	mlx_loop(mlx->mlx_ptr);
}

void	window_init(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "sangminiRT");
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	mlx->img.data = mlx_get_data_addr(mlx->img.img_ptr,
			&mlx->img.bpp, &mlx->img.length, &mlx->img.endian);
}
