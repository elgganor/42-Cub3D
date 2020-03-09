/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 07:49:51 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/03/09 08:10:20 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		pixel_put(t_image *image, int x, int y, int color)
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

void		set_color_on_image(t_game *game, t_ray *ray)
{
	int	y;

	y = 0;
	while (y < ray->draw_start)
		pixel_put(game->image, ray->x, y++, game->c_color);
	y = ray->draw_end + 1;
	while (y < game->window->height)
		pixel_put(game->image, ray->x, y++, game->f_color);
}

static void	texture_put(t_game *game, t_image *texture, t_ray *ray)
{
	int	d;

	d = ray->y * texture->size_line - game->window->height
		* texture->size_line / 2 + ray->line_height * texture->size_line / 2;
	ray->text_y = ((d * texture->height) / ray->line_height)
		/ texture->size_line;
	game->image->img_data[ray->y * game->image->size_line
		+ ray->x * game->image->bpp / 8] =
		texture->img_data[ray->text_y * texture->size_line
		+ ray->text_x * (texture->bpp / 8)];
	game->image->img_data[ray->y * game->image->size_line
		+ ray->x * game->image->bpp / 8 + 1] =
		texture->img_data[ray->text_y * texture->size_line
		+ ray->text_x * (texture->bpp / 8) + 1];
	game->image->img_data[ray->y * game->image->size_line
		+ ray->x * game->image->bpp / 8 + 2] =
		texture->img_data[ray->text_y * texture->size_line
		+ ray->text_x * (texture->bpp / 8) + 2];
	ray->y++;
}

void		set_texture_on_image(t_game *game, t_image *texture, t_ray *ray)
{
	ray->y = ray->draw_start;
	while (ray->y <= ray->draw_end)
		texture_put(game, texture, ray);
}
