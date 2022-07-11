/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 10:51:50 by fmollenh          #+#    #+#             */
/*   Updated: 2021/06/22 19:34:19 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*out;
	int				i;
	size_t			len;

	if ((s == NULL) || (f == NULL))
		return (NULL);
	len = ft_strlen(s);
	out = malloc((len + 1) * sizeof(char));
	if (out == NULL)
		return (NULL);
	i = 0;
	while (i < (int)len)
	{
		out[i] = (*f)(i, s[i]);
		i++;
	}
	out[i] = '\0';
	return (out);
}
