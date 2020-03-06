/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 10:20:37 by mohamed           #+#    #+#             */
/*   Updated: 2020/03/04 10:51:01 by mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	is_sprite(t_game *game, t_ray *ray, t_layout *layout)
{
	t_sprite	sprite;
	t_sprites	*sprites;
	double		distance;
	double		pos_x;
	double		pos_y;

	if (game->sprites != NULL)
	{
		sprite.x = ray->map_x;
		sprite.y = ray->map_y;
		sprites = game->sprites;
		while (sprites != NULL)
		{
			if (sprites->sprite->x == sprite.x && sprites->sprite->y == sprite.y)
				return ;
			sprites = sprites->next;
		}
		pos_x = game->player->pos_x;
		pos_y = game->player->pos_y;
		distance = (pos_x - sprite.x) * (pos_x - sprite.x)
			+ (pos_y - sprite.y) * (pos_y - sprite.y);
		sprites = sprites_struct_init(&sprite, distance);
		sprites->next = game->sprites;
		game->sprites = sprites;
	}
}
