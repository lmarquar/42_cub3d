/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 10:43:39 by fmollenh          #+#    #+#             */
/*   Updated: 2022/04/10 11:39:44 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

char	*ft_strdupn(const char *s, size_t n)
{
	char	*dup;
	int		i;

	dup = ft_calloc((n + 1), sizeof(char));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < (int) n)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
