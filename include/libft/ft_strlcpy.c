/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:04:10 by fmollenh          #+#    #+#             */
/*   Updated: 2021/06/29 11:41:14 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	lensrc;
	int		i;

	if (!dest || !src)
		return (0);
	lensrc = 0;
	i = 0;
	while (src[i])
	{
		lensrc++;
		i++;
	}
	if (size == 0)
		return (lensrc);
	i = 0;
	while ((i < ((int)size - 1)) && (src[i]))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (lensrc);
}
