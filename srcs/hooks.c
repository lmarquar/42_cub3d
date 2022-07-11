/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:35:37 by fmollenh          #+#    #+#             */
/*   Updated: 2022/07/11 16:35:38 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	move_in_dir(t_data *data, t_input *input)
{
	if (input->up)
		move(ARROW_UP, data);
	else if (input->down)
		move(ARROW_DOWN, data);
	else if (input->left)
		move(ARROW_LEFT, data);
	else if (input->right)
		move(ARROW_RIGHT, data);
	else if (input->a)
		move(KEY_A, data);
	else if (input->d)
		move(KEY_D, data);
	else if (input->w)
		move(KEY_W, data);
	else if (input->s)
		move(KEY_S, data);
	else if (input->esc)
		close_win(data);
	return (0);
}

int	loop_hook(void *param)
{
	t_data			*data;
	t_input			*input;

	data = (t_data *) param;
	input = data->input;
	data->loop = data->loop + 1;
	if (!(data->loop % 5000))
		move_in_dir(data, input);
	return (0);
}

int	key_hook_press(int key, void *param)
{
	t_input	*input;

	input = (t_input *) param;
	if (key == ESC)
		input->esc = 1;
	if (key == ARROW_UP)
		input->up = 1;
	else if (key == ARROW_DOWN)
		input->down = 1;
	else if (key == ARROW_LEFT)
		input->left = 1;
	else if (key == ARROW_RIGHT)
		input->right = 1;
	else if (key == KEY_A)
		input->a = 1;
	else if (key == KEY_D)
		input->d = 1;
	else if (key == KEY_W)
		input->w = 1;
	else if (key == KEY_S)
		input->s = 1;
	return (0);
}

int	key_hook_release(int key, void *param)
{
	t_input	*input;

	input = (t_input *) param;
	if (key == ESC)
		input->esc = 0;
	else if (key == ARROW_UP)
		input->up = 0;
	else if (key == ARROW_DOWN)
		input->down = 0;
	else if (key == ARROW_LEFT)
		input->left = 0;
	else if (key == ARROW_RIGHT)
		input->right = 0;
	else if (key == KEY_A)
		input->a = 0;
	else if (key == KEY_D)
		input->d = 0;
	else if (key == KEY_W)
		input->w = 0;
	else if (key == KEY_S)
		input->s = 0;
	return (0);
}

int	close_win(void *param)
{
	t_data	*data;

	data = (t_data *) param;
	mlx_destroy_image(data->graphic->mlx_ptr, data->graphic->img_ptr);
	mlx_destroy_image(data->graphic->mlx_ptr, data->tex->north->img_ptr);
	mlx_destroy_image(data->graphic->mlx_ptr, data->tex->east->img_ptr);
	mlx_destroy_image(data->graphic->mlx_ptr, data->tex->south->img_ptr);
	mlx_destroy_image(data->graphic->mlx_ptr, data->tex->west->img_ptr);
	mlx_destroy_window(data->graphic->mlx_ptr, data->graphic->win_ptr);
	mlx_loop_end(data->graphic->mlx_ptr);
	free_all(data);
	exit(1);
	return (0);
}
