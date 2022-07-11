/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hori_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:35:44 by fmollenh          #+#    #+#             */
/*   Updated: 2022/07/11 16:35:45 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static
double	first_angle(t_data *data, double angle_d)
{
	int		wall_y;
	double	len_y;
	double	equ_x;

	wall_y = (int) data->player->y_calc + 1;
	len_y = 1 - (data->player->y_calc - (int) data->player->y_calc);
	while (1)
	{
		equ_x = data->player->x_calc + len_y / tan(degree_in_radiant(angle_d));
		if ((int) wall_y < 0 || (int) wall_y > data->map->map_size[0] - 1
			|| (int) equ_x < 0 || (int) equ_x > data->map->map_size[1] - 1)
			return (100000000);
		else if (data->map->map[wall_y][(int) equ_x] == '1')
		{
			data->rays->equ_x = equ_x - (int) equ_x;
			return (len_y / sin(degree_in_radiant(angle_d)));
		}
		wall_y = wall_y + 1;
		len_y = len_y + 1;
	}
}

static
double	second_angle(t_data *data, double angle_d)
{
	int		wall_y;
	double	len_y;
	double	equ_x;

	wall_y = (int) data->player->y_calc + 1;
	len_y = 1 - (data->player->y_calc - (int) data->player->y_calc);
	while (1)
	{
		equ_x = data->player->x_calc + len_y / tan(degree_in_radiant(angle_d));
		if ((int) wall_y < 0 || (int) wall_y > data->map->map_size[0] - 1
			|| (int) equ_x < 0 || (int) equ_x > data->map->map_size[1] - 1)
			return (100000000);
		else if (data->map->map[wall_y][(int) equ_x] == '1')
		{
			data->rays->equ_x = equ_x - (int) equ_x;
			return (len_y / sin(degree_in_radiant(angle_d)));
		}
		wall_y = wall_y + 1;
		len_y = len_y + 1;
	}
}

static
double	third_angle(t_data *data, double angle_d)
{
	int		wall_y;
	double	len_y;
	double	equ_x;

	wall_y = (int) data->player->y_calc - 1;
	len_y = (data->player->y_calc - (int) data->player->y_calc);
	while (1)
	{
		equ_x = data->player->x_calc - len_y / tan(degree_in_radiant(angle_d));
		if ((int) wall_y < 0 || (int) wall_y > data->map->map_size[0] - 1
			|| (int) equ_x < 0 || (int) equ_x > data->map->map_size[1] - 1)
			return (100000000);
		else if (data->map->map[wall_y][(int) equ_x] == '1')
		{
			data->rays->equ_x = equ_x - (int) equ_x;
			return (-len_y / sin(degree_in_radiant(angle_d)));
		}		
		wall_y = wall_y - 1;
		len_y = len_y + 1;
	}
}

static
double	forth_angle(t_data *data, double angle_d)
{
	int		wall_y;
	double	len_y;
	double	equ_x;

	wall_y = (int) data->player->y_calc - 1;
	len_y = (data->player->y_calc - (int) data->player->y_calc);
	while (1)
	{
		equ_x = data->player->x_calc - len_y / tan(degree_in_radiant(angle_d));
		if ((int) wall_y < 0 || (int) wall_y > data->map->map_size[0] - 1
			|| (int) equ_x < 0 || (int) equ_x > data->map->map_size[1] - 1)
			return (100000000);
		else if (data->map->map[wall_y][(int) equ_x] == '1')
		{
			data->rays->equ_x = equ_x - (int) equ_x;
			return (-len_y / sin(degree_in_radiant(angle_d)));
		}
		wall_y = wall_y - 1;
		len_y = len_y + 1;
	}
}

double	get_hori_len(t_data *data, double angle_d)
{
	double	len;

	if (angle_d == 0)
		len = 1000000000;
	else if (angle_d > 0 && angle_d < 90)
		len = first_angle(data, angle_d);
	else if (angle_d == 90)
		len = angle_90d(data);
	else if (angle_d > 90 && angle_d < 180)
		len = second_angle(data, angle_d);
	else if (angle_d == 180)
		len = 1000000000;
	else if (angle_d > 180 && angle_d < 270)
		len = third_angle(data, angle_d);
	else if (angle_d == 270)
		len = angle_270d(data);
	else
		len = forth_angle(data, angle_d);
	return (len);
}
