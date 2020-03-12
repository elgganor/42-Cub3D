/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 09:24:29 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/03/12 18:16:41 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		exit_game(t_game *game)
{
	clear_game(game);
	exit(EXIT_SUCCESS);
}

static void	game_init(t_game *game)
{
	game->window->mlx_ptr = mlx_init();
	game->window->win_ptr = mlx_new_window(game->window->mlx_ptr,
							game->window->width, game->window->height, "CUB3D");
	get_texture(game);
	game->image->img_ptr = mlx_new_image(game->window->mlx_ptr,
									game->window->width, game->window->height);
	game->image->img_data = mlx_get_data_addr(game->image->img_ptr,
		&(game->image->bpp), &(game->image->size_line), &(game->image->endian));
}

static void	game_loop(t_game *game)
{
	game_init(game);
	if (game->save == 1)
		raycasting(game, game->player, game->window, game->ray);
	mlx_hook(game->window->win_ptr, KEY_PRESS, 1L << 0, key_press, game);
	mlx_hook(game->window->win_ptr, KEY_RELEASE, 1L << 1, key_release, game);
	mlx_hook(game->window->win_ptr, 17, 1L << 17, destroy_window, game);
	mlx_loop_hook(game->window->mlx_ptr, main_loop, game);
	mlx_loop(game->window->mlx_ptr);
}

static void	cub3d(char *map_path, int save, t_game *game)
{
	game->save = save;
	read_map(map_path, game);
	game_loop(game);
}

int			main(int ac, char **av)
{
	t_game *game;

	if (!(game = game_struct_init()))
	{
		ft_puterror("Impossible to allocate memory for game structure;\n");
		exit(EXIT_FAILURE);
	}
	if (ac > 3 || ac < 2)
		exit_failure("You must have at least two arguments;\n", game);
	else if (ac == 2 && !check_args(av[1], NULL, game))
		cub3d(av[1], 0, game);
	else if (ac == 3 && !check_args(av[1], av[2], game))
		cub3d(av[1], 1, game);
	return (EXIT_SUCCESS);
}
