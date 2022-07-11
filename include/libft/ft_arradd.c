/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 10:37:13 by fmollenh          #+#    #+#             */
/*   Updated: 2022/04/10 11:42:22 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

char	**ft_arradd(const char *const *s1, const char *s2)
{
	char	**new;
	int		i;

	if ((s1 == NULL) && (s2 == NULL))
		return (NULL);
	new = malloc((ft_arrlen(s1) + 2) * sizeof(char *));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != NULL)
	{
		new[i] = ft_strdup(s1[i]);
		i++;
	}
	new[i++] = ft_strdup(s2);
	new[i] = NULL;
	return (new);
}
