/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:36:05 by fmollenh          #+#    #+#             */
/*   Updated: 2022/07/14 12:09:32 by fmollenh         ###   ########.fr       */
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
		{
			printf("ERROR\nError while loading textures\n");
			return (1);
		}
		i++;
	}
	if (!t->ceil || !t->floor)
	{
		printf("ERROR\nError while loading floor- or ceiling-colors\n");
		return (1);
	}
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

int	check_f_c_string2(char *s, int i, int digit_count)
{
	int	j;

	if ((s[i] < '0' && s[i] != ' ' && s[i] != ',') || s[i] > '9')
		return (1);
	if (digit_count == 0 && s[i] == ',')
		return (1);
	if (digit_count > 0 && s[i] == ' ')
	{
		j = i;
		while (s[++j] != 0 && s[j] != ',')
		{
			if (s[j] != ' ')
				return (1);
		}
	}
	return (0);
}

int	check_f_c_string(char *s)
{
	int	i;
	int	digit_count;
	int	comma_count;

	i = -1;
	digit_count = 0;
	comma_count = 0;
	while (s[++i] != 0)
	{
		if (check_f_c_string2(s, i, digit_count) == 1)
			return (1);
		if (s[i] == ',')
		{
			digit_count = 0;
			comma_count++;
			if (comma_count > 2)
				return (1);
		}
		if (s[i] >= '0' && s[i] <= '9')
			digit_count++;
	}
	if (comma_count < 2 || (comma_count == 2 && digit_count == 0))
		return (1);
	return (0);
}
