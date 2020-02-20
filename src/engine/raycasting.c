/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:36:08 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/20 12:45:51 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void	print_ray(t_ray ray, t_player *player)
// {
// 	printf("x: %d\n", ray.x);
// 	printf("pos_x: %f\n", player->pos_x);
// 	printf("pos_y: %f\n", player->pos_y);
// 	printf("map_x: %d\n", ray.map_x);
// 	printf("map_y: %d\n", ray.map_y);
// 	printf("camera_x: %f\n", ray.camera_x);
// 	printf("ray_dir_x: %f\n", ray.ray_dir_x);
// 	printf("ray_dir_y: %f\n", ray.ray_dir_y);
// 	printf("side_dist_x: %f\n", ray.side_dist_x);
// 	printf("side_dist_y: %f\n", ray.side_dist_y);
// 	printf("delta_dist_x: %f\n", ray.delta_dist_x);
// 	printf("delta_dist_y: %f\n", ray.delta_dist_y);
// 	printf("step_x: %d\n", ray.step_x);
// 	printf("step_y: %d\n", ray.step_y);
// 	printf("hit: %d\n", ray.hit);
// 	printf("side: %d\n", ray.side);
// 	printf("perp_wall_dist: %f\n", ray.perp_wall_dist);
// 	printf("line_height: %d\n\n\n", ray.line_height);
// }

static void	get_delta_dist(t_ray *ray)
{
	if (ray->ray_dir_y == 0)
		ray->delta_dist_x = 0;
	else if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_x == 0)
		ray->delta_dist_y = 0;
	else if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	
}

static void	get_step_and_side_dist(t_ray *ray, t_player *player)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x - player->pos_x + 1.0) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y - player->pos_y + 1.0) * ray->delta_dist_y;
	}
}

static void	init_ray(t_ray *ray, t_player *player, t_window *window)
{
	ray->camera_x = 2 * ray->x / (double)window->width - 1;
	ray->ray_dir_x = player->dir_x + player->plan_x * ray->camera_x;
	ray->ray_dir_y = player->dir_y + player->plan_y * ray->camera_x;
	get_delta_dist(ray);
	ray->hit = 0;
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
	ray->line_height = 0;
}

void	raycasting(t_game *game, t_player *player, t_window *window, t_ray ray)
{
	ray.x = 0;
	while (ray.x < window->width)
	{
		init_ray(&ray, player, window);
		get_step_and_side_dist(&ray, player);
		dda(game->layout, &ray);
		if (ray.side == 0)
			ray.perp_wall_dist = (ray.map_x - player->pos_x + (1 - ray.step_x) / 2) / ray.ray_dir_x;
		else
			ray.perp_wall_dist = (ray.map_y - player->pos_y + (1 - ray.step_y) / 2) / ray.ray_dir_y;
		ray.line_height = (int)(window->height / ray.perp_wall_dist);
		draw_col(game, window, ray);
		ray.x++;
	}
}
