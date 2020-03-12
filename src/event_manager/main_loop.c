/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:32:49 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/03/12 08:22:19 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main_loop(t_game *game)
{
	key_manager(game);
	mlx_clear_window(game->window->mlx_ptr, game->window->win_ptr);
	raycasting(game, game->player, game->window, game->ray);
	return (0);
}
