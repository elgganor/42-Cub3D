/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cub_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:43:23 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/20 14:12:12 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_isdirection(char c)
{
	if (c == 'N' || c == 'W' || c == 'S' || c == 'E')
		return (1);
	return (0);
}

void	get_resolution(char *line, int *width, int *height)
{
	int	i;

	i = 0;
	while (line[i] && !ft_isdigit(line[i]))
		i++;
	*width = ft_atoi(line + i);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	while (line[i] && !ft_isdigit(line[i]))
		i++;
	*height = ft_atoi(line + i);
}

void	get_texture(char *line, char **str)
{
	char	**path;

	path = ft_split(line, ' ');
	if (path[1])
		*str = ft_strdup(path[1]);
	free_split(path);
}

void	get_color(char *line, int *color)
{
	int		i;
	char	**rgb;

	i = 0;
	*color = 0x0;
	while (line[i] && !ft_isdigit(line[i]))
		i++;
	rgb = ft_split(line + i, ',');
	*color = get_color_handle(rgb);
	free_split(rgb);
}

void	get_map(char *line, t_game *game)
{
	int	i;

	ft_strjoin_free(&(game->layout->tmp_map), line);
	ft_strjoin_free(&(game->layout->tmp_map), "\n");
	i = -1;
	while (line[++i])
	{
		if (ft_isdirection(line[i]))
		{
			if (game->player->dir == '0')
			{
				game->player->dir = line[i];
				init_player(game->player);
			}
			else
				exit_failure("The map already has a direction;\n");
		}
	}
}
