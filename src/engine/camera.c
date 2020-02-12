/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:27:50 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/12 13:27:58 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_player *player)
{
	float	oldDirX;
	float	oldPlanX;

	oldDirX = player->dir_x;
	player->dir_x = cos(-(player->rot_speed)) * player->dir_x -
					sin(-(player->rot_speed)) * player->dir_y;
	player->dir_y = sin(-(player->rot_speed)) * oldDirX +
					cos(-(player->rot_speed)) * player->dir_y;
	oldPlanX = player->plan_x;
	player->plan_x = cos(-(player->rot_speed)) * player->plan_x -
					 sin(-(player->rot_speed)) * player->plan_y;
	player->plan_y = sin(-(player->rot_speed)) * oldPlanX +
					 cos(-(player->rot_speed)) * player->plan_y;
}

void	rotate_right(t_player *player)
{
	float oldDirX;
	float oldPlanX;

	oldDirX = player->dir_x;
	player->dir_x = cos(player->rot_speed) * player->dir_x -
					sin(player->rot_speed) * player->dir_y;
	player->dir_y = sin(player->rot_speed) * oldDirX +
					cos(player->rot_speed) * player->dir_y;
	oldPlanX = player->plan_x;
	player->plan_x = cos(player->rot_speed) * player->plan_x -
					 sin(player->rot_speed) * player->plan_y;
	player->plan_y = sin(player->rot_speed) * oldPlanX +
					 cos(player->rot_speed) * player->plan_y;
}
