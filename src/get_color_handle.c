/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 09:12:40 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/01 10:45:50 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_colors(int r, int g, int b)
{
	if ((r < 0 || 255 < r) || (g < 0 || 255 < g) || (b < 0 || 255 < b))
		return (0);
	return (1);
}

int			get_color_handle(char **rgb)
{
	int	r;
	int	g;
	int	b;
	int	color;

	color = 0;
	if (!rgb[0] || !rgb[1] || !rgb[2])
		ft_puterror("Wrong data for the color;\n");
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (check_colors(r, g, b))
	{
		color = r;
		color = (color << 8) + g;
		color = (color << 8) + b;
	}
	else
	{
		ft_puterror("Wrong data for the color;\n");
	}
	return (color);
}
