/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:36:12 by fmollenh          #+#    #+#             */
/*   Updated: 2022/07/11 16:36:13 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parser_free_all(t_parser *parser)
{
	if (parser->textures)
		textures_free_all(parser->textures);
	if (parser->layout)
		ft_arrdel(parser->layout);
	free(parser);
}

void	arr_max_xy(int (*dest)[], char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i] != NULL)
	{
		j = 0;
		while (arr[i][j] != 0)
			j++;
		if (j > (*dest)[1])
			(*dest)[1] = j + 1;
		i++;
	}
	(*dest)[0] = i + 1;
}

int	parse2(t_parser *parser, char *input_file)
{
	int	fd;

	if (!parser->textures)
	{
		free(parser);
		return (1);
	}
	fd = open(input_file, O_RDONLY);
	parser->layout = load_layout(fd);
	if (!parser->textures || !parser->layout)
	{
		parser_free_all(parser);
		return (1);
	}
	arr_max_xy(&(parser->xy_max), parser->layout);
	return (0);
}

t_parser	*parse(char *input_file)
{
	t_parser	*parser;
	int			fd;

	parser = ft_calloc(1, sizeof(t_parser));
	fd = open(input_file, O_RDONLY);
	if (fd == -1)
	{
		printf("ERROR\nInput-file not found\n");
		free (parser);
		return (NULL);
	}
	parser->textures = load_textures(fd);
	if (!parser->textures)
	{
		free(parser);
		return (NULL);
	}
	close(fd);
	if (parse2(parser, input_file) != 0)
		return (NULL);
	return (parser);
}
