/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:35:03 by fmollenh          #+#    #+#             */
/*   Updated: 2022/07/12 14:43:30 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	exit_program(int nbr, t_data *data, char *filename)
{
	if (nbr == 1)
	{
		printf("ERROR\nXpm file %s not in valid format\n", filename);
		free_all(data);
		exit (1);
	}
	if (nbr == 2)
	{
		printf("ERROR\nSize of texture in xpm file %s is to small\n", filename);
		free_all(data);
		exit(2);
	}
}

t_texture	*get_texture(t_data *data, char *filename)
{
	t_texture	*tex;

	tex = ft_calloc(1, sizeof(t_texture));
	tex->img_ptr = mlx_xpm_file_to_image(data->graphic->mlx_ptr,
			filename, &tex->width, &tex->height);
	if (!tex->img_ptr)
		exit_program(1, data, filename);
	tex->img = mlx_get_data_addr(tex->img_ptr, &tex->img_bp,
			&tex->img_sl, &tex->img_e);
	tex->img_matrix = create_matrix(tex->img, tex->width,
			tex->height, tex->img_sl);
	if (tex->height > tex->width)
		tex->size = (tex->width);
	else
		tex->size = (tex->height);
	// if (tex->size < 100)
	// 	exit_program(2, data, filename);
	return (tex);
}

int	*get_tex_pixel(t_data *data, t_texture *tex, t_ray ray, int wall_pixel_y)
{
	double	tex_start;
	int		x;
	int		y;

	if (data->rays->orientation == 'h')
		tex_start = (tex->size - 1) * data->rays->equ_x;
	else
		tex_start = (tex->size - 1) * data->rays->equ_y;
	x = (int)((ray.pixel.row
				- (data->rays->middle_pixel_y - (wall_pixel_y / 2)))
			* ((double)(tex->size - 1) / wall_pixel_y));
	y = (int)(tex_start + ray.pixel.ray_col * (((data->rays->pixel_per_calc
						* (ray.i + 1) - 1) - (data->rays->pixel_per_calc
						* ray.i)) / ((tex_start + (ray.delta_x
							* (tex->size - 1))) - tex_start)));
	return ((int *)tex->img_matrix[x][y]);
}
