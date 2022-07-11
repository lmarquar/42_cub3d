/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:35:27 by fmollenh          #+#    #+#             */
/*   Updated: 2022/07/11 16:35:29 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	create_map_array(t_data *data)
{
	int		i;
	t_map	*map;

	map = data->map;
	map->map = malloc((map->map_size[0] + 1) * sizeof(char *));
	i = 0;
	while (i < map->map_size[0])
	{
		map->map[i] = ft_calloc(map->map_size[1] + 1, sizeof(char));
		ft_strlcpy(map->map[i], data->parser->layout[i], map->map_size[1]);
		i++;
	}
	map->map[i] = NULL;
	i = 0;
}

void	get_map_size(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->parser->layout[i] != NULL)
	{
		j = 0;
		while (data->parser->layout[i][j] != 0)
			j++;
		if (j > data->map->map_size[1])
			data->map->map_size[1] = j + 1;
		i++;
	}
	data->map->map_size[0] = i + 1;
}

void	init_minimap(t_data *data)
{
	data->map = ft_calloc(1, sizeof(t_map));
	data->player = ft_calloc(1, sizeof(t_player));
	data->player->radius = 2 * data->pixel_scale;
	data->player->direction_len = 5 * data->pixel_scale;
	data->map->wall_size = 10 * data->pixel_scale;
	data->map->minimap_size = data->graphic->img_y / 4;
	get_map_size(data);
	create_map_array(data);
}

int	player_init_start_orient(t_player *player, char o)
{
	if (o == 'E')
		player->direction_d = 0;
	if (o == 'S')
		player->direction_d = 90;
	if (o == 'W')
		player->direction_d = 180;
	if (o == 'N')
		player->direction_d = 270;
	return (0);
}

int	init_player(t_data *data)
{
	int		i;
	int		j;
	t_map	*map;

	i = 0;
	j = 0;
	map = data->map;
	while (map->map[i][j] != 0 && !is_start_chr(map->map[i][j]))
	{
		while (map->map[i][j] != 0 && !is_start_chr(map->map[i][j]))
			j++;
		if (!is_start_chr(map->map[i][j]))
		{
			i++;
			j = 0;
		}
	}
	data->player->x_calc = j + 0.5;
	data->player->y_calc = i + 0.5;
	player_init_start_orient(data->player, map->map[i][j]);
	get_new_xy_pos(data);
	return (0);
}
