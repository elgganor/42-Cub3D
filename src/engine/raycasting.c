/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:36:08 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/19 10:30:56 by mrouabeh         ###   ########.fr       */
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
		ray.camera_x = (2 * x) / (double)window->width - 1;
		ray.ray_x = player->dir_x + player->plan_x * ray.camera_x;
		ray.ray_y = player->dir_y + player->plan_y * ray.camera_x;

		dda(game->layout, player, &ray);

		line_height = (int)(window->height / ray.perp_wall_dist);

		printf("x: %d\n", x);
		printf("camera_x: %f\n", ray.camera_x);
		printf("perp_wall_dist: %f\n", ray.perp_wall_dist);
		printf("ray_x: %f\n", ray.ray_x);
		printf("ray_y: %f\n", ray.ray_y);
		printf("side_dist_x: %f\n", ray.side_dist_x);
		printf("side_dist_y: %f\n", ray.side_dist_y);
		printf("delta_dist_x: %f\n", ray.delta_dist_x);
		printf("delta_dist_y: %f\n", ray.delta_dist_y);
		printf("step_x: %d\n", ray.step_x);
		printf("step_y: %d\n", ray.step_y);
		printf("side: %d\n", ray.side);
		printf("hit: %d\n", ray.hit);
		printf("line_height: %d\n\n\n", line_height);

		draw_col(game, window, line_height, x);
		x++;
	}
}

