/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 08:31:09 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/03/11 11:20:49 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static void image_header(t_image *image, int fd)
{
	int	header_size;
	int	plane;

	header_size = 40;
	plane = 1;
	write(fd, &header_size, 4);
	write(fd, &image->width, 4);
	write(fd, &image->height, 4);
	write(fd, &plane, 2);
	write(fd, &image->bpp, 2);
	write(fd, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 24);
}

static void	put_img_to_bitmap(t_image *image, int fd)
{
	int	i;
	int	len;

	len = image->width + image->height - 1;
	i = 0;
	while (i < len)
	{
		write(fd, &image->img_data[i * image->bpp / 8], 4);
	}
}

void	create_bitmap(t_image *image)
{
	int	fd;

	fd = open("Cub3d.bmp", O_CREAT | O_RDWR);
	file_header(image, fd);
	image_header(image, fd);
	put_img_to_bitmap(image, fd);
	close(fd);
}