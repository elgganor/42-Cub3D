/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 10:38:14 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/07 12:14:18 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct	s_position
{
	float	x_pos;
	float	y_pos;
}				t_position;

typedef struct	s_layout
{
	char		*map;
	int			**layout;
	t_position	*camera;
	size_t		nb_row;
	size_t		nb_col;
	char		dir;
}				t_layout;

typedef struct	s_cub
{
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	char	*sp_texture;
	int		f_color;
	int		c_color;
	t_layout	*layout;
}				t_cub;

typedef struct	s_player
{
	float	x_position;
	float	y_position;
	float	rotation_speed;
	float	move_speed;
	float	fov;
}				t_player;

typedef struct	s_window
{
	int		height;
	int		width;
	void	*mlx_ptr;
	void	*win_ptr;
}				t_window;

typedef struct	s_vars
{
	int			map_started;
	t_cub		*cub;
	t_window	*window;
}				t_vars;
#endif
