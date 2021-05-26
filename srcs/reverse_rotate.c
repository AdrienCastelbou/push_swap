/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastelb <acastelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 09:34:55 by acastelb          #+#    #+#             */
/*   Updated: 2021/05/26 09:35:23 by acastelb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stacks *stacks)
{
	t_dlist	*last;
	t_dlist	*elem;

	if (!stacks->a || !stacks->a->next)
		return ;
	elem = stacks->a;
	while (elem->next->next)
		elem = elem->next;
	last = elem->next;
	last->prev = NULL;
	elem->next = NULL;
	ft_dlstadd_front(&stacks->a, last);
}

void	ft_rrb(t_stacks *stacks)
{
	t_dlist	*last;
	t_dlist	*elem;

	if (!stacks->b || !stacks->b->next)
		return ;
	elem = stacks->b;
	while (elem->next->next)
		elem = elem->next;
	last = elem->next;
	last->prev = NULL;
	elem->next = NULL;
	ft_dlstadd_front(&stacks->b, last);
}

void	ft_rrr(t_stacks *stacks)
{
	ft_rrb(stacks);
	ft_rra(stacks);
}
