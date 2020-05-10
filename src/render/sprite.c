/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 13:30:15 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/05/10 14:02:49 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	texture_put(t_game *game, t_sprites *sprite)
{
	int	index;
	int index_sprite;

	index = sprite->y * game->image->size_line
	+ sprite->x * game->image->bpp / 8;
	index_sprite = sprite->text_y * game->sp_texture->size_line + sprite->text_x
	* game->sp_texture->bpp / 8;
	game->image->img_data[index] = game->sp_texture->img_data[index_sprite];
	game->image->img_data[index + 1] =
	game->sp_texture->img_data[index_sprite + 1];
	game->image->img_data[index + 2] =
	game->sp_texture->img_data[index_sprite + 2];
}

void		sprite_put(t_game *game, t_window *window, t_sprites *sprite)
{
	int	d;
	int	color;
	int	index;

	d = sprite->y * game->sp_texture->size_line - window->height
	* game->sp_texture->size_line / 2 + sprite->sprite_height
	* game->sp_texture->size_line / 2;
	sprite->text_y = (int)(d * game->sp_texture->height / sprite->sprite_height
	/ game->sp_texture->size_line);
	index = sprite->text_y * game->sp_texture->size_line
	+ sprite->text_x * game->sp_texture->bpp / 8;
	color = game->sp_texture->img_data[index]
	+ game->sp_texture->img_data[index + 1]
	+ game->sp_texture->img_data[index + 2];
	if (color != 0)
		texture_put(game, sprite);
}

void		set_sprite_on_image(t_game *game, t_sprites *current,
			t_window *window, t_ray *ray)
{
	current->x = current->draw_start_x;
	while (current->x < current->draw_end_x)
	{
		if (current->transform_y > 0
			&& current->transform_y < ray->z_buffer[current->x])
		{
			current->y = current->draw_start_y;
			current->text_x = (int)(game->sp_texture->size_line
			* (current->x - (-current->sprite_width / 2
			+ current->sprite_screen_x)) * game->sp_texture->width
			/ current->sprite_width) / game->sp_texture->size_line;
			while (current->y < current->draw_end_y)
			{
				sprite_put(game, window, current);
				current->y++;
			}
		}
		current->x++;
	}
}

void		draw_sprites(t_game *game, t_player *player, t_window *window,
					t_ray *ray)
{
	t_sprites	*current;

	current = game->sprites_head;
	while (current != NULL)
	{
		projection_sprite(player, window, current);
		size_sprite(current, window);
		set_sprite_on_image(game, current, window, ray);
		current = current->next;
	}
	free_sprites(&game->sprites_head);
}
