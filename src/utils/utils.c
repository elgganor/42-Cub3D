/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:52:29 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/05/09 14:22:54 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_isdirection(char c)
{
	if (c == 'N' || c == 'W' || c == 'S' || c == 'E')
		return (1);
	return (0);
}

int	ft_isrow(char *row)
{
	int	i;

	i = 0;
	if (row[0] == '\0')
		return (0);
	while (row[i])
	{
		if (!ft_isdigit(row[i]) && !ft_isdirection(row[i]) && row[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	ft_isempty(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '\n'
			&& line[i] != '\t' && line[i] != '\0')
			return (0);
		i++;
	}
	return (1);
}
