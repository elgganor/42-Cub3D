/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cub_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:43:23 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/01/29 10:24:10 by mrouabeh         ###   ########.fr       */
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
	*height =ft_atoi(line + i);
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
	int		hex_color;
	char	**rgb;

	i = 0;
	hex_color = 0x0;
	while (line[i] && !ft_isdigit(line[i]))
		i++;
	rgb = ft_split(line + i, ',');
	if (rgb[1] && rgb[2] && rgb[3])
	{
		// TODO: rgb to hex
	}
	*color = hex_color;
	free_split(rgb);
}

// void	get_map(char *line, char *map)
// {

// }