/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 10:20:37 by mohamed           #+#    #+#             */
/*   Updated: 2020/03/11 14:19:08 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	sorted_insert(t_sprites **head_ref, t_sprites *new_node)
{
	t_sprites *current;

	if ((*head_ref) == NULL || (*head_ref)->distance <= new_node->distance)
	{
		new_node->next = (*head_ref);
		(*head_ref) = new_node;
	}
	else
	{
		current = (*head_ref);
		while (current->next != NULL
			&& current->next->distance >= new_node->distance)
		{
			current = current->next;
		}
		new_node->next = current->next;
		current->next = new_node;
	}
}

void		is_sprite(t_game *game, t_ray *ray)
{
	t_sprite	*new;
	t_sprites	*new_sprite;
	t_sprites	*current;
	double		distance;

	if (!(new = (t_sprite *)malloc(sizeof(t_sprite))))
		return ;
	new->x = ray->map_x;
	new->y = ray->map_y;
	current = game->sprites_head;
	while (current != NULL)
	{
		if (current->sprite->x == new->x
			&& current->sprite->y == new->y)
		{
			free(new);
			return ;
		}
		current = current->next;
	}
	distance = (game->player->pos_x - new->x) * (game->player->pos_x - new->x)
		+ (game->player->pos_y - new->y) * (game->player->pos_y - new->y);
	new_sprite = sprites_struct_init(new, distance);
	sorted_insert(&(game->sprites_head), new_sprite);
}

void		projection_sprite(
	t_player *player,
	t_window *window,
	t_sprites *current)
{
	current->sprite_x = current->sprite->x - (player->pos_x - 0.5);
	current->sprite_y = current->sprite->y - (player->pos_y - 0.5);
	current->inv_det = 1.0 / (player->plan_x * player->dir_y - player->plan_y
	* player->dir_x);
	current->transform_x = current->inv_det
	* (player->dir_y * current->sprite_x - player->dir_x * current->sprite_y);
	current->transform_y = current->inv_det
	* (player->plan_x * current->sprite_y - player->plan_y * current->sprite_x);
	current->sprite_screen_x = (int)((window->width / 2)
	* (1 + current->transform_x / current->transform_y));
}

void		size_sprite(t_sprites *current, t_window *window)
{
	current->sprite_height = abs((int)(window->height / current->transform_y));
	current->draw_start_y = -current->sprite_height / 2 + window->height / 2;
	if (current->draw_start_y < 0)
		current->draw_start_y = 0;
	current->draw_end_y = current->sprite_height / 2 + window->height / 2;
	if (current->draw_end_y >= window->height)
		current->draw_end_y = window->height - 1;
	current->sprite_width = abs((int)(window->height / current->transform_y));
	current->draw_start_x = -current->sprite_width / 2
	+ current->sprite_screen_x;
	if (current->draw_start_x < 0)
		current->draw_start_x = 0;
	current->draw_end_x = current->sprite_width / 2 + current->sprite_screen_x;
	if (current->draw_end_x >= window->width)
		current->draw_end_x = window->width - 1;
}
