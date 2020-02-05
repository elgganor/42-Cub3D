/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 10:38:14 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/05 08:44:25 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct	s_cub
{
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	char	*sp_texture;

	int		f_color;
	int		c_color;

	char	*layout;
	char	dir;
}				t_cub;

typedef struct	s_player
{
	int	x_position;
	int	y_position;
}				t_player;

typedef struct	s_window
{
	int		height;
	int		width;
	void	*win_ptr;
}				t_window;

typedef struct	s_vars
{
	int			map_started;
	void		*mlx_ptr;
	t_cub		*cub;
	t_window	*window;
}				t_vars;
#endif
