/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 08:06:14 by fmollenh          #+#    #+#             */
/*   Updated: 2021/06/23 10:46:18 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i[2];
	size_t	lens1;

	if ((s1 == NULL) && (s2 == NULL))
		return (NULL);
	lens1 = ft_strlen(s1);
	new = malloc((lens1 + ft_strlen(s2) + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	i[0] = 0;
	i[1] = 0;
	while ((s2[i[1]]) || (i[0] < (int)lens1))
	{
		if (i[0] < (int)lens1)
			new[i[0]] = s1[i[0]];
		else
		{
			new[i[0]] = s2[i[1]];
			i[1]++;
		}
		i[0]++;
	}
	new[i[0]] = '\0';
	return (new);
}
