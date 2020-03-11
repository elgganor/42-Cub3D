/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 08:57:29 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/03/11 13:40:05 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_split(char **str)
{
	int	len;

	len = 0;
	while (str[len])
		free(str[len++]);
	free(str);
}

void	free_sprites(t_sprites **head_ref)
{
	t_sprites *current;
	t_sprites *next;

	current = (*head_ref);
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	(*head_ref) = NULL;
}

void	clear_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->no_texture)
		free(game->no_texture);
	if (game->so_texture)
		free(game->so_texture);
	if (game->we_texture)
		free(game->we_texture);
	if (game->ea_texture)
		free(game->ea_texture);
	if (game->sp_texture)
		free(game->sp_texture);
	if (game->layout)
	{
		free(game->layout->tmp_map);
		if (game->layout->map)
		{
			while (i++ < game->layout->nb_row)
				free(game->layout->map[i]);
			free(game->layout->map);
		}
		free(game->layout);
	}
}

void	clear_window(t_window *window)
{
	if (window->win_ptr)
		mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	free(window->mlx_ptr);
	free(window);
}

void	clear_game(t_game *game)
{
	if (game->player)
		free(game->player);
	clear_map(game);
	free(game->keys);
	if (game->sprites_head)
		free_sprites(&game->sprites_head);
	if (game->image->path)
		free(game->image->path);
	if (game->image->img_ptr)
		mlx_destroy_image(game->window->mlx_ptr, game->image->img_ptr);
	free(game->image);
	clear_window(game->window);
	free(game);
}
