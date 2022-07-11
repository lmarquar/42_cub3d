/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 09:17:11 by fmollenh          #+#    #+#             */
/*   Updated: 2021/08/13 21:37:48 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*wdest;
	char	*wsrc;
	int		i;

	if (dest == src)
		return (dest);
	i = 0;
	wdest = (char *)dest;
	wsrc = (char *)src;
	if (wsrc <= wdest)
	{
		while (++i <= (int) n)
			wdest[n - i] = wsrc[n - i];
	}
	else
	{
		while (n-- > 0)
		{
			wdest[i] = wsrc[i];
			i++;
		}
	}
	return (wdest);
}
