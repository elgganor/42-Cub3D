/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:14:31 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/03/02 10:53:27 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_position(t_player *player, float pos_x, float pos_y)
{
	player->pos_x += pos_x;
	player->pos_y += pos_y;
}

void	init_player(t_player *player)
{
	if (player->dir == 'N' || player->dir == 'S')
	{
		player->dir_x = 0.;
		player->dir_y = (player->dir == 'N') ? -1. : 1.;
		player->plan_x = (player->dir == 'N') ? 0.66 : -0.66;
		player->plan_y = 0.;
	}
	else if (player->dir == 'W' || player->dir == 'E')
	{
		player->dir_x = (player->dir == 'W') ? -1. : 1.;
		player->dir_y = 0.;
		player->plan_x = 0.;
		player->plan_y = (player->dir == 'W') ? -0.66 : 0.66;
	}
}
