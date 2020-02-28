/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 09:24:29 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/28 12:31:49 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	game_start(t_game *game, char *option)
{
	game->window->mlx_ptr = mlx_init();
	game->window->win_ptr = mlx_new_window(game->window->mlx_ptr,
						game->window->width, game->window->height, "CUB3D");
	get_texture(game);
	game->image->img_ptr = mlx_new_image(game->window->mlx_ptr, game->window->width, game->window->height);
	game->image->img_data = mlx_get_data_addr(game->image->img_ptr, &(game->image->bpp), &(game->image->size_line), &(game->image->endian));
	if (option)
	{
		// take_screenshot()
	}
	mlx_hook(game->window->win_ptr, KEY_PRESS, 1L << 0, key_press, game);
	mlx_hook(game->window->win_ptr, KEY_RELEASE, 1L << 1, key_release, game);
	mlx_loop_hook(game->window->mlx_ptr, main_loop, game);
	mlx_loop(game->window->mlx_ptr);
}

static void	cub3d(char *map_path, char *option)
{
	t_game *game;

	if (!(game = game_struct_init()))
		exit_failure("Erreur d'initialisation\n");
	read_map(map_path, game);
	game_start(game, option);
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
