/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 09:26:15 by fmollenh          #+#    #+#             */
/*   Updated: 2021/06/22 10:49:34 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	out;
	int	i;
	int	neg;

	out = 0;
	i = 0;
	neg = 1;
	while ((str[i] == 32) || ((str[i] > 8) && (str[i] < 14)))
		i++;
	if ((str[i] == 45) || (str[i] == 43))
	{
		neg = 44 - str[i];
		i++;
	}
	if (str[i] == '\0')
		return (0);
	while ((str[i] >= 48) && (str[i] <= 57))
	{
		out = out * 10 + str[i] - 48;
		i++;
	}
	out = out * neg;
	return (out);
}
