/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:59:34 by fmollenh          #+#    #+#             */
/*   Updated: 2021/05/28 09:45:34 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strchr(const char *s, int c)
{
	int			i;
	const char	*p;

	i = 0;
	while (s[i] && (s[i] != c))
		i++;
	if (s[i] == c)
		p = s + i;
	else
		p = NULL;
	return ((char *)p);
}
