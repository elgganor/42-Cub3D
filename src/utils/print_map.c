/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 09:04:34 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/03/06 12:53:31 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(int **map, int nb_row, int nb_col)
{
	int x;
	int y;

	y = 0;
	while (y < nb_row)
	{
		x = 0;
		while (x < nb_col)
		{
			ft_putnbr(map[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
	ft_putstr("\n\n");
}
