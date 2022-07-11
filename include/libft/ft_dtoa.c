/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:30:43 by fmollenh          #+#    #+#             */
/*   Updated: 2022/01/20 11:08:23 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dota2(char **string, int n, double d)
{
	if (d < 0)
	{
		string[2] = ft_strjoin("-", ft_itoa(n));
		string[1] = ft_strjoin(string[2], ".");
		free(string[2]);
	}
	else
		string[1] = ft_strjoin(ft_itoa(n), ".");
}

char	*ft_dtoa(double d)
{
	double	w_d;
	int		n;
	double	temp;
	char	*string[3];

	w_d = d;
	if (d < 0)
		w_d = w_d * -1;
	n = w_d;
	temp = w_d - n;
	ft_dota2(string, n, d);
	temp = temp * 10000000;
	n = temp;
	string[0] = ft_strjoin(string[1], ft_itoa(n));
	free (string[1]);
	n = ft_strlen(string[0]);
	while (string[0][--n] == '0' || n == 0)
		string[0][n] = '\0';
	return (string[0]);
}
