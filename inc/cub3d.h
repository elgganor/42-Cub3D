/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 09:24:37 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/01 10:13:10 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "includes.h"
# include "libft.h"
# include "structures.h"
# include "mlx.h"

/*
** ===== Prototypes =====
*/
int		check_args(char *map_path, char *option);
void	ft_puterror(char *str);
void	read_map(char *map_path, t_cub *cub);
t_cub	*cub_init(void);
void	get_resolution(char *line, int *width, int *height);
void	get_texture(char *line, char **str);
void	get_color(char *line, int *color);
int		get_color_handle(char **rgb);
void	get_map(char *line, char **layout);
void	free_split(char **str);
#endif