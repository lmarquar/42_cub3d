/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarquar <leon.marquardt@gmx.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 17:53:58 by lmarquar          #+#    #+#             */
/*   Updated: 2021/07/13 23:55:26 by lmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	append2(char *line, char *buffer, int lc)
{
	int	bc;

	bc = 0;
	while (buffer[bc] && buffer[bc] != '\n')
		line[lc++] = buffer[bc++];
	if (buffer[bc] == '\n')
		line[lc] = buffer[bc++];
	if (buffer[bc - 1] == '\n')
	{
		lc = 0;
		while (buffer[bc])
			buffer[lc++] = buffer[bc++];
		while (buffer[lc])
			buffer[lc++] = '\0';
		return (1);
	}
	else if (!buffer[bc])
	{
		lc = 0;
		while (buffer[lc])
			buffer[lc++] = '\0';
		return (2);
	}
	return (0);
}

static int	append(char **line, char *buffer)
{
	int		lc;
	int		bc;
	char	*nline;

	lc = 0;
	while ((*line)[lc])
		lc++;
	bc = 0;
	while (buffer[bc] && buffer[bc] != '\n')
		bc++;
	if (buffer[bc] == '\n')
		bc++;
	nline = ft_calloc (bc + lc + 1, 1);
	if (!nline)
		return (-1);
	bc = -1;
	while (++bc < lc)
		nline[bc] = (*line)[bc];
	free(*line);
	*line = nline;
	return (append2(*line, buffer, lc));
}

static
int	createline(int fd, char *buffer, char **line)
{
	int	flag;

	flag = 2;
	while (flag > 1)
	{
		if (!buffer[0])
			flag = read(fd, buffer, BUFFER_SIZE);
		if (flag < 1 && !(**line))
			return (-2);
		if (flag > 0)
			flag = append(line, buffer);
	}
	return (flag);
}

char	*get_next_line(int fd)
{
	int			flag;
	char		*line;
	static char	*buffer;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1)
		return (NULL);
	line = ft_calloc(1, 1);
	if (!buffer)
		buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer || !line)
		return (NULL);
	flag = createline(fd, buffer, &line);
	if (flag <= 0)
	{
		free(buffer);
		buffer = NULL;
		if (flag == -2)
			free(line);
		if (flag < 0)
			line = NULL;
	}
	return (line);
}
