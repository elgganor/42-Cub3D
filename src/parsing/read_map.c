/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 10:29:13 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/03/12 17:29:26 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_data(char *line, t_game *game)
{
	if (!ft_strncmp(line, "R", 1))
		get_resolution(line, &(game->window->width),
						&(game->window->height));
	else if (!ft_strncmp(line, "NO", 2))
		get_texture_path(line, game->no_texture);
	else if (!ft_strncmp(line, "SO", 2))
		get_texture_path(line, game->so_texture);
	else if (!ft_strncmp(line, "WE", 2))
		get_texture_path(line, game->we_texture);
	else if (!ft_strncmp(line, "EA", 2))
		get_texture_path(line, game->ea_texture);
	else if (!ft_strncmp(line, "S", 1))
		get_texture_path(line, game->sp_texture);
	else if (!ft_strncmp(line, "C", 1))
		get_color(line, &(game->c_color), game);
	else if (!ft_strncmp(line, "F", 1))
		get_color(line, &(game->f_color), game);
}

static void	get_cub_data(char *line, t_game *game)
{
	if (game->map_started == 1)
	{
		if (game->map_stopped == 1 && !ft_isempty(line))
			exit_failure("The map has a wrong format;\n", game);
		else
		{
			if (ft_isempty(line))
				game->map_stopped = 1;
			else if (ft_isrow(line))
				get_map(line, game);
			else if (game->map_started == 1)
				exit_failure("The map has a wrong format;\n", game);
		}
	}
	else
	{
		if (ft_isrow(line))
		{
			game->map_started = 1;
			get_map(line, game);
		}
		else
			get_data(line, game);
	}
}

void		read_map(char *map_path, t_game *game)
{
	int			fd;
	char		*line;

	if ((fd = open(map_path, O_RDONLY)) < 0)
		exit_failure("The file doesn't exist;\n", game);
	else
	{
		while (get_next_line(fd, &line) > 0)
		{
			if (game->map_started == 0)
				line = ft_strtrim(line, " ");
			get_cub_data(line, game);
			free(line);
		}
		get_cub_data(line, game);
		free(line);
		check_cub_data(game);
		get_layout(game);
		check_layout(game, game->layout, game->player);
	}
}
