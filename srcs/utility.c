/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:34:00 by fmollenh          #+#    #+#             */
/*   Updated: 2022/07/11 16:34:53 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

double	degree_in_radiant(double degree)
{
	return (degree * 0.0174532925);
}

int	is_start_chr(char c)
{
	if (c == 'E' || c == 'S' || c == 'W' || c == 'N')
		return (1);
	return (0);
}

int	*get_start_pos(char **layout)
{
	int	*start;
	int	x;
	int	y;

	y = -1;
	start = NULL;
	while (layout[++y] != NULL)
	{
		x = -1;
		while (layout[y][++x])
		{
			if (layout[y][x] == 'N' || layout[y][x] == 'E' ||
				layout[y][x] == 'S' || layout[y][x] == 'W')
			{
				if (start != NULL)
					return (NULL);
				start = ft_calloc(2, sizeof(int));
				start[0] = x;
				start[1] = y;
			}	
		}		
	}
	return (start);
}
