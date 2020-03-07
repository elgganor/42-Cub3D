/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 09:24:37 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/03/07 08:42:01 by mohamed          ###   ########.fr       */
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
void		print_map(int **map, int nb_row, int nb_col);
void print_sprites(t_sprites *head_ref);

t_player	*player_struct_init(void);
t_layout	*layout_struct_init(void);
t_window	*window_struct_init(void);
t_game		*game_struct_init(void);
t_keys		*keys_struct_init(void);
t_image		*image_struct_init(void);
t_sprites	*sprites_struct_init(t_sprite *sprite, double distance);

void		read_map(char *map_path, t_game *game);
void		get_resolution(char *line, int *width, int *height);
void		get_texture_path(char *line, t_image *texture);
void		get_color(char *line, int *color);
int			get_color_handle(char **rgb);
void		get_layout(t_game *game);
void		get_map(char *line, t_game *game);
int			ft_isdirection(char c);
void		check_layout(t_layout *layout, t_player *player);
void		get_texture(t_game *game);

int			check_args(char *map_path, char *option);
void		check_cub_data(t_game *game);

void		free_split(char **str);
void		ft_puterror(char *str);
void		exit_failure(char *error);

int			key_press(int key_code, t_game *game);
int			key_release(int key_code, t_game *game);
void		key_manager(t_game *game);
int			main_loop(t_game *game);

void		set_position(t_player *player, float pos_x, float pos_y);
void		init_player(t_player *player);
void		move_forward(t_layout *layout, t_player *player);
void		move_backward(t_layout *layout, t_player *player);
void		move_left(t_layout *layout, t_player *player);
void		move_right(t_layout *layout, t_player *player);
void		rotate_left(t_player *player);
void		rotate_right(t_player *player);

void		dda(t_game *game, t_layout *layout, t_ray *ray);
void		raycasting(t_game *game, t_player *player, t_window *window, t_ray ray);

void		draw_col(t_game *game, t_window *window, t_ray *ray);
void		pixel_put(t_image *image, int x, int y, int color);
void		set_color_on_image(t_game *game, t_ray *ray);
void		set_texture_on_image(t_game *game, t_image *texture, t_ray *ray);
void		texture_put(t_game *game, t_image *texture, t_ray *ray);

void		is_sprite(t_game *game, t_ray *ray);
void draw_sprites(t_game *game, t_player *player, t_window *window, t_ray *ray);
void size_sprite(t_sprites *current, t_window *window);
void projection_sprite(t_player *player, t_window *window, t_sprites *current);
#endif
