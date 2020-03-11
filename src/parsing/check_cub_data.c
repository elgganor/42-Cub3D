/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 10:57:55 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/03/11 14:27:25 by mrouabeh         ###   ########.fr       */
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

static void	check_texture(char *texture_path, char *texture)
{
	char	**path;
	int		len;

	if (!texture_path)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd(texture, STDERR_FILENO);
		ft_putstr_fd("Missing texture;\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	len = 0;
	path = ft_split(texture_path, '.');
	while (path[len])
		len++;
	if (ft_strcmp(path[len - 1], "xpm"))
		exit_failure("Wrong extension for xpm file;\n");
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
		exit_failure("Missing layout;\n");
	else
	{
		i = 0;
		while (game->layout->tmp_map[i])
		{
			if (!ft_islayout_char(game->layout->tmp_map[i]))
				exit_failure("Wrong characters in the layout;\n");
			if (game->layout->tmp_map[i] == '2'
				&& game->sp_texture->path == NULL)
			{
				clear_game(game);
				exit_failure("The sprite texture doesn't exist;\n");
			}
			i++;
		}
		if (game->player->dir == '0')
			exit_failure("No direction;\n");
	}
}

void		check_cub_data(t_game *game)
{
	check_dimensions(&(game->window->width),
					&(game->window->height));
	check_texture(game->no_texture->path, "NO: ");
	check_texture(game->so_texture->path, "SO: ");
	check_texture(game->we_texture->path, "WE: ");
	check_texture(game->ea_texture->path, "EA: ");
	if (game->sp_texture->path)
		check_texture(game->sp_texture->path, "S : ");
	check_map(game);
}
