/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 10:43:39 by fmollenh          #+#    #+#             */
/*   Updated: 2021/06/25 11:25:12 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;
	size_t	len;

	len = ft_strlen(s);
	dup = ft_calloc((len + 1), sizeof(char));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < (int) len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
