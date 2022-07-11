/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_angles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:35:10 by fmollenh          #+#    #+#             */
/*   Updated: 2022/07/11 16:35:11 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

double	angle_0d(t_data *data)
{
	int		wall_x;
	double	len_x;

	wall_x = (int) data->player->x_calc + 1;
	len_x = 1 - (data->player->x_calc - (int) data->player->x_calc);
	while (1)
	{
		if (data->map->map[(int) data->player->y_calc][wall_x] == '1')
			return (len_x);
		wall_x = wall_x + 1;
		len_x = len_x + 1;
	}
}

double	angle_90d(t_data *data)
{
	int		wall_y;
	double	len_y;

	wall_y = (int) data->player->y_calc + 1;
	len_y = 1 - (data->player->y_calc - (int) data->player->y_calc);
	while (1)
	{
		if (data->map->map[wall_y][(int) data->player->x_calc] == '1')
			return (len_y);
		wall_y = wall_y + 1;
		len_y = len_y + 1;
	}
}

double	angle_180d(t_data *data)
{
	int		wall_x;
	double	len_x;

	wall_x = (int) data->player->x_calc - 1;
	len_x = (data->player->x_calc - (int) data->player->x_calc);
	while (1)
	{
		if (data->map->map[(int) data->player->y_calc][wall_x] == '1')
			return (len_x);
		wall_x = wall_x - 1;
		len_x = len_x + 1;
	}
}

double	angle_270d(t_data *data)
{	
	int		wall_y;
	double	len_y;

	wall_y = (int) data->player->y_calc - 1;
	len_y = (data->player->y_calc - (int) data->player->y_calc);
	while (1)
	{
		if (data->map->map[wall_y][(int) data->player->x_calc] == '1')
			return (len_y);
		wall_y = wall_y - 1;
		len_y = len_y + 1;
	}
}
