/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdelline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 09:31:59 by fmollenh          #+#    #+#             */
/*   Updated: 2022/04/01 09:39:54 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrdelline(char **arr, size_t line)
{
	int	i;

	if (line > ft_arrlen((const char *const *)arr))
		return (arr);
	if (line == ft_arrlen((const char *const *)arr) && line == 0)
	{
		ft_arrdel(arr);
		return (NULL);
	}
	if (arr[line] != NULL)
		free(arr[line]);
	i = (int) line;
	while (arr[i + 1] != NULL)
	{
		arr[i] = arr[i + 1];
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
