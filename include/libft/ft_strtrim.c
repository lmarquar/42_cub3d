/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 08:37:02 by fmollenh          #+#    #+#             */
/*   Updated: 2021/06/23 10:45:28 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static int	ft_compare(char const s1, char const *set, int lenset)
{
	int	com;
	int	i;

	i = 0;
	com = 0;
	while (i < lenset)
	{
		if (s1 == set[i])
			com = 1;
		i++;
	}
	return (com);
}

static int	ft_forward(char const *s1, char const *set, char *new)
{
	int		i1;
	int		i2;
	size_t	lenset;
	size_t	lens1;

	lens1 = ft_strlen(s1);
	lenset = ft_strlen(set);
	i1 = 0;
	i2 = 0;
	while ((i1 < (int) lens1) && (ft_compare(s1[i1], set, lenset) == 1))
	{
		i1++;
		i2++;
	}
	i1 = 0;
	while (i2 < (int) lens1)
	{
		new[i1] = s1[i2];
		i1++;
		i2++;
	}
	return (i1);
}

static int	ft_backwards(char const *s1, char const *set)
{
	int		i1;
	int		i2;
	size_t	lenset;
	size_t	lens1;

	lens1 = ft_strlen(s1);
	lenset = ft_strlen(set);
	i1 = lens1 - 1;
	i2 = 0;
	while ((i1 >= 0) && (ft_compare(s1[i1], set, lenset) == 1))
	{
		i1--;
		i2++;
	}
	return (i2);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i1;
	int		i2;
	size_t	lens1;
	char	*new;

	if (s1 == NULL)
		return (NULL);
	lens1 = ft_strlen(s1);
	new = malloc((lens1 + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	i1 = ft_forward(s1, set, new);
	if (i1 != 0)
	{
		i2 = ft_backwards(s1, set);
		new[lens1 - (lens1 - i1) - i2] = '\0';
	}
	else
		new[0] = '\0';
	return (new);
}
