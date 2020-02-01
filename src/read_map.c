/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 10:29:13 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/01 10:43:46 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_cub_data(char *line, t_cub *cub)
{
	if (!ft_strncmp(line, "R ", 2))
		get_resolution(line, &(cub->width), &(cub->height));
	else if (!ft_strncmp(line, "NO ", 3))
		get_texture(line, &(cub->no_texture));
	else if (!ft_strncmp(line, "SO ", 3))
		get_texture(line, &(cub->so_texture));
	else if (!ft_strncmp(line, "WE ", 3))
		get_texture(line, &(cub->we_texture));
	else if (!ft_strncmp(line, "EA ", 3))
		get_texture(line, &(cub->ea_texture));
	else if (!ft_strncmp(line, "S ", 2))
		get_texture(line, &(cub->sp_texture));
	else if (!ft_strncmp(line, "C ", 2))
		get_color(line, &(cub->c_color));
	else if (!ft_strncmp(line, "F ", 2))
		get_color(line, &(cub->f_color));
	else if (ft_isdigit(line[0]))
		get_map(line, &(cub->layout));
}

void		read_map(char *map_path, t_cub *cub)
{
	int		fd;
	char	*line;

	if ((fd = open(map_path, O_RDONLY)) < 0)
	{
		ft_puterror("The file doesn't exist;\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		while (get_next_line(fd, &line) > 0)
		{
			get_cub_data(line, cub);
			free(line);
		}
		get_cub_data(line, cub);
		free(line);
	}
}
