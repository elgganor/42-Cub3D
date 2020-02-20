/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:27:59 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/20 14:07:20 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_layout *layout, t_player *player)
{
	if (layout->map[(int)(player->pos_y)]
			[(int)(player->pos_x + player->dir_x * player->mov_speed)] == 0)
		set_position(player, player->dir_x * player->mov_speed, 0);
	if (layout->map[(int)(player->pos_y + player->dir_y * player->mov_speed)]
		[(int)(player->pos_x)] == 0)
		set_position(player, 0, player->dir_y * player->mov_speed);
}

void	move_backward(t_layout *layout, t_player *player)
{
	if (layout->map[(int)(player->pos_y)]
			[(int)(player->pos_x + player->dir_x * player->mov_speed)] == 0)
		set_position(player, -(player->dir_x * player->mov_speed), 0);
	if (layout->map[(int)(player->pos_y + player->dir_y * player->mov_speed)]
			[(int)(player->pos_x)] == 0)
		set_position(player, 0, -(player->dir_y * player->mov_speed));
}

void	move_left(t_layout *layout, t_player *player)
{
	if (layout->map[(int)(player->pos_y)]
			[(int)(player->pos_x + player->dir_x * player->mov_speed)] == 0)
		set_position(player, -(player->dir_y * player->mov_speed), 0);
	if (layout->map[(int)(player->pos_y + player->dir_y * player->mov_speed)]
			[(int)(player->pos_x)] == 0)
		set_position(player, 0, player->dir_x * player->mov_speed);
}

void	move_right(t_layout *layout, t_player *player)
{
	if (layout->map[(int)(player->pos_y)]
			[(int)(player->pos_x + player->dir_x * player->mov_speed)] == 0)
		set_position(player, player->dir_y * player->mov_speed, 0);
	if (layout->map[(int)(player->pos_y + player->dir_y * player->mov_speed)]
			[(int)(player->pos_x)] == 0)
		set_position(player, 0, -(player->dir_x * player->mov_speed));
}
