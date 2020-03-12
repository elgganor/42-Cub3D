/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cub_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:43:23 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/03/12 17:02:17 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	get_texture_path(char *line, t_image *texture)
{
	char	**path;

	path = ft_split(line, ' ');
	if (path[1])
		texture->path = ft_strdup(path[1]);
	free_split(path);
}

void	get_color(char *line, int *color, t_game *game)
{
	int		i;
	char	**rgb;

	i = 0;
	*color = 0x0;
	while (line[i] && !ft_isdigit(line[i]))
		i++;
	rgb = ft_split(line + i, ',');
	*color = get_color_handle(rgb, game);
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
				exit_failure("The map already has a direction;\n", game);
		}
	}
}
