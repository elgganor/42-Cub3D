/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 07:49:51 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/28 08:18:29 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void pixel_put(t_image *image, int x, int y, int color)
{
	unsigned char *src;
	unsigned char r;
	unsigned char g;
	unsigned char b;

	src = (unsigned char *)&color;
	r = src[0];
	g = src[1];
	b = src[2];
	image->img_data[y * image->size_line + x * image->bpp / 8] = r;
	image->img_data[y * image->size_line + x * image->bpp / 8 + 1] = g;
	image->img_data[y * image->size_line + x * image->bpp / 8 + 2] = b;
}

void set_color_on_image(t_game *game, int start, int end, int color)
{
	int y;

	y = start;
	while (y < end)
		pixel_put(game->image, game->ray.x, y++, color);
}

void texture_put(t_game *game, t_image *texture, int x, int y)
{
	int d;

	d = y * texture->size_line - game->window->height * texture->size_line / 2 + game->ray.line_height * texture->size_line / 2;
	game->image->text_y = ((d * texture->height) / game->ray.line_height) / texture->size_line;
	game->image->img_data[y * game->image->size_line + x * game->image->bpp / 8] = texture->img_data[game->image->text_y * texture->size_line + game->image->text_x * (texture->bpp / 8)];
	game->image->img_data[y * game->image->size_line + x * game->image->bpp / 8 + 1] = texture->img_data[game->image->text_y * texture->size_line + game->image->text_x * (texture->bpp / 8) + 1];
	game->image->img_data[y * game->image->size_line + x * game->image->bpp / 8 + 2] = texture->img_data[game->image->text_y * texture->size_line + game->image->text_x * (texture->bpp / 8) + 2];
}

void set_texture_on_image(t_game *game, t_image *texture)
{
	int y;

	y = game->image->draw_start;
	while (y <= game->image->draw_end)
		texture_put(game, texture, game->ray.x, y++);
}