/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarquar <lmarquar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 12:57:29 by lmarquar          #+#    #+#             */
/*   Updated: 2022/07/11 13:44:47 by lmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	arr_contains_str(char **sarr, char *s)
{
	int	i;

	i = 1;
	while (sarr[i])
	{
		if (!ft_strncmp(sarr[i], s, ft_strlen(sarr[i])))
			return (1);
		i++;
	}
	return (0);
}
