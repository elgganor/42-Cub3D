/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 13:30:15 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/03/06 14:39:52 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	projection_sprite(
	t_player *player,
	t_window *window,
	t_sprites *current)
{
	current->sprite_x = current->sprite->x - player->pos_x;
	current->sprite_y = current->sprite->y - player->pos_y;
	current->inv_det = 1.0 / (player->plan_x * player->dir_y
		- player->plan_y * player->dir_x);
	current->transform_x = current->inv_det
	* (player->dir_y * current->sprite_x - player->dir_x * current->sprite_y);
	current->transform_x = current->inv_det
	* (player->plan_x * current->sprite_y - player->plan_y * current->sprite_x);
	current->sprite_screen_x = (int)((window->width / 2)
	* (1 + current->transform_x / current->transform_y));
}

void	draw_sprites(t_game *game, t_player *player, t_window *window, t_ray *ray)
{
	t_sprites *current;

	(void)ray;
	current = game->sprites_head;
	while (current != NULL)
	{
		projection_sprite(player, window, current);
		// TODO: size_sprite()
		current = current->next;
	}

	// free les sprites
}