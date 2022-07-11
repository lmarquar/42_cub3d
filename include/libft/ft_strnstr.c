/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 08:32:32 by fmollenh          #+#    #+#             */
/*   Updated: 2021/06/29 11:34:11 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i1;
	unsigned int	i2;

	if (s2[0] == '\0')
		return ((char *)s1);
	i1 = 0;
	i2 = 0;
	while ((s1[i1]) && (i1 < (unsigned int) n))
	{
		i2 = 0;
		while ((s1[i1 + i2] == s2[i2]) && (s2[i2])
			&& (i1 + i2 < (unsigned int) n))
			i2++;
		if (i2 == (unsigned int) ft_strlen(s2))
			return ((char *)(s1 + i1));
		i1++;
	}
	return (NULL);
}
