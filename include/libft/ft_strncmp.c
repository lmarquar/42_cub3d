/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 15:29:24 by fmollenh          #+#    #+#             */
/*   Updated: 2021/06/15 09:56:13 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (str1[i] && str2[i] && (str1[i] == str2[i]) && (i < (int)n - 1))
		i++;
	return ((unsigned char) str1[i] - (unsigned char) str2[i]);
}
