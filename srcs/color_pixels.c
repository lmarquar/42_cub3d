/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_pixels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:35:54 by fmollenh          #+#    #+#             */
/*   Updated: 2022/07/11 16:35:56 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	*create_color(int color1, int color2, int color3)
{
	int	*color;

	color = malloc(4 * sizeof(int));
	color[0] = color1;
	color[1] = color2;
	color[2] = color3;
	color[3] = -1;
	return (color);
}

void	pixel_color(t_data *data, t_pixel *pixel)
{
	(data->graphic->img_matrix)[pixel->row]
	[pixel->col][0] = (char)pixel->color[0];
	(data->graphic->img_matrix)[pixel->row]
	[pixel->col][1] = (char)pixel->color[1];
	(data->graphic->img_matrix)[pixel->row]
	[pixel->col][2] = (char)pixel->color[2];
	if (pixel->color[3] == -1)
		free(pixel->color);
}
