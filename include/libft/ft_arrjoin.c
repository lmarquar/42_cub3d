/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 09:58:21 by fmollenh          #+#    #+#             */
/*   Updated: 2022/04/08 10:34:39 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

char	**ft_arrjoin(const char *const *s1, const char *const *s2)
{
	char	**new;
	int		i;
	int		j;

	if ((s1 == NULL) && (s2 == NULL))
		return (NULL);
	new = malloc((ft_arrlen(s1) + ft_arrlen(s2) + 1) * sizeof(char *));
	if (new == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != NULL)
	{
		new[i] = ft_strdup(s1[i]);
		i++;
	}
	while (s2[j] != NULL)
	{
		new[i] = ft_strdup(s2[j]);
		i++;
		j++;
	}
	new[i] = NULL;
	return (new);
}
