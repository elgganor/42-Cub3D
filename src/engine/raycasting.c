/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:36:08 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/13 12:56:41 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(
	t_game *game,
	t_player *player,
	t_window *window,
	t_ray ray
)
{
	int	x;
	int	line_height;

	x = 0;
	while (x < window->width)
	{
		ray.camera_x = (2 * x) / (float)(window->width) - 1;
		ray.ray_x = player->dir_x + player->plan_x * ray.camera_x;
		ray.ray_y = player->dir_y + player->plan_y * ray.camera_x;
		dda(game->layout, player, &ray);
		if (ray.side == 0)
			ray.perp_wall_dist = ((int)player->pos_x - player->pos_x + (1 - ray.step_x) / 2) / ray.ray_x;
		else
			ray.perp_wall_dist = ((int)player->pos_y - player->pos_y + (1 - ray.step_y) / 2) / ray.ray_y;
		line_height = (int)(window->height / ray.perp_wall_dist);
		draw_col(game, window, line_height, x);
		x++;
	}
}
