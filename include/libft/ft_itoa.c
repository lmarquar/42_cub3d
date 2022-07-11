/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:29:28 by fmollenh          #+#    #+#             */
/*   Updated: 2021/12/19 10:57:36 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	prep_and_negativ(int n, int *i)
{
	i[0] = 1;
	i[1] = 1;
	i[2] = 0;
	if (n == -2147483648)
	{
		i[3] = 2;
		n = n + 2000000000;
		n = n * (-1);
		i[2] = 2;
	}
	else if (n < 0)
	{
		i[3] = 1;
		n = n * (-1);
		i[2] = 1;
	}
	else
		i[3] = 0;
	while ((n / i[0]) >= 10)
	{
		i[0] = i[0] * 10;
		i[1]++;
	}
	return (n);
}

char	*ft_itoa(int n)
{
	char	*new;
	int		i[4];

	n = prep_and_negativ(n, i);
	new = malloc((i[1] + 1 + i[3]) * sizeof(char));
	if (new == NULL)
		return (NULL);
	if ((i[3] == 1) || (i[3] == 2))
		new[0] = '-';
	if (i[3] == 2)
		new[1] = '2';
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
