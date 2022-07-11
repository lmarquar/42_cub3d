/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_no_nl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:37:21 by fmollenh          #+#    #+#             */
/*   Updated: 2022/07/11 16:37:23 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*gnl_no_nl(int fd)
{
	char	*gnl_out;
	char	*res;
	int		i;

	gnl_out = get_next_line(fd);
	if (!gnl_out)
		return (gnl_out);
	i = ft_strlen(gnl_out);
	res = ft_calloc(i, sizeof(char));
	i = 0;
	while (gnl_out[i] && gnl_out[i] != '\n')
	{
		res[i] = gnl_out[i];
		i++;
	}
	free(gnl_out);
	return (res);
}
