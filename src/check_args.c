/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 09:42:51 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/01/28 09:42:52 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_args(char *map_path, char *option)
{
	char	**path;
	int		path_len;

	path_len = 0;
	if (map_path)
	{
		path = ft_split(map_path, '.');
		while (path[path_len])
			path_len++;
		if (ft_strncmp(path[path_len - 1],"cub", 4))
		{
			ft_puterror("Wrong extension for the map;\n");
			return (EXIT_FAILURE);
		}
	}
	if (option)
	{
		if (ft_strncmp(option, "--save", 7))
		{
			ft_puterror("Wrong option;\n");
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}