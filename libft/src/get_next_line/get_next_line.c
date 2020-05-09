/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 10:50:34 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/01 10:57:24 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strjoin_free(char **str, char *buf)
{
	char	*tmp;

	if (*str == NULL)
		*str = ft_strdup(buf);
	else if (**str == '\0')
	{
		free(*str);
		*str = ft_strdup(buf);
	}
	else
	{
		tmp = ft_strdup(*str);
		free(*str);
		*str = ft_strjoin(tmp, buf);
		free(tmp);
	}
}

int		check_error(int fd, char **line)
{
	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (0);
	return (1);
}

int		check_line_break(char *str)
{
	int	index;

	index = 0;
	if (!str)
		return (-1);
	while (str[index] != '\0')
	{
		if (str[index] == '\n')
			return (index);
		index++;
	}
	return (-1);
}

int		get_line(char **line, char **str, int index, int step)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!(*str))
	{
		*line = ft_strdup("");
		return (1);
	}
	if (!(*line = (char *)ft_calloc(index + 1, sizeof(char))))
		return (0);
	while (i < index)
	{
		(*line)[i] = (*str)[i];
		i++;
	}
	(*line)[i] = '\0';
	tmp = ft_strdup(*str);
	free(*str);
	*str = (step == 1) ? NULL : ft_strdup(tmp + index + 1);
	free(tmp);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*str = NULL;
	int			r;
	char		buf[BUFFER_SIZE + 1];

	if (check_error(fd, line) == 0)
		return (-1);
	while (check_line_break(str) == -1 && (r = read(fd, buf, BUFFER_SIZE)) != 0)
	{
		if ((r == -1) || (buf[r] = '\0'))
			return (-1);
		ft_strjoin_free(&str, buf);
	}
	if ((check_line_break(str) != -1))
		return ((get_line(line, &str, check_line_break(str), 0) == 1) ? 1 : -1);
	if (r == 0)
		return ((get_line(line, &str, ft_strlen(str), 1) == 1) ? 0 : -1);
	return (0);
}
