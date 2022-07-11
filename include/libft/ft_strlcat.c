/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:36:37 by fmollenh          #+#    #+#             */
/*   Updated: 2021/06/22 11:00:21 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static	int	ft_dest_err(char *dest, size_t size)
{
	int	i;

	i = 0;
	while (i <= (int) size)
	{
		if (dest[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	lensrc;
	size_t	lendest;
	int		i;
	int		j;
	int		dest_err;

	dest_err = ft_dest_err(dest, size);
	lensrc = ft_strlen(src);
	if (dest_err == 1)
		lendest = size;
	else
		lendest = ft_strlen(dest);
	i = (int)lendest;
	j = 0;
	if (size <= lendest)
		return (size + lensrc);
	j = 0;
	while (i < (int)size - 1 && src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (lensrc + lendest);
}
