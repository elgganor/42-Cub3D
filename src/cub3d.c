/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 09:24:29 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/01 10:18:17 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	cub3d(char *map_path, char *option)
{
	t_cub	*cub;

	(void)option;
	cub = cub_init();
	read_map(map_path, cub);
	ft_putstr(cub->layout);

	while (1) ;
}

int			main(int ac, char **av)
{
	if (ac > 3 || ac < 2)
		ft_puterror("You must have at least two arguments;\n");
	else if (ac == 2 && !check_args(av[1], NULL))
		cub3d(av[1], NULL);
	else if (ac == 3 && !check_args(av[1], av[2]))
		cub3d(av[1], av[2]);
	return (EXIT_SUCCESS);
}