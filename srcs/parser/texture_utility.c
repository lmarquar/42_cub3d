/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utility.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:35:59 by fmollenh          #+#    #+#             */
/*   Updated: 2022/07/11 16:36:00 by fmollenh         ###   ########.fr       */
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

int	check_text_behind(char *t, int *color)
{
	int	i;

	i = 0;
	while (t[i] < '0' || t[i] > '9')
		i++;
	if (t[i + 1] != 0)
	{
		free (color);
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
