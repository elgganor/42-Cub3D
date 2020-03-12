/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 08:31:09 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/03/12 10:40:17 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_pixel(t_image *image, int x, int y)
{
	int rgb;
	int color;

	color = image->img_data[y * image->size_line + x *image->bpp];
	rgb = (color & 0xFF0000) | (color & 0x00FF00) | (color & 0x0000ff);
	return (rgb);
}

static void	file_header(t_image *image, int fd)
{
	int	file_size;
	int	pixel_data_offset;

	pixel_data_offset = 54;
	file_size = pixel_data_offset + image->width * image->height * 4;
	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &pixel_data_offset, 4);
}

static void	image_header(t_game *game, t_image *image, int fd)
{
	int	header_size;
	int	plane;
	int	image_size;

	header_size = 40;
	plane = 1;
	image_size = game->window->width * game->window->height;
	write(fd, &header_size, 4);
	write(fd, &image->width, 4);
	write(fd, &image->height, 4);
	write(fd, &plane, 2);
	write(fd, &image->bpp, 2);
	write(fd, "\0\0\0\0", 4);
	write(fd, &image_size, 4);
	write(fd, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 16);
}

static void	fill_bitmap(t_image *image, int fd)
{
	int	x;
	int y;
	int	rgb;

	y = 0;
	while (y < image->height)
	{
		x = 0;
		while (x < image->width)
		{
			rgb = get_pixel(image, x, y);
			write(fd, &rgb, 3);
			x++;
		}
		y++;
	}
}

void	create_bitmap(t_game *game)
{
	int	fd;

	if ((fd = open("Cub3d.bmp", O_CREAT | O_RDWR)) < 0)
	{
		clear_game(game);
		exit_failure("Impossible to create the bitmap file;\n");
	}
	file_header(game->image, fd);
	image_header(game, game->image, fd);
	fill_bitmap(game->image, fd);
	close(fd);
}