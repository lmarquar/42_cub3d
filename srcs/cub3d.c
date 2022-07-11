/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:35:51 by fmollenh          #+#    #+#             */
/*   Updated: 2022/07/11 16:35:53 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	create_image(t_data *data)
{
	t_graphic	*g;

	g = data->graphic;
	rays(data);
	create_minimap(data);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_ptr, 0, 0);
}

int	main(int argc, char *argv[])
{
	t_data		*data;
	t_graphic	*g;

	if (argc != 2)
	{
		printf("ERROR\nWrong number of arguments\n");
		return (1);
	}
	data = init(argv);
	if (!data)
		return (1);
	g = data->graphic;
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_ptr, 0, 0);
	mlx_do_key_autorepeatoff(g->mlx_ptr);
	mlx_hook(g->win_ptr, 17, 0L, close_win, data);
	mlx_hook(g->win_ptr, 02, (1L << 0), key_hook_press, data->input);
	mlx_hook(g->win_ptr, 03, (1L << 1), key_hook_release, data->input);
	mlx_loop_hook(g->mlx_ptr, loop_hook, data);
	create_image(data);
	mlx_loop(g->mlx_ptr);
	return (0);
}
