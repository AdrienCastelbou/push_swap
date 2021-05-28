/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:15:53 by user42            #+#    #+#             */
/*   Updated: 2021/05/28 15:16:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*ft_dlstnew(int content)
{
	t_dlist	*elem;

	if (!(elem = (t_dlist*)malloc(sizeof(t_dlist))))
		return (NULL);
	elem->nb = content;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

int		ft_dlstsize(t_dlist *dlst)
{
	int i;

	i = 0;
	while (dlst && ++i)
		dlst = dlst->next;
	return (i);
}
