/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastelb <acastelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 17:34:02 by acastelb          #+#    #+#             */
/*   Updated: 2021/05/20 09:11:04 by acastelb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dlstadd_back(t_dlist **adlst, t_dlist *new)
{
	t_dlist *elem;

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
	elem->next = new;
	new->prev = elem;
}

void	ft_dlstadd_front(t_dlist **adlst, t_dlist *new)
{
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
	if (!dlst)
		return (NULL);
	while (dlst->next)
		dlst = dlst->next;
	return (dlst);
}

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

int	ft_dlstsize(t_dlist *dlst)
{
	int i;

	i = 0;
	while (dlst && ++i)
		dlst = dlst->next;
	return (i);
}
