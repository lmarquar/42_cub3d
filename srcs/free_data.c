/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:35:46 by fmollenh          #+#    #+#             */
/*   Updated: 2022/07/11 16:35:49 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_matrix(char ***ptr)
{
	free(ptr[0]);
	free(ptr);
}

void	free_texture(t_data *data)
{
	if (data->tex->north != NULL)
	{
		if (data->tex->north->img_matrix != NULL)
			free_matrix(data->tex->north->img_matrix);
		free(data->tex->north);
	}
	if (data->tex->east != NULL)
	{
		if (data->tex->east->img_matrix != NULL)
			free_matrix(data->tex->east->img_matrix);
		free(data->tex->east);
	}
	if (data->tex->south != NULL)
	{
		if (data->tex->south->img_matrix != NULL)
			free_matrix(data->tex->south->img_matrix);
		free(data->tex->south);
	}
	if (data->tex->west != NULL)
	{
		if (data->tex->west->img_matrix != NULL)
			free_matrix(data->tex->west->img_matrix);
		free(data->tex->west);
	}
	free(data->tex);
}

void	free_all(t_data *data)
{
	free(data->input);
	free_matrix(data->graphic->img_matrix);
	free(data->graphic->mlx_ptr);
	free(data->graphic);
	free(data->player);
	parser_free_all(data->parser);
	ft_arrdel(data->map->map);
	free(data->map);
	free(data->rays);
	free_texture(data);
	free(data);
}
