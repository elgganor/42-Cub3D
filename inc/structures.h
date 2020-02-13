/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 10:38:14 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/13 11:43:57 by mrouabeh         ###   ########.fr       */
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
	float	pos_x;
	float	pos_y;
	float	dir_x;
	float	dir_y;
	float	plan_x;
	float	plan_y;
	char	dir;
	float	mov_speed;
	float	rot_speed;
}				t_player;

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

typedef struct	s_ray
{
	float	camera_x;
	float	perp_wall_dist;
	float	ray_x;
	float	ray_y;
	float	side_dist_x;
	float	side_dist_y;
	float	delta_dist_x;
	float	delta_dist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
}				t_ray;

typedef struct	s_game
{
	int			map_started;

	t_player	*player;
	t_layout	*layout;
	t_window	*window;
	t_keys		*keys;
	t_ray		ray;

	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	char		*sp_texture;

	int			c_color;
	int			f_color;
}				t_game;
#endif
