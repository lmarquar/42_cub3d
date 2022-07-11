/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:36:05 by fmollenh          #+#    #+#             */
/*   Updated: 2022/07/11 16:36:07 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	textures_not_complete(t_textures *t)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!t->nswe[i])
			return (1);
		i++;
	}
	if (!t->ceil || !t->floor)
		return (1);
	return (0);
}

int	texture_valid_format(char *s)
{
	int	fd;

	fd = open(s, O_RDONLY);
	if (fd == -1)
	{
		printf("ERROR\nTexturefile %s couldn't be found\n", s);
		return (0);
	}
	close(fd);
	return (1);
}

char	*find_first_occurence(char *s, char *x)
{
	int		i;
	int		j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (x[j])
		{
			if (s[i] == x[j])
				break ;
			j++;
		}
		if (s[i] == x[j])
			break ;
		i++;
	}
	if (!s[i])
		return (NULL);
	if (!texture_valid_format(&s[i]))
		return (NULL);
	return (ft_strdup(&s[i]));
}
