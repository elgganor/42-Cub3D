/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 10:42:35 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/07 11:43:59 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_layout	*layout_init(void)
{
	t_layout	*layout;

	if (!(layout = (t_layout *)malloc(sizeof(t_layout))))
		return (NULL);
	if (!(layout->camera = (t_position *)malloc(sizeof(t_position))))
		return (NULL);
	layout->map = NULL;
	layout->layout = NULL;
	layout->nb_col = 0;
	layout->nb_row = 0;
	layout->dir = '0';
	layout->camera->x_pos = 0;
	layout->camera->y_pos = 0;
	return (layout);
}

t_cub		*cub_init(void)
{
	t_cub	*cub;

	if (!(cub = (t_cub *)malloc(sizeof(t_cub))))
		return (NULL);
	cub->no_texture = NULL;
	cub->so_texture = NULL;
	cub->we_texture = NULL;
	cub->ea_texture = NULL;
	cub->sp_texture = NULL;
	cub->f_color = 0x0;
	cub->c_color = 0x0;
	cub->layout = layout_init();
	return (cub);
}

t_window	*win_init(void)
{
	t_window *window;

	if (!(window = (t_window *)malloc(sizeof(t_window))))
		return (NULL);
	window->width = 0;
	window->height = 0;
	window->win_ptr = NULL;
	window->mlx_ptr = NULL;
	return (window);
}

t_vars		*vars_init(void)
{
	t_vars	*vars;

	if (!(vars = (t_vars *)malloc(sizeof(t_vars))))
		return (NULL);
	vars->map_started = 0;
	CUB = cub_init();
	WIN = win_init();
	return (vars);
}
