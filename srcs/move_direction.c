/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_direction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:35:20 by fmollenh          #+#    #+#             */
/*   Updated: 2022/07/11 16:35:22 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	move_forward(t_data *data)
{
	int	x;
	int	y;

	x = (int)(data->player->x_calc + (cos(degree_in_radiant
					(data->player->direction_d)) * 0.4));
	y = (int)(data->player->y_calc + (sin(degree_in_radiant
					(data->player->direction_d)) * 0.4));
	if (data->map->map[y][x] == '1' || (x != data->player->x_calc
			&& y != data->player->y_calc && data->map->map[y]
				[(int)data->player->x_calc] == '1'
				&& data->map->map[(int)data->player->y_calc][x] == '1'))
		return (0);
	data->player->x_calc = data->player->x_calc + (cos
			(degree_in_radiant(data->player->direction_d)) * 0.2);
	data->player->y_calc = data->player->y_calc + (sin
			(degree_in_radiant(data->player->direction_d)) * 0.2);
	get_new_xy_pos(data);
	return (0);
}

int	move_backward(t_data *data)
{	
	int	x;
	int	y;

	x = (int)(data->player->x_calc - (cos(degree_in_radiant
					(data->player->direction_d)) * 0.4));
	y = (int)(data->player->y_calc - (sin(degree_in_radiant
					(data->player->direction_d)) * 0.4));
	if (data->map->map[y][x] == '1')
		return (0);
	data->player->x_calc = data->player->x_calc - (cos
			(degree_in_radiant(data->player->direction_d)) * 0.2);
	data->player->y_calc = data->player->y_calc - (sin
			(degree_in_radiant(data->player->direction_d)) * 0.2);
	get_new_xy_pos(data);
	return (0);
}

int	move_left(t_data *data)
{	
	int			x;
	int			y;
	t_player	*p;

	p = data->player;
	x = (int)(p->x_calc + (sin(degree_in_radiant(p->direction_d)) * 0.4));
	y = (int)(p->y_calc + (-cos(degree_in_radiant(p->direction_d)) * 0.4));
	if (data->map->map[y][x] == '1')
		return (0);
	p->x_calc = p->x_calc + (sin(degree_in_radiant(p->direction_d)) * 0.2);
	p->y_calc = p->y_calc + (-cos(degree_in_radiant(p->direction_d)) * 0.2);
	get_new_xy_pos(data);
	return (0);
}

int	move_right(t_data *data)
{
	int			x;
	int			y;
	t_player	*p;

	p = data->player;
	x = (int)(p->x_calc + (-sin(degree_in_radiant(p->direction_d)) * 0.4));
	y = (int)(p->y_calc + (cos(degree_in_radiant(p->direction_d)) * 0.4));
	if (data->map->map[y][x] == '1')
		return (0);
	p->x_calc = p->x_calc + (-sin(degree_in_radiant(p->direction_d)) * 0.2);
	p->y_calc = p->y_calc + (cos(degree_in_radiant(p->direction_d)) * 0.2);
	get_new_xy_pos(data);
	return (0);
}
