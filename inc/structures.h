/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 10:38:14 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/08 12:46:01 by mrouabeh         ###   ########.fr       */
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

	char	dir;
}				t_player;

typedef struct	s_layout
{
	char	*tmp_map;
	int		**map;

	size_t	nb_col;
	size_t	nb_row;
}				t_layout;

typedef struct	s_window
{
	int		height;
	int		width;

	void	*mlx_ptr;
	void	*win_ptr;
}				t_window;

typedef struct	s_game
{
	int			map_started;

	t_player	*player;
	t_layout	*layout;
	t_window	*window;
	t_keys		*keys;

	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	char		*sp_texture;

	int			c_color;
	int			f_color;
}				t_game;
#endif
