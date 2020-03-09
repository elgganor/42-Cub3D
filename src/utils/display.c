/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 09:04:34 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/03/09 09:09:13 by mrouabeh         ###   ########.fr       */
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

void	print_sprite(t_sprites *sprite)
{
	printf("sprite.x: %d\n", sprite->sprite->x);
	printf("sprite.y: %d\n", sprite->sprite->y);
	printf("distance: %f\n", sprite->distance);
	printf("sprite_x: %f\n", sprite->sprite_x);
	printf("sprite_y: %f\n", sprite->sprite_y);
	printf("inv_det: %f\n", sprite->inv_det);
	printf("transform_x: %f\n", sprite->transform_x);
	printf("transform_y: %f\n", sprite->transform_y);
	printf("sprite_screen_x: %d\n", sprite->sprite_screen_x);
	printf("sprite_width: %d\n", sprite->sprite_width);
	printf("sprite_height: %d\n", sprite->sprite_height);
	printf("draw_start_x: %d\n", sprite->draw_start_x);
	printf("draw_start_y: %d\n", sprite->draw_start_y);
	printf("draw_end_x: %d\n", sprite->draw_end_x);
	printf("draw_end_y: %d\n", sprite->draw_end_y);
	printf("text_x: %d\n", sprite->text_x);
	printf("text_y: %d\n", sprite->text_y);
	printf("x: %d\n", sprite->x);
	printf("y: %d\n\n\n", sprite->y);
}
