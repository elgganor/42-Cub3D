/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 22:32:26 by mrouabeh          #+#    #+#             */
/*   Updated: 2019/12/02 14:03:15 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	if (str)
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' ||
				str[i] == '\n' || str[i] == '\r' || str[i] == '\f')
			i++;
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				sign = -1;
			i++;
		}
		while (str[i] != '\0' && ft_isdigit(str[i]))
		{
			res = res * 10 + (str[i] - '0');
			i++;
		}
	}
	return (res * sign);
}
