/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 09:24:29 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/05 10:21:31 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void update_window(t_vars *vars)
{
	mlx_clear_window(vars->mlx_ptr, WIN->win_ptr);
}

int print_key(int key_code, t_vars *vars)
{

	update_window(vars);
	if (key_code == KEY_A)
		mlx_string_put(vars->mlx_ptr, WIN->win_ptr, WIN->width / 2, WIN->height / 2, CUB->c_color, "Key A");
	else if (key_code == KEY_S)
		mlx_string_put(vars->mlx_ptr, WIN->win_ptr, WIN->width / 2, WIN->height / 2, CUB->c_color, "Key S");
	else if (key_code == KEY_D)
		mlx_string_put(vars->mlx_ptr, WIN->win_ptr, WIN->width / 2, WIN->height / 2, CUB->c_color, "Key D");
	else if (key_code == KEY_W)
		mlx_string_put(vars->mlx_ptr, WIN->win_ptr, WIN->width / 2, WIN->height / 2, CUB->c_color, "Key W");
	return (0);
}

static void	cub3d(char *map_path, char *option)
{
	t_vars	*vars;

	(void)option;
	vars = vars_init();
	read_map(map_path, vars);
	check_cub_data(vars);

	vars->mlx_ptr = mlx_init();
	// init_game();
	WIN->win_ptr = mlx_new_window(vars->mlx_ptr, WIN->width, WIN->height, "CUB3D");

	mlx_key_hook(WIN->win_ptr, &(print_key), vars);

	mlx_loop(vars->mlx_ptr);
}

int			main(int ac, char **av)
{
	if (ac > 3 || ac < 2)
		exit_failure("You must have at least two arguments;\n");
	else if (ac == 2 && !check_args(av[1], NULL))
		cub3d(av[1], NULL);
	else if (ac == 3 && !check_args(av[1], av[2]))
		cub3d(av[1], av[2]);
	return (EXIT_SUCCESS);
}
