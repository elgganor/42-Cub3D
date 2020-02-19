/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 10:38:14 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/19 10:25:17 by mrouabeh         ###   ########.fr       */
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
	int		map_x;
	int		map_y;
	double	dir_x;
	double	dir_y;
	double	plan_x;
	double	plan_y;
	char	dir;
	double	mov_speed;
	double	rot_speed;
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
	double	camera_x;
	double	perp_wall_dist;
	double	ray_x;
	double	ray_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
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
