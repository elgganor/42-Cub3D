/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 12:14:05 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/07 12:20:55 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ceil(t_vars *vars)
{
	int x;
	int y;

	x = 0;
	while (x < WIN->width)
	{
		y = 0;
		while (y < WIN->height / 2)
		{
			mlx_pixel_put(WIN->mlx_ptr, WIN->win_ptr, x, y, CUB->c_color);
			y++;
		}
		x++;
	}
}

void	draw_floor(t_vars *vars)
{
	int x;
	int y;

	x = 0;
	while (x < WIN->width)
	{
		y = WIN->height / 2;
		while (y < WIN->height)
		{
			mlx_pixel_put(WIN->mlx_ptr, WIN->win_ptr, x, y, CUB->f_color);
			y++;
		}
		x++;
	}
}