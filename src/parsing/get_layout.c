/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_layout.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 10:57:34 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/07 12:57:25 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_isdirection(char c)
{
	if (c == 'N' || c == 'W' || c == 'S' || c == 'E')
		return (1);
	return (0);
}

static int	*get_row(char *line, t_vars *vars, int row_nb)
{
	int		*row;
	size_t	i;

	if(!(row = (int *)malloc(sizeof(int) * MAP->nb_col)))
		return (NULL);
	i = 0;
	while (i < MAP->nb_col)
	{
		while (line[i])
		{
			if (!ft_isdigit(line[i]))
			{
				if (ft_isdirection(line[i]))
				{
					MAP->camera->y_pos = (float)i;
					MAP->camera->x_pos = (float)row_nb;
				}
				row[i] = 0;
			}
			else
				row[i] = line[i] - '0';
			i++;
		}
		while (i < MAP->nb_col)
			row[i++] = 0;
	}
	return (row);
}

void		get_layout(t_vars *vars)
{
	char	**split_layout;
	size_t	i;

	split_layout = ft_split(MAP->map, '\n');
	while (split_layout[MAP->nb_row])
	{
		if (MAP->nb_col < ft_strlen(split_layout[MAP->nb_row]))
			MAP->nb_col = ft_strlen(split_layout[MAP->nb_row]);
		MAP->nb_row++;
	}
	if (!(MAP->layout = (int **)malloc(MAP->nb_row * sizeof(int *))))
		return ;
	i = 0;
	while (i < MAP->nb_row)
	{
		MAP->layout[i] = get_row(split_layout[i], vars, i);
		i++;
	}
	free_split(split_layout);
}
