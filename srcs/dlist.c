/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastelb <acastelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 17:34:02 by acastelb          #+#    #+#             */
/*   Updated: 2021/05/31 10:52:22 by acastelb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dlstadd_back(t_dlist **adlst, t_dlist *new)
{
	t_dlist	*elem;

	if (!adlst)
		return ;
	if (!*adlst)
	{
		*adlst = new;
		return ;
	}
	elem = *adlst;
	while (elem->next)
		elem = elem->next;
	if (elem)
		elem->next = new;
	if (new)
		new->prev = elem;
}

void	ft_dlstadd_front(t_dlist **adlst, t_dlist *new)
{
	if (adlst && *adlst)
		(*adlst)->prev = new;
	new->next = *adlst;
	*adlst = new;
}

void	ft_dlstdelone(t_dlist *dlst, void (*del)(void *))
{
	if (!dlst)
		return ;
	del(dlst);
}

void	ft_dlstclear(t_dlist **dlst, void (*del)(void *))
{
	if (!del || !dlst || !*dlst)
		return ;
	if ((*dlst)->next != NULL)
		ft_dlstclear(&((*dlst)->next), del);
	ft_dlstdelone((*dlst), del);
	*dlst = NULL;
}

t_dlist	*ft_dlstlast(t_dlist *dlst)
{
	t_dlist	*last;

	if (!dlst)
		return (NULL);
	last = dlst;
	while (last->next)
		last = last->next;
	return (last);
}
