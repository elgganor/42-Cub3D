/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 08:03:39 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/27 12:39:51 by mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	pixel_put(t_image *image, int x, int y, int color)
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

static void	set_color_on_image(t_game *game, int start, int end, int color)
{
	int	y;

	y = start;
	while (y < end)
		pixel_put(game->image, game->ray.x, y++, color);
}

// static void	texture_put()
// {

// }

// static void	set_texture_on_image(t_game *game, int start, int end, t_image *texture)
// {
// 	int	y;

// 	y = start;
// 	while (y <= end)
// 		texture_put();
// }

void		draw_col(t_game *game, t_window *window, t_ray ray)
{
	int	draw_start;
	int	draw_end;
	// int	y;

	draw_start = -ray.line_height / 2 + window->height / 2;
	draw_end = ray.line_height / 2 + window->height / 2;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= window->height)
		draw_end = window->height - 1;
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
	set_color_on_image(game, 0, draw_start, game->c_color);
	// set_texture_on_image();
	set_color_on_image(game, draw_end + 1, window->height, game->f_color);
}
