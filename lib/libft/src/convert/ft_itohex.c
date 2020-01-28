/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 08:13:24 by mrouabeh          #+#    #+#             */
/*   Updated: 2019/12/02 14:03:27 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(long l)
{
	int	size;

	size = 0;
	while (l != 0)
	{
		size++;
		l /= 16;
	}
	return (size);
}

static long	convert_neg(long l)
{
	unsigned long	max;

	max = 4294967296;
	return (max + l);
}

char		*ft_itohex(long l)
{
	char	*base;
	char	*dest;
	int		size;
	int		i;

	base = ft_strdup("0123456789abcdef");
	if (l == 0)
		return ("0");
	if (l < 0)
		l = convert_neg(l);
	size = get_size(l);
	if (!(dest = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	dest[size] = '\0';
	i = size - 1;
	while (l != 0)
	{
		dest[i--] = base[l % 16];
		l /= 16;
	}
	free(base);
	return (dest);
}
