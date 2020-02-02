/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cub_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:43:23 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/02 09:33:45 by mrouabeh         ###   ########.fr       */
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

void	get_map(char *line, char **layout, char *direction)
{
	int	i;

	ft_strjoin_free(layout, line);
	ft_strjoin_free(layout, "\n");
	i = 0;
	while (line[i])
	{
		if (line[i] == 'N' || line[i] == 'W' || line[i] == 'S' || line[i] == 'E')
		{
			if (*direction == '0')
				*direction = line[i];
			else
				exit_failure("The map already has a direction;\n");
		}
		i++;
	}
}
