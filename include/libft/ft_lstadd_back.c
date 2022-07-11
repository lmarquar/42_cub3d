/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmollenh <fmollenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 16:32:21 by fmollenh          #+#    #+#             */
/*   Updated: 2021/06/28 21:23:29 by fmollenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lsttemp;

	if (*lst == NULL)
		*lst = new;
	else
	{
		lsttemp = *lst;
		while (lsttemp->next != NULL)
			lsttemp = lsttemp->next;
		lsttemp->next = new;
	}
}
