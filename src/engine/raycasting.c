/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:36:08 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/12 14:57:11 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(
	t_layout *layout,
	t_player *player,
	t_window *window,
	t_ray ray
)
{
	int	x;

	x = 0;
	while (x < window->width)
	{
		ray.camera_x = (2 * x) / (float)(window->width) - 1;
		ray.ray_x = player->dir_x + player->plan_x * ray.camera_x;
		ray.ray_y = player->dir_y + player->plan_y * ray.camera_x;
		
		x++;
	}
}
