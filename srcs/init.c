/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:35:31 by fmollenh          #+#    #+#             */
/*   Updated: 2022/07/12 15:57:29 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	***create_matrix(char *img, int img_width, int img_height, int img_sl)
{
	int		i;
	char	*ptr;
	char	**pptr;
	char	***ppptr;

	ptr = img;
	pptr = malloc(sizeof(char *) * img_width * img_sl);
	i = 0;
	while (ptr < (img + img_height * img_sl))
	{
		pptr[i++] = ptr;
		ptr = ptr + 4;
	}
	ppptr = malloc(sizeof(char **) * img_height);
	i = -1;
	while (++i < img_height)
	{
		ppptr[i] = pptr;
		pptr = pptr + img_width;
	}
	return (ppptr);
}

t_graphic	*create_window(void)
{
	t_graphic	*g;

	g = ft_calloc(1, sizeof(t_graphic));
	g->img_y = 600;
	g->img_x = 900;
	g->mlx_ptr = mlx_init();
	g->img_ptr = mlx_new_image(g->mlx_ptr, g->img_x, g->img_y);
	g->win_ptr = mlx_new_window(g->mlx_ptr, g->img_x, g->img_y, "cube3d");
	g->img = mlx_get_data_addr(g->img_ptr, &g->img_bp, &g->img_sl, &g->img_e);
	g->img_matrix = create_matrix(g->img, g->img_x, g->img_y, g->img_sl);
	return (g);
}

void	init_rays(t_data *data)
{
	data->rays = ft_calloc(1, sizeof(t_rays));
	data->rays->middle_pixel_x = data->graphic->img_x / 2;
	data->rays->middle_pixel_y = data->graphic->img_y / 2;
	data->rays->view_degree = 66;
	data->rays->nbr_calc = data->graphic->img_x / 4;
	data->rays->pixel_per_calc = data->graphic->img_x / data->rays->nbr_calc;
}

void	init_texture(t_data *data)
{
	data->tex = ft_calloc(1, sizeof(t_tex));
	data->tex->north = get_texture(data, data->parser->textures->nswe[0]);
	data->tex->east = get_texture(data, data->parser->textures->nswe[1]);
	data->tex->south = get_texture(data, data->parser->textures->nswe[2]);
	data->tex->west = get_texture(data, data->parser->textures->nswe[3]);
}

t_data	*init(char **argv)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	data->pixel_scale = 3;
	data->parser = parse(argv[1]);
	if (!data->parser)
	{
		free(data);
		return (NULL);
	}
	data->input = ft_calloc(1, sizeof(t_input));
	data->graphic = create_window();
	init_minimap(data);
	init_player(data);
	init_rays(data);
	init_texture(data);
	return (data);
}
