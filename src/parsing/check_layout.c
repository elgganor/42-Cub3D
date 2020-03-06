/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_layout.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:21:16 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/03/06 13:04:33 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	reset_map(t_layout *layout)
{
	int	x;
	int	y;

	y = 0;
	while (y < layout->nb_row)
	{
		x = 0;
		while (x < layout->nb_col)
		{
			if (layout->map[y][x] == 9)
				layout->map[y][x] = 0;
			if (layout->map[y][x] == 8)
				layout->map[y][x] = 2;
			x++;
		}
		y++;
	}
}

static void	flood_fill(t_layout layout, int pos_x, int pos_y)
{
	if (pos_y >= (int)layout.nb_row || pos_y < 0)
		exit_failure("The map is not close;\n");
	else if (pos_x >= (int)layout.nb_col || pos_x < 0)
		exit_failure("The map is not close;\n");
	else if (layout.map[pos_y][pos_x] == 1 || layout.map[pos_y][pos_x] == 9
		|| layout.map[pos_y][pos_x] == 8
		|| (layout.map[pos_y][pos_x] != 0 && layout.map[pos_y][pos_x] != 2))
		return ;
	if (layout.map[pos_y][pos_x] == 0)
		layout.map[pos_y][pos_x] = 9;
	else if (layout.map[pos_y][pos_x] == 2)
		layout.map[pos_y][pos_x] = 8;
	flood_fill(layout, pos_x + 1, pos_y);
	flood_fill(layout, pos_x - 1, pos_y);
	flood_fill(layout, pos_x, pos_y + 1);
	flood_fill(layout, pos_x, pos_y - 1);
}

void		check_layout(t_layout *layout, t_player *player)
{
	if (layout->nb_row < 3 || layout->nb_col < 3)
		exit_failure("The map is too small;\n");
	if (player->pos_y >= (int)layout->nb_row || player->pos_y < 0)
		exit_failure("The coordinates are wrong;\n");
	if (player->pos_x >= (int)layout->nb_col || player->pos_x < 0)
		exit_failure("The coordinates are wrong;\n");
	flood_fill(*(layout), (int)player->pos_x, (int)player->pos_y);
	reset_map(layout);
}
