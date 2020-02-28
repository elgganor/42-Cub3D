/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 07:49:49 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/28 13:09:32 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_wall(t_game *game, t_image *image, t_ray *ray)
{
	int	text_x;

	text_x = (int)(ray->wall_x * (double)image->width);
	if ((ray->side == 0 || ray->side == 1) && ray->ray_dir_x > 0)
		text_x = image->width - text_x - 1;
	if ((ray->side == 2 || ray->side == 3) && ray->ray_dir_y < 0)
		text_x = image->width - text_x - 1;
	ray->text_x = text_x;
	if (ray->side == 0)
		set_texture_on_image(game, game->no_texture, ray);
	else if (ray->side == 1)
		set_texture_on_image(game, game->so_texture, ray);
	else if (ray->side == 2)
		set_texture_on_image(game, game->ea_texture, ray);
	else if (ray->side == 3)
		set_texture_on_image(game, game->we_texture, ray);
}

void		draw_col(t_game *game, t_window *window, t_ray *ray)
{
	ray->draw_start = -ray->line_height / 2 + window->height / 2;
	ray->draw_end = ray->line_height / 2 + window->height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_end >= window->height)
		ray->draw_end = window->height - 1;
	if (ray->side == 0 || ray->side == 1)
		ray->wall_x = game->player->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	else
		ray->wall_x = game->player->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	ray->wall_x -= floor(ray->wall_x);
	set_wall(game, game->image, ray);
	set_color_on_image(game, ray);
}