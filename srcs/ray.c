/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:35:13 by fmollenh          #+#    #+#             */
/*   Updated: 2022/07/11 16:35:15 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

double	get_len(t_data *data, double player_angle, double angle)
{
	double	perp_len;
	double	hori_len;
	double	len;

	perp_len = get_perp_len(data, angle);
	hori_len = get_hori_len(data, angle);
	if (perp_len < hori_len)
	{
		if (angle >= player_angle)
			len = perp_len * (cos(degree_in_radiant(angle - player_angle)));
		else
			len = perp_len * (cos(degree_in_radiant(player_angle - angle)));
		data->rays->orientation = 'p';
	}
	else
	{
		if (angle >= player_angle)
			len = hori_len * (cos(degree_in_radiant(angle - player_angle)));
		else
			len = hori_len * (cos(degree_in_radiant(player_angle - angle)));
		data->rays->orientation = 'h';
	}
	return (len);
}

int	*select_texture(t_data *data, t_ray ray, int wall_pixel_y)
{
	ray.pixel.ray_col = ray.pixel.col
		- (data->rays->pixel_per_calc * ray.i);
	if (data->rays->orientation == 'p'
		&& (ray.angle < 90 || ray.angle > 270))
		ray.pixel.color = get_tex_pixel(data,
				data->tex->north, ray, wall_pixel_y);
	if (data->rays->orientation == 'p'
		&& (ray.angle > 90 && ray.angle < 270))
		ray.pixel.color = get_tex_pixel(data,
				data->tex->south, ray, wall_pixel_y);
	if (data->rays->orientation == 'h'
		&& ray.angle > 180)
		ray.pixel.color = get_tex_pixel(data,
				data->tex->east, ray, wall_pixel_y);
	if (data->rays->orientation == 'h'
		&& ray.angle < 180)
		ray.pixel.color = get_tex_pixel(data,
				data->tex->west, ray, wall_pixel_y);
	return (ray.pixel.color);
}

void	print_one_calc(t_data *data, t_ray ray)
{
	int		wall_pixel_y;
	double	delta_angle;

	wall_pixel_y = data->graphic->img_y / ray.len;
	ray.pixel.row = -1;
	delta_angle = data->rays->view_degree / data->rays->nbr_calc;
	ray.delta_x = sqrt(pow(sin(delta_angle) * ray.len, 2) + pow
			((ray.len * cos(ray.angle) / cos(ray.angle + delta_angle))
				- (cos(delta_angle) * ray.len), 2));
	while (++ray.pixel.row < data->graphic->img_y)
	{
		ray.pixel.col = -1 + (data->rays->pixel_per_calc * ray.i);
		while (++ray.pixel.col < data->rays->pixel_per_calc
			+ (data->rays->pixel_per_calc * ray.i))
		{
			if (ray.pixel.row < data->rays->middle_pixel_y - (wall_pixel_y / 2))
				ray.pixel.color = data->parser->textures->ceil;
			else if (ray.pixel.row > data->rays->middle_pixel_y
				+ (wall_pixel_y / 2))
				ray.pixel.color = data->parser->textures->floor;
			else
				ray.pixel.color = select_texture(data, ray, wall_pixel_y);
			pixel_color(data, &ray.pixel);
		}
	}
}

void	rays(t_data *data)
{
	t_rays	*rays;

	rays = data->rays;
	rays->current_ray.i = 0;
	if ((data->player->direction_d - (rays->view_degree / 2)) < 0)
		rays->current_ray.angle = data->player->direction_d
			- (rays->view_degree / 2) + 360;
	else
		rays->current_ray.angle = data->player->direction_d
			- (rays->view_degree / 2);
	while (rays->current_ray.i < rays->nbr_calc)
	{
		rays->current_ray.len = get_len(data, data->player->direction_d,
				rays->current_ray.angle);
		print_one_calc(data, rays->current_ray);
		rays->current_ray.angle = rays->current_ray.angle
			+ ((rays->view_degree - 1) / rays->nbr_calc);
		if (rays->current_ray.angle >= 360)
			rays->current_ray.angle = rays->current_ray.angle - 360;
		rays->current_ray.i++;
	}	
}
