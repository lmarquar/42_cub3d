/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarquar <lmarquar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:36:08 by fmollenh          #+#    #+#             */
/*   Updated: 2022/07/14 15:46:22 by lmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "../../include/libft/libft.h"
# include "../gnl/get_next_line.h"

/* Map data */
enum e_orientation
{
	NO,
	SO,
	WE,
	EA
};

typedef struct s_textures
{
	char	*nswe[5];
	int		*floor;
	int		*ceil;
}	t_textures;

typedef struct s_parser
{
	char		**layout;
	t_textures	*textures;
	int			xy_max[2];
}	t_parser;

t_parser	*parse(char *parser_file);
void		parser_free_all(t_parser *parser);

char		**load_layout(int fd);
int			layout_correct(char **layout);
int			*get_start_pos(char **layout);
int			is_start_chr(char c);

t_textures	*load_textures(int fd);
char		*find_first_occurence(char *s, char *x);
char		*texture_valid_format(char *s);
void		textures_free_all(t_textures *t);
int			textures_not_complete(t_textures *t);

char		*gnl_no_nl(int fd);
char		*find_needle(char *haystack, char *needle);
int			check_f_c_string(char *s);
int			print_error_if_aready_exists(void *ptr, char *string);

#endif
