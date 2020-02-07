/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 09:53:14 by mrouabeh          #+#    #+#             */
/*   Updated: 2020/02/02 08:07:12 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_puterror(char *str)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
}

void	exit_failure(char *error)
{
	ft_puterror(error);
	exit(EXIT_FAILURE);
}
