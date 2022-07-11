/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 09:17:11 by fmollenh          #+#    #+#             */
/*   Updated: 2021/06/29 11:34:54 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	int					i;
	unsigned char		*uns_dest;
	const unsigned char	*uns_src;
	unsigned char		uns_c;

	i = 0;
	uns_dest = (unsigned char *) dest;
	uns_src = (const unsigned char *) src;
	uns_c = (const char) c;
	while (i < (int) n)
	{
		uns_dest[i] = uns_src[i];
		if (uns_src[i] == uns_c)
			return (dest + i + 1);
		i++;
	}
	return (0);
}
