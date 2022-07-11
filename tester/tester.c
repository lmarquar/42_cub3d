/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarquar <lmarquar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 12:57:13 by lmarquar          #+#    #+#             */
/*   Updated: 2022/07/11 13:45:20 by lmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	testparser_textures(t_textures *t)
{
	int	i;
	int	fd;

	i = 0;
	while (t->nswe[i])
	{
		fd = open(t->nswe[i], O_RDONLY);
		if (fd == -1)
			printf("texturefile %d:\n%scouldn't be found\n\n", i, t->nswe[i]);
		close(fd);
		i++;
	}
	if (i != 4)
		printf("too little texturefiles loaded: expected 4, actual %d\n", i);
}

int	testparser(void)
{
	t_parser	*parser;
	char		*mapfile;

	printf("parser:\n");
	mapfile = "/Users/lmarquar/Desktop/Projects/Cube3d/cub3d/testmap.cub";
	parser = parse(mapfile);
	if (!parser)
	{
		printf("Error: parser returned NULL, terminating\n");
		exit(0);
	}
	testparser_textures(parser->textures);
	return (0);
}

void	testxpm(char *argv[])
{
	t_data		*data;
	t_graphic	*g;
	void		*xpm_i;
	int			w;
	int			h;

	printf("testxpm:\n");
	w = 0;
	h = 0;
	data = init(argv);
	g = data->graphic;
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_ptr, 0, 0);
	mlx_hook(g->win_ptr, 17, 0L, close_win, g);
	mlx_key_hook(g->win_ptr, khook, g);
	mlx_mouse_hook(g->win_ptr, mhook, g);
	xpm_i = mlx_xpm_file_to_image(g->mlx_ptr, "./red_armor.xpm", &w, &h);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, xpm_i, 0, 0);
	mlx_loop(g->mlx_ptr);
}

void	run_all(void)
{
	testparser();
}

int	main(int argc, char *argv[])
{
	printf("Tester Cub3d:\n");
	if (argc == 1)
		run_all();
	else if (arr_contains_str(argv, "parser"))
		testparser();
	else if (arr_contains_str(argv, "xpm"))
		testxpm(argv);
	return (0);
}
