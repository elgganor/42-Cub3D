/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 09:24:37 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/01/29 09:56:28 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "includes.h"
# include "libft.h"
# include "structures.h"

/*
** ===== Prototypes =====
*/
int		check_args(char *map_path, char *option);
void	ft_puterror(char *str);
void	read_map(char *map_path, t_cub *cub);
t_cub	*map_init(void);
void	get_resolution(char *line, int *width, int *height);
void	get_texture(char *line, char **str);
void	get_color(char *line, int *color);
void	get_map(char *line, char *map);
void	free_split(char **str);
int		ft_rgbtohex(int r, int g, int b);
#endif