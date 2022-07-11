/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:45:30 by fmollenh          #+#    #+#             */
/*   Updated: 2021/06/29 11:34:34 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	int		i1;
	int		i2;

	if (s == NULL)
		return (NULL);
	sub = (char *) ft_calloc((len + 1), sizeof(char));
	if (sub == NULL)
		return (NULL);
	i1 = 0;
	i2 = 0;
	while (s[i1])
	{
		if ((i1 >= (int) start) && (i2 < (int) len))
		{
			sub[i2] = s[i1];
			i2++;
		}
		i1++;
	}
	sub[i2] = '\0';
	return (sub);
}
