/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:36:18 by fmollenh          #+#    #+#             */
/*   Updated: 2022/07/14 12:25:07 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static
int	gaps_in_wall(char **layout, int x, int y)
{
	int	res;

	res = 0;
	if (y == 0 || x == 0 || !layout[y] || !layout[y][x]
		|| (layout[y][x] != '0' && layout[y][x] != ' '))
		return (1);
	layout[y][x] = '1';
	if (layout[y - 1][x] != '1')
		res += gaps_in_wall(layout, x, y - 1);
	if (layout[y][x + 1] != '1')
		res += gaps_in_wall(layout, x + 1, y);
	if (layout[y + 1][x] != '1')
		res += gaps_in_wall(layout, x, y + 1);
	if (layout[y][x - 1] != '1')
		res += gaps_in_wall(layout, x - 1, y);
	if (layout[y - 1][x - 1] != '1')
		res += gaps_in_wall(layout, x - 1, y - 1);
	if (layout[y + 1][x + 1] != '1')
		res += gaps_in_wall(layout, x + 1, y + 1);
	if (layout[y + 1][x - 1] != '1')
		res += gaps_in_wall(layout, x - 1, y + 1);
	if (layout[y - 1][x + 1] != '1')
		res += gaps_in_wall(layout, x + 1, y - 1);
	return (res);
}

int	wrong_chars_map(char **layout)
{
	int	i;
	int	j;

	i = -1;
	while (layout[++i] != NULL)
	{
		j = -1;
		while (layout[i][++j] != 0)
		{
			if (layout[i][j] != '0' && layout[i][j] != '1' &&
				layout[i][j] != ' ' && layout[i][j] != 'N' &&
				layout[i][j] != 'E' && layout[i][j] != 'S' &&
				layout[i][j] != 'W')
				return (1);
		}
	}
	return (0);
}

int	layout_error(char **tmp_layout, int	*xy_start, int error)
{
	if (error == 1)
	{
		printf("ERROR\nMap contains other chars than 0, 1 or space\n");
		ft_arrdel(tmp_layout);
		free(xy_start);
		return (0);
	}
	if (error == 2)
	{
		printf("ERROR\nStart position not circled by ones\n");
		ft_arrdel(tmp_layout);
		free(xy_start);
		return (0);
	}
	return (0);
}

int	layout_correct(char **layout)
{
	int		*xy_start;
	char	**tmp_layout;

	xy_start = get_start_pos(layout);
	if (!xy_start)
	{
		printf("ERROR\nStartposition not found or found more than one\n");
		if (xy_start != NULL)
			free(xy_start);
		return (0);
	}
	tmp_layout = ft_arrdup((const char *const *)layout);
	tmp_layout[xy_start[1]][xy_start[0]] = '0';
	if (wrong_chars_map(tmp_layout) != 0)
		return (layout_error(tmp_layout, xy_start, 1));
	if (gaps_in_wall(tmp_layout, xy_start[0], xy_start[1]))
		return (layout_error(tmp_layout, xy_start, 2));
	free(xy_start);
	ft_arrdel(tmp_layout);
	return (1);
}
