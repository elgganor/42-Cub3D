/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 08:52:12 by mohamed           #+#    #+#             */
/*   Updated: 2020/03/09 10:05:50 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_image		*image_struct_init(void)
{
	t_image	*image;

	if (!(image = (t_image *)malloc(sizeof(t_image))))
		return (NULL);
	image->img_data = NULL;
	image->img_ptr = NULL;
	image->path = NULL;
	image->bpp = 0;
	image->endian = 0;
	image->size_line = 0;
	image->width = 0;
	image->height = 0;
	return (image);
}

t_sprites	*sprites_struct_init(t_sprite *sprite, double distance)
{
	t_sprites	*sprites;

	if (!(sprites = (t_sprites *)malloc(sizeof(t_sprites))))
		return (NULL);
	sprites->sprite = sprite;
	sprites->distance = distance;
	sprites->next = NULL;
	sprites->draw_start_x = 0;
	sprites->draw_end_x = 0;
	sprites->draw_start_y = 0;
	sprites->draw_end_y = 0;
	sprites->sprite_x = 0;
	sprites->sprite_y = 0;
	sprites->inv_det = 0;
	sprites->transform_x = 0;
	sprites->transform_y = 0;
	sprites->sprite_screen_x = 0;
	sprites->sprite_height = 0;
	sprites->sprite_width = 0;
	sprites->x = 0;
	sprites->y = 0;
	sprites->text_x = 0;
	sprites->text_y = 0;
	return (sprites);
}
