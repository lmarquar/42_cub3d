/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:02:46 by fmollenh          #+#    #+#             */
/*   Updated: 2021/12/10 11:10:06 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_power(int nbr, int power)
{
	int	i;
	int	temp;

	i = 0;
	temp = nbr;
	while (++i < power)
		nbr = nbr * temp;
	return (nbr);
}
