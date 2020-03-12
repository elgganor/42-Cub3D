/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:36:08 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/03/12 17:03:54 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		ray->side_dist_x = (ray->map_x - player->pos_x + 1.0)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y - player->pos_y + 1.0)
			* ray->delta_dist_y;
	}
}

static void	get_perp_and_height(t_ray *ray, t_player *player, t_window *window)
{
	if (ray->side == 0 || ray->side == 1)
		ray->perp_wall_dist = (ray->map_x - player->pos_x + (1 - ray->step_x)
		/ 2) / ray->ray_dir_x;
	else if (ray->side == 2 || ray->side == 3)
		ray->perp_wall_dist = (ray->map_y - player->pos_y + (1 - ray->step_y)
		/ 2) / ray->ray_dir_y;
	ray->line_height = (int)(window->height / ray->perp_wall_dist);
	ray->z_buffer[ray->x] = ray->perp_wall_dist;
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
	ray->y = 0;
	get_step_and_side_dist(ray, player);
}

void		raycasting(
	t_game *game,
	t_player *player,
	t_window *window,
	t_ray ray
)
{
	ray.x = 0;
	if (!(ray.z_buffer = (double *)malloc(sizeof(double) * window->width)))
		exit_failure("Impossible to allocate memory for the z_buffer;\n", game);
	ft_bzero(ray.z_buffer, sizeof(double) * window->width);
	while (ray.x < window->width)
	{
		init_ray(&ray, player, window);
		dda(game, game->layout, &ray);
		get_perp_and_height(&ray, player, window);
		draw_col(game, window, &ray);
		ray.x++;
	}
	if (game->sprites_head != NULL)
		draw_sprites(game, player, window, &ray);
	free(ray.z_buffer);
	if (game->save == 1)
	{
		create_bitmap(game);
		exit_game(game);
	}
	else
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
			game->image->img_ptr, 0, 0);
}
