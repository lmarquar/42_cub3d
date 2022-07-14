/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utility.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:35:59 by fmollenh          #+#    #+#             */
/*   Updated: 2022/07/14 11:52:50 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	print_error_if_aready_exists(void *ptr, char *string)
{
	if (ptr != NULL)
	{
		printf("ERROR\n%s is set multiple times,", string);
		printf(" the first one will be used\n");
		return (1);
	}
	return (0);
}

void	textures_free_all(t_textures *t)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (t->nswe[i] != NULL)
			free(t->nswe[i]);
		i++;
	}
	if (t->ceil)
		free(t->ceil);
	if (t->floor)
		free(t->floor);
	free(t);
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
