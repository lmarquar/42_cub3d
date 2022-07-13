/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_load.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarquar <lmarquar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:36:02 by fmollenh          #+#    #+#             */
/*   Updated: 2022/07/13 15:43:12 by lmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	*get_floor_or_cealing(char *s)
{
	int		ci;
	int		*color;
	char	*t;
	int		x;

	color = ft_calloc(5, sizeof(int));
	t = s;
	while (*t < '0' || *t > '9')
		t++;
	ci = 0;
	while (ci < 3)
	{
		x = ft_atoi(t);
		if (x > 255 || x < 0)
		{
			free(color);
			printf("ERROR\nColorvalue too big in line: %s\n", s);
			return (NULL);
		}
		color[ci] = x;
		if (ci < 2)
			t = ft_strchr(t, ',') + 1;
		ci++;
	}
	if (check_text_behind(t, color) != 0)
		return (NULL);
	return (color);
}

void	check_string2(t_textures *t, char *string, int i)
{
	if (!ft_strncmp(&string[i], "NO ", 3))
	{
		if (!print_error_if_aready_exists(t->nswe[0], "NO-texture"))
			t->nswe[0] = find_first_occurence(string, "./");
	}
	else if (!ft_strncmp(&string[i], "EA ", 3))
	{
		if (!print_error_if_aready_exists(t->nswe[1], "EA-texture"))
			t->nswe[1] = find_first_occurence(string, "./");
	}
	else if (!ft_strncmp(&string[i], "SO ", 3))
	{
		if (!print_error_if_aready_exists(t->nswe[2], "SO-texture"))
			t->nswe[2] = find_first_occurence(string, "./");
	}
	else if (!ft_strncmp(&string[i], "WE ", 3))
	{
		if (!print_error_if_aready_exists(t->nswe[3], "WE-texture"))
			t->nswe[3] = find_first_occurence(string, "./");
	}
}

void	check_string(t_textures *t, char *string)
{
	int	i;

	i = 0;
	while (string[i] == ' ')
		i++;
	if (!ft_strncmp(&string[i], "F ", 2))
	{
		if (!print_error_if_aready_exists(t->floor, "Floorcolor"))
			t->floor = get_floor_or_cealing(string);
	}
	else if (!ft_strncmp(&string[i], "C ", 2))
	{
		if (!print_error_if_aready_exists(t->ceil, "Ceilingcolor"))
			t->ceil = get_floor_or_cealing(string);
	}
	else
		check_string2(t, string, i);
	free(string);
}

t_textures	*load_textures(int fd)
{
	t_textures	*t;
	char		*tmp;

	t = ft_calloc(1, sizeof(t_textures));
	t->nswe[4] = 0;
	tmp = gnl_no_nl(fd);
	while (tmp)
	{
		check_string(t, tmp);
		tmp = gnl_no_nl(fd);
	}
	free (tmp);
	if (textures_not_complete(t))
	{
		printf("ERROR\nError while loading textures\n");
		textures_free_all(t);
		return (NULL);
	}
	return (t);
}
