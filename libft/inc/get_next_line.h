/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 10:53:30 by mrouabeh          #+#    #+#             */
/*   Updated: 2019/11/12 10:53:54 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "includes.h"
# include "libft.h"
# define BUFFER_SIZE 32

int		get_next_line(int fd, char **line);
void	ft_strjoin_free(char **str, char *buf);
int		get_line(char **line, char **str, int index, int step);
int		check_line_break(char *str);
int		check_error(int fd, char **line);
#endif
