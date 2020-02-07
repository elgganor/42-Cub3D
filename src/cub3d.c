/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 09:24:29 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/07 14:11:46 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void draw_rect(t_vars *vars, int x_start, int y_start, int width, int height, int color)
{
	int y;
	int x;

	x = x_start;
	while (x < x_start + width)
	{
		y = y_start;
		while (y < y_start + height)
		{
			mlx_pixel_put(WIN->mlx_ptr, WIN->win_ptr, x, y, color);
			y++;
		}
		x++;
	}
}

static void	init_game(t_vars *vars)
{
	WIN->mlx_ptr = mlx_init();
	WIN->win_ptr = mlx_new_window(WIN->mlx_ptr, WIN->width, WIN->height, "CUB3D");

	// print_map
	int width_case;
	int height_case;
	int x = 0;
	int y = 0;
	int pos_x;
	int pos_y;
	int red;
	char **rgb;

	rgb = malloc(3);
	width_case = WIN->width / MAP->nb_col;
	height_case = WIN->height / MAP->nb_row;
	while (x < (int)MAP->nb_col)
	{
		y = 0;
		while (y < (int)MAP->nb_row)
		{
			if (MAP->layout[y][x] == 1)
			{
				draw_rect(vars, x * width_case, y * height_case, (x + 1) * width_case, (y + 1) * height_case, CUB->c_color);
			}
			else
			{
				draw_rect(vars, x * width_case, y * height_case, x * (width_case + 1), y * (height_case + 1), CUB->f_color);
			}
			y++;
		}
		x++;
	}
	pos_x = MAP->camera->x_pos;
	pos_y = MAP->camera->y_pos;
	rgb[0] = ft_strdup("255");
	rgb[1] = ft_strdup("0");
	rgb[2] = ft_strdup("0");
	red = get_color_handle(rgb);
	draw_rect(vars, pos_x * width_case, pos_y * height_case, width_case, height_case, red);
	// End print_map

	mlx_loop(WIN->mlx_ptr);
}

static void	cub3d(char *map_path, char *option)
{
	t_vars	*vars;

	(void)option;
	vars = vars_init();
	read_map(map_path, vars);
	init_game(vars);
}

int			main(int ac, char **av)
{
	if (ac > 3 || ac < 2)
		exit_failure("You must have at least two arguments;\n");
	else if (ac == 2 && !check_args(av[1], NULL))
		cub3d(av[1], NULL);
	else if (ac == 3 && !check_args(av[1], av[2]))
		cub3d(av[1], av[2]);
	return (EXIT_SUCCESS);
}
