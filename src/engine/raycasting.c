/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:36:08 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/18 13:54:46 by mrouabeh         ###   ########.fr       */
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
		ray.camera_x = (2 * x) / window->width - 1;
		ray.ray_x = player->dir_x + player->plan_x * ray.camera_x;
		ray.ray_y = player->dir_y + player->plan_y * ray.camera_x;
		dda(game->layout, player, &ray);
		line_height = (int)(window->height / ray.perp_wall_dist);
		printf("\nperp_wall_dist: %f\n", ray.perp_wall_dist);
		printf("line_height: %d\n", line_height);
		draw_col(game, window, line_height, x);
		x++;
	}
}
