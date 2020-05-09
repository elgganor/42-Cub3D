/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 17:43:26 by mrouabeh          #+#    #+#             */
/*   Updated: 2019/12/02 14:03:42 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				get_size(unsigned long l)
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

static unsigned long	convert_neg(long l)
{
	unsigned long max;

	max = ULONG_MAX;
	return (max + l + 1);
}

char					*ft_ltohex(long l)
{
	unsigned long	n;
	char			*base;
	char			*dest;
	int				size;
	int				i;

	base = ft_strdup("0123456789abcdef");
	if (l == 0)
		return ("0");
	if (l < 0)
		n = convert_neg(l);
	else
		n = l;
	size = get_size(n);
	if (!(dest = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	dest[size] = '\0';
	i = size - 1;
	while (n != 0)
	{
		dest[i--] = base[n % 16];
		n /= 16;
	}
	free(base);
	return (dest);
}
