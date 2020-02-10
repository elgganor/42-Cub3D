/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_layout.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 10:57:34 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/10 12:59:53 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	*get_row(char *line, t_game *game, int row_nb)
{
	int	*row;
	int	i;

	if (!(row = (int *)malloc(sizeof(int) * game->layout->size.x)))
		return (NULL);
	i = 0;
	while (i < game->layout->size.x)
	{
		while (line[i])
		{
			if (ft_isdirection(line[i]))
			{
				game->player->position.x = (float)i;
				game->player->position.y = (float)row_nb;
				row[i] = 0;
			}
			else
				row[i] = ft_isdigit(line[i]) ? line[i] - '0' : 0;
			i++;
		}
		while (i < game->layout->size.x)
			row[i++] = 0;
	}
	return (row);
}

void		get_layout(t_game *game)
{
	char		**split_layout;
	t_layout	*layout;
	int			i;

	layout = game->layout;
	split_layout = ft_split(layout->tmp_map, '\n');
	while (split_layout[(int)layout->size.y])
	{
		if (layout->size.x < (int)ft_strlen(split_layout[layout->size.y]))
			layout->size.x = (int)ft_strlen(split_layout[layout->size.y]);
		layout->size.y++;
	}
	if (!(layout->map = (int **)malloc(layout->size.y * sizeof(int *))))
		return ;
	i = 0;
	while (i < layout->size.y)
	{
		layout->map[i] = get_row(split_layout[i], game, i);
		i++;
	}
	free_split(split_layout);
}
