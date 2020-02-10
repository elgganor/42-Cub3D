/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 10:57:55 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/10 12:43:06 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_dimensions(int *width, int *height)
{
	if (*width <= 0 || *height <= 0)
		exit_failure("The map cannot have a negative or null width/height;\n");
	if (*width > MAX_WIDTH)
		*width = MAX_WIDTH;
	if (*height > MAX_HEIGHT)
		*height = MAX_HEIGHT;
}

static void	check_texture(char *texture_path, char *texture)
{
	if (!texture_path)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd(texture, STDERR_FILENO);
		ft_putstr_fd("Missing texture;\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

static int	ft_islayout_char(char c)
{
	if (c == 'N' || c == 'W' || c == 'S' || c == 'E')
		return (1);
	else if (c == '0' || c == '1' || c == '2' || c == '\n' || c == ' ')
		return (1);
	return (0);
}

static void	check_map(t_game *game)
{
	int	i;

	if (!game->layout)
		exit_failure("Missing layout;\n");
	else
	{
		i = 0;
		while (game->layout->tmp_map[i])
		{
			if (!ft_islayout_char(game->layout->tmp_map[i]))
				exit_failure("Wrong characters in the layout;\n");
			i++;
		}
		if (game->player->dir == '0')
			exit_failure("No direction;\n");
	}
}

void		check_cub_data(t_game *game)
{
	check_dimensions(&(game->window->resolution.x),
					&(game->window->resolution.y));
	check_texture(game->no_texture, "NO: ");
	check_texture(game->so_texture, "SO: ");
	check_texture(game->we_texture, "WE: ");
	check_texture(game->ea_texture, "EA: ");
	check_texture(game->sp_texture, "S : ");
	check_map(game);
}
