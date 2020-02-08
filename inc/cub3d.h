/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 09:24:37 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/08 13:49:07 by mrouabeh         ###   ########.fr       */
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
t_player	*player_struct_init(void);
t_layout	*layout_struct_init(void);
t_window	*window_struct_init(void);
t_game		*game_struct_init(void);
t_keys		*keys_struct_init(void);

void		read_map(char *map_path, t_game *game);
void		get_resolution(char *line, int *width, int *height);
void		get_texture(char *line, char **str);
void		get_color(char *line, int *color);
int			get_color_handle(char **rgb);
void		get_layout(t_game *game);
void		get_map(char *line, t_game *game);
int			ft_isdirection(char c);

int			check_args(char *map_path, char *option);
void		check_cub_data(t_game *game);

void		free_split(char **str);
void		ft_puterror(char *str);
void		exit_failure(char *error);

int			key_press(int key_code, t_game *game);
int			key_release(int key_code, t_game *game);
int			main_loop(t_game *game);
#endif
