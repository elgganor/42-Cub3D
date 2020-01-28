/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 10:29:13 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/01/28 10:29:14 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_cub *map_init(void)
{
	t_cub *cub;

	if (!(cub = (t_cub *)malloc(sizeof(t_cub))))
		return (NULL);
	if (!(cub->resolution = (int *)malloc(sizeof(int) * 2)))
		return (NULL);
	cub->no_texture = NULL;
	cub->so_texture = NULL;
	cub->we_texture = NULL;
	cub->ea_texture = NULL;
	cub->sp_texture = NULL;
	cub->map = NULL;
	return (cub);
}

// get_map
// get_cub_data

static int	check_map_line(char *line)
{
	if (!ft_strncmp(line, "R ", 2))
		return (1);
	else if (!ft_strncmp(line, "NO ", 3))
		return (2);
	else if (!ft_strncmp(line, "SO ", 3))
		return (3);
	else if (!ft_strncmp(line, "WE ", 3))
		return (4);
	else if (!ft_strncmp(line, "EA ", 3))
		return (5);
	else if (!ft_strncmp(line, "S ", 2))
		return (6);
	else if (!ft_strncmp(line, "C ", 2))
		return (7);
	else if (!ft_strncmp(line, "F ", 2))
		return (8);
	else if (line[0] == '1')
		return (9);
	return (0);
}

void		read_map(char *map_path, t_cub *cub)
{
	int	fd;
	int	type;
	char *line;

	if ((fd = open(map_path, O_RDONLY)) < 0)
	{
		ft_puterror("The file doesn't exist;\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		while (get_next_line(fd, &line) > 0)
		{
			// On check de quel type il s'agit
			type = check_map_line(line);
		}
	}
}