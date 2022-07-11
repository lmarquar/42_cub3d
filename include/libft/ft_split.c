/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 13:16:49 by fmollenh          #+#    #+#             */
/*   Updated: 2021/06/25 15:44:59 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static int	ft_strnbr(const char *s, char c)
{
	int		i;
	int		strlen;
	int		strnbr;

	i = 0;
	strnbr = 0;
	if (c == 0)
		return (1);
	strlen = ft_strlen(s);
	while (s[i])
	{
		if ((s[strlen - 1] == c) && (s[strlen - 2] == c))
		{
			if (((s[i] != c) && (s[i - 1] == c) && (i > 0))
				|| ((s[i] != c) && (i == 0)))
				strnbr++;
		}
		else
		{
			if ((s[i] == c) && (s[i - 1] != c) && (s[i + 1]) && (i))
				strnbr++;
		}
		i++;
	}
	return (strnbr + 1);
}

static void	ft_fillnew(const char *s, char c, char **new)
{
	int		i1;
	int		i2;
	int		start;

	i1 = 0;
	i2 = 0;
	start = 0;
	while (s[i1])
	{
		while (s[i1] == c && s[i1])
			i1++;
		start = i1;
		while (s[i1] != c && s[i1])
			i1++;
		if (s[i1 - 1] != c)
			new[i2] = ft_substr(s, start, i1 - start);
		i2++;
	}
	new[i2] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		strnbr;

	if (s == NULL)
		return (NULL);
	strnbr = ft_strnbr(s, c);
	new = ft_calloc((strnbr + 1), sizeof(char *));
	if (new == NULL)
		return (NULL);
	ft_fillnew(s, c, new);
	return (new);
}
