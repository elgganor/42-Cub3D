/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_layout.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:21:16 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/10 13:01:01 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	flood_fill(t_layout layout, int pos_x, int pos_y, int target, int nb)
{
	if (pos_y >= (int)layout.size.y || pos_y < 0)
		exit_failure("The map is not close;\n");
	else if (pos_x >= (int)layout.size.x || pos_x < 0)
		exit_failure("The map is not close;\n");
	else if (layout.map[pos_y][pos_x] == 1
	|| layout.map[pos_y][pos_x] == nb
	|| (layout.map[pos_y][pos_x] != target && layout.map[pos_y][pos_x] != 2))
		return ;
	else
	{
		if (layout.map[pos_y][pos_x] != 2)
			layout.map[pos_y][pos_x] = nb;
		flood_fill(layout, pos_x + 1, pos_y, target, nb);
		flood_fill(layout, pos_x - 1, pos_y, target, nb);
		flood_fill(layout, pos_x, pos_y + 1, target, nb);
		flood_fill(layout, pos_x, pos_y - 1, target, nb);
	}
	return ;
}

void	check_layout(t_layout *layout, t_player *player)
{
	if (layout->size.y < 3 || layout->size.x < 3)
		exit_failure("The map has a wrong format;\n");
	if (player->position.y >= (int)layout->size.y || player->position.y < 0)
		exit_failure("The coordinates are wrong;\n");
	if (player->position.x >= (int)layout->size.x || player->position.x < 0)
		exit_failure("The coordinates are wrong;\n");
	flood_fill(*(layout), (int)player->position.x,
				(int)player->position.y, 0, 9);
	flood_fill(*(layout), (int)player->position.x,
				(int)player->position.y, 9, 0);
}
