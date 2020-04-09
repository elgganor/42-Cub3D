/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 10:38:14 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/04/09 11:53:50 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct	s_keys
{
	int	left_arr;
	int	right_arr;
	int	key_a;
	int	key_s;
	int	key_d;
	int	key_w;
	int	key_esc;
}				t_keys;

typedef struct	s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plan_x;
	double	plan_y;
	char	dir;
	double	mov_speed;
	double	rot_speed;
}				t_player;

typedef struct	s_ray
{
	int		x;
	int		y;
	double	camera_x;
	double	perp_wall_dist;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		text_x;
	int		text_y;
	double	wall_x;
	double	*z_buffer;
}				t_ray;

typedef struct	s_layout
{
	char	*tmp_map;
	int		**map;
	int		nb_row;
	int		nb_col;
}				t_layout;

typedef struct	s_window
{
	int		width;
	int		height;
	void	*mlx_ptr;
	void	*win_ptr;
}				t_window;

typedef struct	s_image
{
	void	*img_ptr;
	char	*img_data;
	char	*path;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}				t_image;

typedef struct	s_sprite
{
	int	x;
	int	y;
}				t_sprite;

typedef struct	s_sprites
{
	t_sprite			*sprite;
	double				distance;
	int					draw_start_x;
	int					draw_end_x;
	int					draw_start_y;
	int					draw_end_y;
	double				sprite_x;
	double				sprite_y;
	double				inv_det;
	double				transform_x;
	double				transform_y;
	int					sprite_screen_x;
	int					sprite_height;
	int					sprite_width;
	int					text_x;
	int					text_y;
	int					x;
	int					y;
	struct s_sprites	*next;
}				t_sprites;

typedef struct	s_game
{
	int			map_started;
	int			map_stopped;
	int			save;

	t_player	*player;
	t_layout	*layout;
	t_window	*window;
	t_keys		*keys;
	t_ray		ray;
	t_image		*image;
	t_sprites	*sprites_head;

	t_image		*no_texture;
	t_image		*so_texture;
	t_image		*we_texture;
	t_image		*ea_texture;
	t_image		*sp_texture;

	int			c_color;
	int			f_color;
}				t_game;
#endif
