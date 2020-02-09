/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 10:29:13 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/09 18:21:02 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_cub_data(char *line, t_game *game)
{
	if ((game->map_started == 1) && !ft_isdigit(line[0]))
		exit_failure("The map has a wrong format;\n");
	else if (!ft_strncmp(line, "R ", 2))
		get_resolution(line, &(game->window->width), &(game->window->height));
	else if (!ft_strncmp(line, "NO ", 3))
		get_texture(line, &(game->no_texture));
	else if (!ft_strncmp(line, "SO ", 3))
		get_texture(line, &(game->so_texture));
	else if (!ft_strncmp(line, "WE ", 3))
		get_texture(line, &(game->we_texture));
	else if (!ft_strncmp(line, "EA ", 3))
		get_texture(line, &(game->ea_texture));
	else if (!ft_strncmp(line, "S ", 2))
		get_texture(line, &(game->sp_texture));
	else if (!ft_strncmp(line, "C ", 2))
		get_color(line, &(game->c_color));
	else if (!ft_strncmp(line, "F ", 2))
		get_color(line, &(game->f_color));
	else if (ft_isdigit(line[0]))
	{
		game->map_started = 1;
		get_map(line, game);
	}
}

void		read_map(char *map_path, t_game *game)
{
	int			fd;
	char		*line;

	if ((fd = open(map_path, O_RDONLY)) < 0)
	{
		exit_failure("The file doesn't exist;\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		while (get_next_line(fd, &line) > 0)
		{
			get_cub_data(line, game);
			free(line);
		}
		get_cub_data(line, game);
		free(line);
		check_cub_data(game);
		get_layout(game);
		flood_fill(game->layout->map, (int)game->player->pos_x,
		(int)game->player->pos_x, game->layout->nb_row, game->layout->nb_col);
		// ft_putstr("Everything is good;\n");
	}
}
