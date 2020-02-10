/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_layout.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:21:16 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/10 09:07:50 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	flood_fill(t_layout layout, int pos_x, int pos_y, int target, int nb)
{
	if (pos_y >= (int)layout.nb_row || pos_y < 0)
		exit_failure("The map is not close;\n");
	else if (pos_x >= (int)layout.nb_col || pos_x < 0)
		exit_failure("The map is not close;\n");
	else if (layout.map[pos_y][pos_x] == 1
	|| layout.map[pos_y][pos_x] == nb
	|| (layout.map[pos_y][pos_x] != target && layout.map[pos_y][pos_x] != 2))
		return ;
	else
	{
		if (layout.map[pos_y][pos_x] != 2)
		{
			layout.map[pos_y][pos_x] = nb;
		}
		flood_fill(layout, pos_x + 1, pos_y, target, nb);
		flood_fill(layout, pos_x, pos_y + 1, target, nb);
		flood_fill(layout, pos_x - 1, pos_y, target, nb);
		flood_fill(layout, pos_x, pos_y - 1, target, nb);
	}
	return ;
}

void	check_layout(t_layout *layout, t_player *player)
{
	if (layout->nb_row < 3 || layout->nb_col < 3)
		exit_failure("The map has a wrong format;\n");
	if (player->pos_y >= (int)layout->nb_row || player->pos_y < 0)
		exit_failure("The coordinates are wrong;\n");
	if (player->pos_x >= (int)layout->nb_col || player->pos_x < 0)
		exit_failure("The coordinates are wrong;\n");
	flood_fill(*(layout), (int)player->pos_x, (int)player->pos_y, 0, 9);
	flood_fill(*(layout), (int)player->pos_x, (int)player->pos_y, 9, 0);
}