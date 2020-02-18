/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digital_differential_analyser.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 14:03:29 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/18 14:01:22 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_delta_dist(t_ray *ray)
{
	if (ray->ray_x == 0)
		ray->delta_dist_y = 0;
	else if (ray->ray_y == 0)
		ray->delta_dist_y = 1;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_x);
	if (ray->ray_y == 0)
		ray->delta_dist_x = 0;
	else if (ray->ray_x == 0)
		ray->delta_dist_x = 1;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_y);
	
}

static void get_step(t_player *player, t_ray *ray)
{
	if (ray->ray_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->pos_x - player->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (player->map_x + 1.0 - player->pos_x) * ray->delta_dist_x;
	}
	if (ray->ray_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos_y - player->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (player->map_y + 1.0 - player->pos_y) * ray->delta_dist_y;
	}
}

static void get_side(t_player *player, t_ray *ray)
{
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->delta_dist_x;
		player->map_x += ray->step_x;
		ray->side = 0;
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		player->map_y += ray->step_y;
		ray->side = 1;
	}
}

void		dda(t_layout *layout, t_player *player, t_ray *ray)
{
	player->map_x = (int)player->pos_x;
	player->map_y = (int)player->pos_y;
	ray->hit = 0;
	get_delta_dist(ray);
	get_step(player, ray);
	while (ray->hit == 0)
	{
		get_side(player, ray);
		if (layout->map[player->map_y][player->map_x] == 1)
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perp_wall_dist = (player->map_x - player->pos_x + (1 - ray->step_x) / 2) / ray->ray_x;
	else
		ray->perp_wall_dist = (player->map_y - player->pos_y + (1 - ray->step_y) / 2) / ray->ray_y;
}