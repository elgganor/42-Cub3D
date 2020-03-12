/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 09:42:51 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/03/12 16:55:18 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			check_args(char *map_path, char *option, t_game *game)
{
	char	**path;
	int		path_len;

	path_len = 0;
	if (map_path)
	{
		path = ft_split(map_path, '.');
		while (path[path_len])
			path_len++;
		if (ft_strncmp(path[path_len - 1], "cub", 4))
		{
			exit_failure("Wrong extension for the map;\n", game);
		}
		free_split(path);
	}
	if (option)
	{
		if (ft_strncmp(option, "--save", 7))
		{
			exit_failure("Wrong option;\n", game);
		}
	}
	return (EXIT_SUCCESS);
}
