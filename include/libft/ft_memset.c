/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarquar <lmarquar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:02:35 by fmollenh          #+#    #+#             */
/*   Updated: 2022/06/16 10:37:44 by lmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*mem;
	unsigned char	val;

	mem = s;
	val = c;
	i = 0;
	while (i < (unsigned int)n)
	{
		mem[i] = val;
		i++;
	}
	return (mem);
}
