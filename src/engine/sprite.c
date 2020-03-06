/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 10:20:37 by mohamed           #+#    #+#             */
/*   Updated: 2020/03/06 13:05:27 by mrouabeh         ###   ########.fr       */
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
			&& current->next->distance > new_node->distance)
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
			return ;
		current = current->next;
	}
	distance = (game->player->pos_x - new->x) * (game->player->pos_x - new->x)
		+ (game->player->pos_y - new->y) * (game->player->pos_y - new->y);
	new_sprite = sprites_struct_init(new, distance);
	sorted_insert(&(game->sprites_head), new_sprite);
}
