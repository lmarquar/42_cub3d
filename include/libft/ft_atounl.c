/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atounl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 09:26:15 by fmollenh          #+#    #+#             */
/*   Updated: 2022/02/15 16:48:34 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_atounl(const char *str)
{
	unsigned long	out;
	int				i;

	out = 0;
	i = 0;
	while ((str[i] == 32) || ((str[i] > 8) && (str[i] < 14)))
		i++;
	if (str[i] == '\0')
		return (0);
	while ((str[i] >= 48) && (str[i] <= 57))
	{
		out = out * 10 + str[i] - 48;
		i++;
	}
	return (out);
}
