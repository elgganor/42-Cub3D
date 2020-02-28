/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 07:49:49 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/28 08:17:48 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	texture_side(t_game *game, t_image *image, t_ray ray)
{
	int	text_x;

	text_x = 0;
	text_x = (int)(image->wall_x * (double)image->width);
	if ((ray.side == 0 || ray.side == 1) && ray.ray_dir_x > 0)
		text_x = image->width - text_x - 1;
	if ((ray.side == 2 || ray.side == 3) && ray.ray_dir_y < 0)
		text_x = image->width - text_x - 1;
	image->text_x = text_x;
	if (ray.side == 0)
		set_texture_on_image(game, game->no_texture);
	else if (ray.side == 1)
		set_texture_on_image(game, game->so_texture);
	else if (ray.side == 2)
		set_texture_on_image(game, game->ea_texture);
	else if (ray.side == 3)
		set_texture_on_image(game, game->we_texture);
}

void		draw_col(t_game *game, t_window *window, t_ray ray)
{
	// int	y;

	game->image->draw_start = -ray.line_height / 2 + window->height / 2;
	game->image->draw_end = ray.line_height / 2 + window->height / 2;
	if (game->image->draw_start < 0)
		game->image->draw_start = 0;
	if (game->image->draw_end >= window->height)
		game->image->draw_end = window->height - 1;
	if (ray.side == 0 || ray.side == 1)
		game->image->wall_x = game->player->pos_y + ray.perp_wall_dist * ray.ray_dir_y;
	else
		game->image->wall_x = game->player->pos_x + ray.perp_wall_dist * ray.ray_dir_x;
	game->image->wall_x -= floor(game->image->wall_x);
	if (game->layout->map[ray.map_y][ray.map_x] == '1')
		texture_side(game, game->image, ray);
	// y = 0;
	// while (y < draw_start)
	// 	mlx_pixel_put(window->mlx_ptr, window->win_ptr, ray.x, y++, game->c_color);
	// while (draw_start <= y && y <= draw_end)
	// {
	// 	if (ray.side == 0)
	// 		mlx_pixel_put(window->mlx_ptr, window->win_ptr, ray.x, y++, 0xffffff);
	// 	else if (ray.side == 1)
	// 		mlx_pixel_put(window->mlx_ptr, window->win_ptr, ray.x, y++, 0xff0000);
	// 	else if (ray.side == 2)
	// 		mlx_pixel_put(window->mlx_ptr, window->win_ptr, ray.x, y++, 0x00ff00);
	// 	else if (ray.side == 3)
	// 		mlx_pixel_put(window->mlx_ptr, window->win_ptr, ray.x, y++, 0x0000ff);
	// }
	// while (y < window->height)
	// 	mlx_pixel_put(window->mlx_ptr, window->win_ptr, ray.x, y++, game->c_color);
	set_color_on_image(game, 0, game->image->draw_start, game->c_color);
	set_color_on_image(game, game->image->draw_end + 1, window->height, game->f_color);
}