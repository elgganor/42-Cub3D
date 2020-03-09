/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 08:57:29 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/03/09 12:55:06 by mrouabeh         ###   ########.fr       */
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

void	free_game(t_game *game)
{
	free(game->image);
	free(game->no_texture);
	free(game->so_texture);
	free(game->we_texture);
	free(game->ea_texture);
	free(game->sp_texture);
	free(game->player);
}
