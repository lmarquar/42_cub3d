/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:29:28 by fmollenh          #+#    #+#             */
/*   Updated: 2021/08/11 09:33:08 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	prep_and_negativ(unsigned int n, int *i)
{
	i[0] = 1;
	i[1] = 1;
	i[2] = 0;
	while ((n / i[0]) >= 10)
	{
		i[0] = i[0] * 10;
		i[1]++;
	}
	return (n);
}

char	*ft_unitoa(unsigned int n)
{
	char	*new;
	int		i[3];

	n = prep_and_negativ(n, i);
	new = malloc((i[1] + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	while (i[1] != 0)
	{
		new[i[2]] = n / i[0] + 48;
		n = n - (n / i[0]) * i[0];
		i[0] = i[0] / 10;
		i[1]--;
		i[2]++;
	}
	new[i[2]] = '\0';
	return (new);
}
