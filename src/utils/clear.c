/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 08:49:05 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/03/12 16:11:26 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clear_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->layout->tmp_map)
		free(game->layout->tmp_map);
	if (game->layout->map)
	{
		while (i < game->layout->nb_row)
			free(game->layout->map[i++]);
		free(game->layout->map);
	}
	free(game->layout);
}

void	clear_window(t_window *window)
{
	if (window->win_ptr)
		mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	free(window);
}

void	clear_image(t_image *image, t_window *window)
{
	if (image->path)
		free(image->path);
	if (image->img_ptr)
		mlx_destroy_image(window->mlx_ptr, image->img_ptr);
	free(image);
}

void	clear_game(t_game *game)
{
	free(game->keys);
	free(game->player);
	clear_map(game);
	clear_image(game->no_texture, game->window);
	clear_image(game->so_texture, game->window);
	clear_image(game->we_texture, game->window);
	clear_image(game->ea_texture, game->window);
	clear_image(game->sp_texture, game->window);
	clear_image(game->image, game->window);
	if (game->sprites_head)
		free_sprites(&game->sprites_head);
	free(game->sprites_head);
	clear_window(game->window);
	free(game);
}
