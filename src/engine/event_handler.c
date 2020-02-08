/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 09:15:08 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/08 12:49:34 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int key_code, t_game *game)
{
	if (key_code == KEY_A)
		game->keys->key_a = 1;
	else if (key_code == KEY_S)
		game->keys->key_s = 1;
	else if (key_code == KEY_D)
		game->keys->key_d = 1;
	else if (key_code == KEY_W)
		game->keys->key_w = 1;
	else if (key_code == KEY_ESC)
		game->keys->key_esc = 1;
	else if (key_code == LEFT_ARR)
		game->keys->left_arr = 1;
	else if (key_code == RIGHT_ARR)
		game->keys->right_arr = 1;
	return (0);
}

int	key_release(int key_code, t_game *game)
{
	if (key_code == KEY_A)
		game->keys->key_a = 0;
	else if (key_code == KEY_S)
		game->keys->key_s = 0;
	else if (key_code == KEY_D)
		game->keys->key_d = 0;
	else if (key_code == KEY_W)
		game->keys->key_w = 0;
	else if (key_code == KEY_ESC)
		game->keys->key_esc = 0;
	else if (key_code == LEFT_ARR)
		game->keys->left_arr = 0;
	else if (key_code == RIGHT_ARR)
		game->keys->right_arr = 0;
	return (0);
}