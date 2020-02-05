/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 09:24:37 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/05 08:18:43 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "includes.h"
# include "libft.h"
# include "structures.h"
# include "constant.h"
# include <mlx.h>

/*
** ===== Prototypes =====
*/
int			check_args(char *map_path, char *option);
void		ft_puterror(char *str);
void		exit_failure(char *error);
void		read_map(char *map_path, t_vars *vars);
t_cub		*cub_init(void);
t_vars		*vars_init(void);
t_window	*win_init(void);
void		get_resolution(char *line, int *width, int *height);
void		get_texture(char *line, char **str);
void		get_color(char *line, int *color);
int			get_color_handle(char **rgb);
void		get_map(char *line, char **layout, char *direction);
void		free_split(char **str);
void		check_cub_data(t_vars *vars);
#endif
