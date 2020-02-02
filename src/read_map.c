/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 10:29:13 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/02 09:31:05 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_cub_data(char *line, t_vars *vars)
{
	if ((vars->map_started == 1) && !ft_isdigit(line[0]))
		exit_failure("The map has a wrong format;\n");
	else if (!ft_strncmp(line, "R ", 2))
		get_resolution(line, &(CUB->width), &(CUB->height));
	else if (!ft_strncmp(line, "NO ", 3))
		get_texture(line, &(CUB->no_texture));
	else if (!ft_strncmp(line, "SO ", 3))
		get_texture(line, &(CUB->so_texture));
	else if (!ft_strncmp(line, "WE ", 3))
		get_texture(line, &(CUB->we_texture));
	else if (!ft_strncmp(line, "EA ", 3))
		get_texture(line, &(CUB->ea_texture));
	else if (!ft_strncmp(line, "S ", 2))
		get_texture(line, &(CUB->sp_texture));
	else if (!ft_strncmp(line, "C ", 2))
		get_color(line, &(CUB->c_color));
	else if (!ft_strncmp(line, "F ", 2))
		get_color(line, &(CUB->f_color));
	else if (ft_isdigit(line[0]))
	{
		vars->map_started = 1;
		get_map(line, &(MAP), &(CUB->dir));
	}
}

void		read_map(char *map_path, t_vars *vars)
{
	int		fd;
	char	*line;

	if ((fd = open(map_path, O_RDONLY)) < 0)
	{
		exit_failure("The file doesn't exist;\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		while (get_next_line(fd, &line) > 0)
		{
			get_cub_data(line, vars);
			free(line);
		}
		get_cub_data(line, vars);
		free(line);
	}
}
