/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:36:28 by fmollenh          #+#    #+#             */
/*   Updated: 2022/07/11 16:36:32 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include "../srcs/parser/parser.h"
# include "keys.h"
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>

/* Player data */
typedef struct s_player
{
	int		radius;
	int		x_position;
	int		y_position;
	double	x_calc;
	double	y_calc;
	double	direction_d;
	int		direction_len;
	double	direction_ratio;
}	t_player;

/* Main data */
typedef struct s_graphic
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img;
	char	***img_matrix;
	int		img_bp;
	int		img_sl;
	int		img_e;
	int		img_y;
	int		img_x;
}	t_graphic;

typedef struct s_map
{
	int		map_size[2];
	int		wall_size;
	int		minimap_size;
	char	**map;
}	t_map;

typedef struct s_pixel
{
	int		row;
	int		col;
	int		ray_col;
	int		type;
	int		*color;
}	t_pixel;

typedef struct s_ray
{
	int			i;
	double		angle;
	t_pixel		pixel;
	double		len;
	double		delta_x;
}	t_ray;

typedef struct s_texture
{
	void	*img_ptr;
	char	*img;
	char	***img_matrix;
	int		img_bp;
	int		img_sl;
	int		img_e;
	int		height;
	int		width;
	int		size;
	char	orientation;
	double	equ_x;
	double	equ_y;
}	t_texture;

typedef struct s_tex
{
	t_texture	*north;
	t_texture	*east;
	t_texture	*south;
	t_texture	*west;
}	t_tex;

typedef struct s_rays
{
	double		view_degree;
	int			nbr_calc;
	int			pixel_per_calc;
	int			middle_pixel_x;
	int			middle_pixel_y;
	char		orientation;
	double		equ_x;
	double		equ_y;
	t_ray		current_ray;
}	t_rays;

typedef struct s_input
{
	int	up;
	int	down;
	int	left;
	int	right;
	int	a;
	int	d;
	int	w;
	int	s;
	int	esc;
}	t_input;

typedef struct s_data
{
	t_graphic		*graphic;
	t_parser		*parser;
	t_map			*map;
	t_player		*player;
	t_rays			*rays;
	t_tex			*tex;
	t_input			*input;
	int				pixel_scale;
	unsigned int	loop;
}	t_data;

// mlx-affected
int			khook(int key, void *param);
int			mhook(int button, int x, int y, void *param);
int			key_hook_press(int key, void *param);
int			key_hook_release(int key, void *param);
int			loop_hook(void *param);
int			move(int key, void *param);
int			move_forward(t_data *data);
int			move_backward(t_data *data);
int			move_left(t_data *data);
int			move_right(t_data *data);
int			close_win(void *param);

//init and freeing
t_data		*init(char **argv);
void		free_all(t_data *data);
int			init_player(t_data *data);
void		init_minimap(t_data *data);
void		create_minimap(t_data *data);
void		create_image(t_data *data);

//pixel and colors
void		pixel_color(t_data *data, t_pixel *pixel);
int			*create_color(int color1, int color2, int color3);
t_texture	*get_texture(t_data *data, char *filename);
char		***create_matrix(char *img, int img_width,
				int img_height, int img_sl);
int			*get_tex_pixel(t_data *data, t_texture *tex,
				t_ray ray, int wall_pixel_y);

// raytracing
void		rays(t_data *data);
double		get_hori_len(t_data *data, double angle_d);
double		get_perp_len(t_data *data, double angle_d);
double		angle_0d(t_data *data);
double		angle_90d(t_data *data);
double		angle_180d(t_data *data);
double		angle_270d(t_data *data);

//others
int			get_new_xy_pos(t_data *data);
double		degree_in_radiant(double degree);

#endif
