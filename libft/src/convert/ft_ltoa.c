/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 22:53:49 by mrouabeh          #+#    #+#             */
/*   Updated: 2019/12/02 14:03:37 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(long n)
{
	int	size;

	size = 0;
	if (n < 0)
	{
		size++;
		n = -n;
	}
	while (n >= 10)
	{
		size++;
		n /= 10;
	}
	return (size + 1);
}

char		*ft_ltoa(long n)
{
	int		size;
	int		i;
	char	*dest;

	if (n < -9223372036854775807)
		return ("-9223372036854775808");
	size = get_size(n);
	if (!(dest = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = size - 1;
	dest[size] = '\0';
	if (n < 0)
	{
		dest[0] = '-';
		n = -n;
	}
	while (n >= 10)
	{
		dest[i--] = n % 10 + '0';
		n /= 10;
	}
	dest[i] = n % 10 + '0';
	return (dest);
}
