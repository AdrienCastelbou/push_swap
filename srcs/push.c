/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastelb <acastelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 09:33:55 by acastelb          #+#    #+#             */
/*   Updated: 2021/05/26 09:34:15 by acastelb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb(t_stacks *stacks)
{
	t_dlist	*elem;
	if (!stacks->a)
		return ;
	elem = stacks->a->next;
	elem->prev = NULL;
	ft_dlstadd_front(&stacks->b, stacks->a);
	stacks->a = elem;
}

void	ft_pa(t_stacks *stacks)
{
	t_dlist	*elem;
	if (!stacks->b)
		return ;
	elem = stacks->b->next;
	if (elem)
		elem->prev = NULL;
	ft_dlstadd_front(&stacks->a, stacks->b);
	stacks->b = elem;
}
