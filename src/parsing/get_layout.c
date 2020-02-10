/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_layout.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 10:57:34 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/10 07:56:17 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	*get_row(char *line, t_game *game, int row_nb)
{
	int		*row;
	size_t	i;

	if (!(row = (int *)malloc(sizeof(int) * game->layout->nb_col)))
		return (NULL);
	i = 0;
	while (i < game->layout->nb_col)
	{
		while (line[i])
		{
			if (ft_isdirection(line[i]))
			{
				game->player->pos_x = (float)i;
				game->player->pos_y = (float)row_nb;
				row[i] = 0;
			}
			else
				row[i] = ft_isdigit(line[i]) ? line[i] - '0' : 0;
			i++;
		}
		while (i < game->layout->nb_col)
			row[i++] = 0;
	}
	return (row);
}

void		get_layout(t_game *game)
{
	char		**split_layout;
	t_layout	*layout;
	size_t		i;

	layout = game->layout;
	split_layout = ft_split(layout->tmp_map, '\n');
	while (split_layout[layout->nb_row])
	{
		if (layout->nb_col < ft_strlen(split_layout[layout->nb_row]))
			layout->nb_col = ft_strlen(split_layout[layout->nb_row]);
		layout->nb_row++;
	}
	if (!(layout->map = (int **)malloc(layout->nb_row * sizeof(int *))))
		return ;
	i = 0;
	while (i < layout->nb_row)
	{
		layout->map[i] = get_row(split_layout[i], game, i);
		i++;
	}
	free_split(split_layout);
}
