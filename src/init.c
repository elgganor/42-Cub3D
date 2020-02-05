/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 10:42:35 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/05 08:44:38 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	cub->layout = NULL;
	cub->f_color = 0x0;
	cub->c_color = 0x0;
	cub->dir = '0';
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
	return (window);
}

t_vars		*vars_init(void)
{
	t_vars	*vars;

	if (!(vars = (t_vars *)malloc(sizeof(t_vars))))
		return (NULL);
	vars->map_started = 0;
	vars->mlx_ptr = NULL;
	CUB = cub_init();
	WIN = win_init();
	return (vars);
}
