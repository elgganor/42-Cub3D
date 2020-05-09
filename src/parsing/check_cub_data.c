/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 10:57:55 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/05/09 14:23:28 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_dimensions(int *width, int *height)
{
	if (*width < 480)
		*width = 480;
	if (*height < 320)
		*height = 320;
	if (*width >= 2560)
		*width = 2560;
	if (*height >= 1440)
		*height = 1440;
}

static void	check_texture(t_game *game, char *texture_path)
{
	char	**path;
	int		len;

	if (!texture_path)
		exit_failure("Missing texture;\n", game);
	len = 0;
	path = ft_split(texture_path, '.');
	while (path[len])
		len++;
	if (ft_strcmp(path[len - 1], "xpm"))
	{
		free_split(path);
		exit_failure("Wrong extension for xpm file;\n", game);
	}
	free_split(path);
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
		exit_failure("Missing layout;\n", game);
	else
	{
		i = 0;
		while (game->layout->tmp_map[i])
		{
			if (!ft_islayout_char(game->layout->tmp_map[i]))
				exit_failure("Wrong characters in the layout;\n", game);
			if (game->layout->tmp_map[i] == '2'
				&& game->sp_texture->path == NULL)
				exit_failure("The sprite texture doesn't exist;\n", game);
			i++;
		}
		if (game->player->dir == '0')
			exit_failure("No direction;\n", game);
	}
}

void		check_cub_data(t_game *game)
{
	if (game->window->height == 0 || game->window->width == 0)
	{
		clear_game(game);
		exit_failure("Resolution missing;\n", game);
	}
	check_dimensions(&(game->window->width),
					&(game->window->height));
	check_texture(game, game->no_texture->path);
	check_texture(game, game->so_texture->path);
	check_texture(game, game->we_texture->path);
	check_texture(game, game->ea_texture->path);
	if (game->sp_texture->path)
		check_texture(game, game->sp_texture->path);
	check_map(game);
}
