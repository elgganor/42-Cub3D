/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 10:42:35 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/10 13:00:09 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_keys		*keys_struct_init(void)
{
	t_keys *keys;

	if (!(keys = (t_keys *)malloc(sizeof(t_keys))))
		return (NULL);
	keys->key_a = 0;
	keys->key_s = 0;
	keys->key_d = 0;
	keys->key_w = 0;
	keys->key_esc = 0;
	keys->left_arr = 0;
	keys->right_arr = 0;
	return (keys);
}

t_player	*player_struct_init(void)
{
	t_player *player;

	if (!(player = (t_player *)malloc(sizeof(t_player))))
		return (NULL);
	player->position.x = 0;
	player->position.y = 0;
	player->direction.x = 0;
	player->direction.y = 0;
	player->dir = '0';
	return (player);
}

t_layout	*layout_struct_init(void)
{
	t_layout *layout;

	if (!(layout = (t_layout *)malloc(sizeof(t_layout))))
		return (NULL);
	layout->map = NULL;
	layout->tmp_map = NULL;
	layout->size.x = 0;
	layout->size.y = 0;
	return (layout);
}

t_window	*window_struct_init(void)
{
	t_window *window;

	if (!(window = (t_window *)malloc(sizeof(t_window))))
		return (NULL);
	window->resolution.x = 0;
	window->resolution.y = 0;
	window->mlx_ptr = NULL;
	window->win_ptr = NULL;
	return (window);
}

t_game		*game_struct_init(void)
{
	t_game *game;

	if (!(game = (t_game *)malloc(sizeof(t_game))))
		return (NULL);
	game->map_started = 0;
	game->no_texture = NULL;
	game->so_texture = NULL;
	game->we_texture = NULL;
	game->ea_texture = NULL;
	game->sp_texture = NULL;
	game->c_color = 0;
	game->f_color = 0;
	game->player = player_struct_init();
	game->layout = layout_struct_init();
	game->window = window_struct_init();
	game->keys = keys_struct_init();
	return (game);
}
