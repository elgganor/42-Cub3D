/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 09:24:29 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/09 18:20:12 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void	game_start(t_game *game, char *option)
// {
// 	t_window *win;

// 	win = game->window;
// 	win->mlx_ptr = mlx_init();
// 	win->win_ptr = mlx_new_window(win->mlx_ptr,
// 									win->width, win->height, "CUB3D");
// 	if (option)
// 	{
// 		// take_screenshot()
// 	}
// 	mlx_hook(win->win_ptr, KEY_PRESS, 0, &(key_press), game);
// 	mlx_hook(win->win_ptr, KEY_RELEASE, 0, &(key_release), game);
// 	mlx_loop_hook(win->win_ptr, &(main_loop), game);
// 	mlx_loop(win->mlx_ptr);
// }

// static void print_map(int **map, int nb_row, int nb_col)
// {
// 	int x;
// 	int y;

// 	y = 0;
// 	while (y < nb_col)
// 	{
// 		x = 0;
// 		while (x < nb_row)
// 		{
// 			ft_putnbr(map[y][x]);
// 			x++;
// 		}
// 		ft_putchar('\n');
// 		y++;
// 	}
// }

static void	cub3d(char *map_path, char *option)
{
	t_game *game;

	(void)option;
	game = game_struct_init();
	read_map(map_path, game);
	// print_map(game->layout->map, game->layout->nb_row, game->layout->nb_col);
	// game_start(game, option);
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
