/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_perp_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:35:40 by fmollenh          #+#    #+#             */
/*   Updated: 2022/07/11 16:35:42 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static
double	first_angle(t_data *data, double angle_d)
{
	int		wall_x;
	double	len_x;
	double	equ_y;

	wall_x = (int) data->player->x_calc + 1;
	len_x = 1 - (data->player->x_calc - (int) data->player->x_calc);
	while (1)
	{
		equ_y = data->player->y_calc + tan(degree_in_radiant(angle_d)) * len_x;
		if ((int) wall_x < 0 || (int) wall_x > data->map->map_size[1] - 1
			|| equ_y < 0 || equ_y > data->map->map_size[0] - 1)
			return (10000000);
		else if (data->map->map[(int) equ_y][wall_x] == '1')
		{
			data->rays->equ_y = equ_y - (int) equ_y;
			return (len_x / cos(degree_in_radiant(angle_d)));
		}
		wall_x = wall_x + 1;
		len_x = len_x + 1;
	}
}

static
double	second_angle(t_data *data, double angle_d)
{
	int		wall_x;
	double	len_x;
	double	equ_y;

	wall_x = (int) data->player->x_calc - 1;
	len_x = (data->player->x_calc - (int) data->player->x_calc);
	while (1)
	{
		equ_y = data->player->y_calc - tan(degree_in_radiant(angle_d)) * len_x;
		if ((int) wall_x < 0 || (int) wall_x > data->map->map_size[1] - 1
			|| equ_y < 0 || equ_y > data->map->map_size[0] - 1)
			return (10000000);
		else if (data->map->map[(int) equ_y][wall_x] == '1')
		{
			data->rays->equ_y = equ_y - (int) equ_y;
			return (-len_x / cos(degree_in_radiant(angle_d)));
		}
		wall_x = wall_x - 1;
		len_x = len_x + 1;
	}
}

static
double	third_angle(t_data *data, double angle_d)
{
	int		wall_x;
	double	len_x;
	double	equ_y;

	wall_x = (int) data->player->x_calc - 1;
	len_x = (data->player->x_calc - (int) data->player->x_calc);
	while (1)
	{
		equ_y = data->player->y_calc - tan(degree_in_radiant(angle_d)) * len_x;
		if ((int) wall_x < 0 || (int) wall_x > data->map->map_size[1] - 1
			|| equ_y < 0 || equ_y > data->map->map_size[0] - 1)
			return (10000000);
		else if (data->map->map[(int) equ_y][wall_x] == '1')
		{
			data->rays->equ_y = equ_y - (int) equ_y;
			return (-len_x / cos(degree_in_radiant(angle_d)));
		}
		wall_x = wall_x - 1;
		len_x = len_x + 1;
	}
}

static
double	forth_angle(t_data *data, double angle_d)
{
	int		wall_x;
	double	len_x;
	double	equ_y;

	wall_x = (int) data->player->x_calc + 1;
	len_x = 1 - (data->player->x_calc - (int) data->player->x_calc);
	while (1)
	{
		equ_y = data->player->y_calc + tan(degree_in_radiant(angle_d)) * len_x;
		if ((int) wall_x < 0 || (int) wall_x > data->map->map_size[1] - 1
			|| equ_y < 0 || equ_y > data->map->map_size[0] - 1)
			return (10000000);
		else if (data->map->map[(int) equ_y][wall_x] == '1')
		{
			data->rays->equ_y = equ_y - (int) equ_y;
			return (len_x / cos(degree_in_radiant(angle_d)));
		}
		wall_x = wall_x + 1;
		len_x = len_x + 1;
	}
}

double	get_perp_len(t_data *data, double angle_d)
{
	double	len;

	if (angle_d == 0)
		len = angle_0d(data);
	else if (angle_d >= 0 && angle_d < 90)
		len = first_angle(data, angle_d);
	else if (angle_d == 90)
		len = 1000000000;
	else if (angle_d > 90 && angle_d < 180)
		len = second_angle(data, angle_d);
	else if (angle_d == 180)
		len = angle_180d(data);
	else if (angle_d > 180 && angle_d < 270)
		len = third_angle(data, angle_d);
	else if (angle_d == 270)
		len = 1000000000;
	else
		len = forth_angle(data, angle_d);
	return (len);
}
