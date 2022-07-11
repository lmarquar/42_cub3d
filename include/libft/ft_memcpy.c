/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 09:17:11 by fmollenh          #+#    #+#             */
/*   Updated: 2021/06/29 11:35:04 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*wdest;
	const char	*wsrc;
	int			i;

	if ((dest == src) || (n == 0))
		return (dest);
	if (!dest && !src)
		return (0);
	wdest = (char *)dest;
	wsrc = (const char *)src;
	i = 0;
	while (i < (int)n)
	{
		wdest[i] = wsrc[i];
		i++;
	}
	return (dest);
}
