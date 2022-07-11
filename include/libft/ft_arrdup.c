/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 08:27:53 by fmollenh          #+#    #+#             */
/*   Updated: 2022/04/01 08:34:32 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrdup(const char *const *arr)
{
	char	**new_arr;
	size_t	i;

	new_arr = malloc(sizeof(char *) * (ft_arrlen(arr) + 1));
	if (new_arr != NULL)
	{
		i = 0;
		while (arr[i] != NULL)
		{
			new_arr[i] = ft_strdup(arr[i]);
			if (new_arr[i] == NULL)
			{
				ft_arrdel(new_arr);
				return (NULL);
			}
			i++;
		}
		new_arr[i] = NULL;
	}
	return (new_arr);
}
