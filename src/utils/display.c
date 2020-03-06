/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 09:04:34 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/03/06 14:02:56 by mrouabeh         ###   ########.fr       */
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

void	print_sprites(t_sprites *head_ref)
{
	t_sprites *current;

	current = head_ref;
	while (current != NULL)
	{
		printf("%f\n", current->distance);
		current = current->next;
	}
	printf("\n\n");
}
