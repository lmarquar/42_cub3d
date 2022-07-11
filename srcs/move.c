/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:35:17 by fmollenh          #+#    #+#             */
/*   Updated: 2022/07/11 16:35:19 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	get_new_xy_pos(t_data *data)
{
	data->player->x_position = data->player->x_calc * data->map->wall_size;
	data->player->y_position = data->player->y_calc * data->map->wall_size;
	return (0);
}

int	move(int key, void *param)
{
	t_data	*data;

	data = (t_data *) param;
	if (key == ARROW_UP || key == KEY_W)
		move_forward(data);
	if (key == ARROW_DOWN || key == KEY_S)
		move_backward(data);
	if (key == KEY_A)
		move_left(data);
	if (key == KEY_D)
		move_right(data);
	if (key == ARROW_LEFT)
	{
		data->player->direction_d = data->player->direction_d - 5;
		if (data->player->direction_d < 0)
			data->player->direction_d = 360 + data->player->direction_d;
	}
	if (key == ARROW_RIGHT)
	{
		data->player->direction_d = data->player->direction_d + 5;
		if (data->player->direction_d >= 360)
			data->player->direction_d = data->player->direction_d - 360;
	}
	create_image(data);
	return (0);
}
