/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digital_differential_analyser.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 14:03:29 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/25 12:09:06 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void get_wall_dist(t_ray *ray)
{
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->delta_dist_x;
		ray->map_x += ray->step_x;
		if (ray->ray_dir_x < 0)
			ray->side = 0;
		else
			ray->side = 1;
		
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		ray->map_y += ray->step_y;
		if (ray->ray_dir_y < 0)
			ray->side = 2;
		else
			ray->side = 3;
	}
}

void	dda(t_layout *layout, t_ray *ray)
{
	while (ray->hit == 0)
	{
		get_wall_dist(ray);
		if (layout->map[ray->map_y][ray->map_x] >= 1
			&& layout->map[ray->map_y][ray->map_x] != 2)
			ray->hit = 1;
		else if (layout->map[ray->map_y][ray->map_y] == 2)
			ray->hit = 2;
	}
}