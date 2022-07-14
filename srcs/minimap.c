/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarquar <lmarquar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:35:23 by fmollenh          #+#    #+#             */
/*   Updated: 2022/07/14 15:47:27 by lmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	is_ray(int row, int col, t_data *data)
{
	int	pos;

	pos = data->map->minimap_size / 2;
	if ((row > ((int)(data->player->direction_ratio * (double)
				((col - pos))) + pos - 2) && row < ((int)
			(data->player->direction_ratio * (double)
				((col - pos))) + pos + 2)) || (col > ((int)
			((double)((row - pos) + 1) / data->player->direction_ratio)
			+ pos - 2) && col < ((int)((double)((row - pos) + 1)
			/ data->player->direction_ratio) + pos + 2)))
	{
		if (data->player->direction_d >= 0 && data->player->direction_d < 90
			&& row >= pos && col >= pos)
			return (1);
		if (data->player->direction_d >= 90 && data->player->direction_d < 180
			&& row >= pos && col <= pos)
			return (1);
		if (data->player->direction_d >= 180 && data->player->direction_d < 270
			&& row <= pos && col <= pos)
			return (1);
		if (data->player->direction_d >= 270 && data->player->direction_d < 360
			&& row <= pos && col >= pos)
			return (1);
	}
	return (0);
}

int	is_player(t_pixel pixel, t_data *data)
{
	int	lower_limit;
	int	upper_limit;

	lower_limit = (data->map->minimap_size / 2) - (sqrt(pow
				(data->player->radius, 2) - pow(pixel.row
					- (data->map->minimap_size / 2), 2)));
	upper_limit = (data->map->minimap_size / 2) + (sqrt(pow
				(data->player->radius, 2) - pow(pixel.row
					- (data->map->minimap_size / 2), 2)));
	if (lower_limit < pixel.col && pixel.col < upper_limit)
		return (1);
	else
		return (0);
}

void	minimap_put_pixel(t_data *data, t_pixel pixel, int zoom)
{
	t_player	*p;
	int			x;
	int			y;

	p = data->player;
	x = (p->x_calc - zoom) + (((double)(pixel.col + 1) / (double)
				data->map->minimap_size) * (2 * zoom));
	y = (p->y_calc - zoom) + (((double)(pixel.row + 1) / (double)
				data->map->minimap_size) * (2 * zoom));
	if (x < 0 || y < 0 || x + 1 >= data->map->map_size[1]
		|| y + 1 >= data->map->map_size[0])
	{
		pixel.color = create_color(0, 0, 0);
		pixel_color(data, &pixel);
		return ;
	}
	if (data->map->map[y][x] == '1')
		pixel.color = create_color(0, 0, 0);
	else if (is_player(pixel, data))
		pixel.color = create_color(0, 0, 220);
	else if (is_ray(pixel.row, pixel.col, data) == 1)
		pixel.color = create_color(255, 100, 100);
	else
		pixel.color = create_color(0, 255, 255);
	pixel_color(data, &pixel);
}

void	create_minimap(t_data *data)
{
	double		zoom;
	t_player	*p;
	t_pixel		pixel;

	p = data->player;
	p->direction_ratio = (sin(degree_in_radiant(p->direction_d))
			* p->direction_len) / (cos(degree_in_radiant(p->direction_d))
			* p->direction_len);
	pixel.row = -1;
	zoom = 8;
	while (++pixel.row < data->map->minimap_size)
	{
		pixel.col = -1;
		while (++pixel.col < data->map->minimap_size)
		{
			minimap_put_pixel(data, pixel, zoom);
		}
	}
}
