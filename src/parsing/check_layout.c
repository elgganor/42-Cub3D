/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_layout.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:21:16 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/09 18:19:17 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void print_map(int **map, int nb_row, int nb_col)
{
	int x;
	int y;

	y = 0;
	while (y < nb_col)
	{
		x = 0;
		while (x < nb_row)
		{
			ft_putnbr(map[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

void	flood_fill(int **map, int pos_x, int pos_y, int nb_row, int nb_col)
{
	if (map[pos_y][pos_x] == 1
		|| map[pos_y][pos_x] == 2
		|| map[pos_y][pos_x] == 9
		|| map[pos_y][pos_x] != 0)
		return ;
	else if (pos_y >= nb_row || pos_y < 0)
		exit_failure("The map is not close;\n");
	else if (pos_x >= nb_col || pos_x < 0)
		exit_failure("The map is not close;\n");
	else
	{
		map[pos_y][pos_x] = 9;
		print_map(map, nb_row, nb_col);
		ft_putstr("\n\n\n\n\n");
		flood_fill(map, pos_x + 1, pos_y, nb_row, nb_col);
		flood_fill(map, pos_x, pos_y + 1, nb_row, nb_col);
		flood_fill(map, pos_x - 1, pos_y, nb_row, nb_col);
		flood_fill(map, pos_x, pos_y - 1, nb_row, nb_col);
	}
	return ;
}