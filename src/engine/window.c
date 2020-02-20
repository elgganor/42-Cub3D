/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 08:03:39 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/20 12:44:35 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_col(t_game *game, t_window *window, t_ray ray)
{
	int	draw_start;
	int	draw_end;
	int	y;

	draw_start = -ray.line_height / 2 + window->height / 2;
	draw_end = ray.line_height / 2 + window->height / 2;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= window->height)
		draw_end = window->height - 1;
	y = 0;
	while (y < window->height)
	{
		if (y < draw_start)
			mlx_pixel_put(window->mlx_ptr, window->win_ptr, ray.x, y, game->c_color);
		else if (draw_start <= y && y <= draw_end)
		{
			if (ray.side == 0)
				mlx_pixel_put(window->mlx_ptr, window->win_ptr, ray.x, y, 0xffffff);
			else
				mlx_pixel_put(window->mlx_ptr, window->win_ptr, ray.x, y, 0xbbbbbb);
		}
		else
			mlx_pixel_put(window->mlx_ptr, window->win_ptr, ray.x, y, game->f_color);
		y++;
	}
}
