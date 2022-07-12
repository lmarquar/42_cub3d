/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:36:15 by fmollenh          #+#    #+#             */
/*   Updated: 2022/07/12 11:53:36 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	all_ones_and_spaces(char *line)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (line[i] == '1' || line[i] == ' ' || line[i] == '0')
	{
		if (line[i] == '1' || line[i] == '0')
			check++;
		i++;
	}
	if (i == 0 || check == 0 || line[i] != 0)
		return (0);
	else
		return (1);
}

char	*get_line_for_layout(int fd)
{
	char	*line;

	line = gnl_no_nl(fd);
	while (line && !all_ones_and_spaces(line))
	{
		free(line);
		line = gnl_no_nl(fd);
	}
	return (line);
}

char	**load_layout(int fd)
{
	char	**res;
	char	*line;
	int		i;

	line = get_line_for_layout(fd);
	res = ft_calloc(200, sizeof(char *));
	i = 0;
	while (line && ft_strchr(line, '1'))
	{
		res[i] = line;
		line = gnl_no_nl(fd);
		i++;
	}
	if (line || !layout_correct(res))
	{
		if (line)
		{
			free(line);
			printf("ERROR\nMapfile should end after maplayout\n");
		}
		ft_arrdel(res);
		res = NULL;
	}
	return (res);
}
