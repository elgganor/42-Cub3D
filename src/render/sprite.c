/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 13:30:15 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/03/07 13:30:35 by mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_put(t_game *game, t_sprites *sprite)
{

}

void set_sprite_on_image(t_game *game, t_sprites *current, t_window *window, t_ray *ray)
{
	int x;
	int y;

	x = current->draw_start_x;
	while (x < current->draw_end_x)
	{
		if (current->transform_y > 0 && current->transform_y < ray->z_buffer[x])
		{
			y = current->draw_start_y;
			while (y < current->draw_end_y)
			{

				y++;
			}
		}
		x++;
	}
}

void	draw_sprites(t_game *game, t_player *player, t_window *window, t_ray *ray)
{
	t_sprites *current;

	(void)ray;
	current = game->sprites_head;
	while (current != NULL)
	{
		projection_sprite(player, window, current);
		size_sprite(current, window);
		set_sprite_on_image(game, current, window, ray);
		current = current->next;
	}
	// free les sprites
}