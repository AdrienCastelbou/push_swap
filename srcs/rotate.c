/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastelb <acastelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 09:34:26 by acastelb          #+#    #+#             */
/*   Updated: 2021/05/26 09:34:46 by acastelb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stacks *stacks)
{
	t_dlist *elem;

	if (!stacks->a || !stacks->a->next)
		return ;
	elem = stacks->a;
	stacks->a = elem->next;
	stacks->a->prev = NULL;
	elem->next = NULL;
	ft_dlstadd_back(&stacks->a, elem);
}

void	ft_rb(t_stacks *stacks)
{
	t_dlist *elem;

	if (!stacks->b || !stacks->b->next)
		return ;
	elem = stacks->b;
	stacks->b = elem->next;
	stacks->b->prev = NULL;
	elem->next = NULL;
	ft_dlstadd_back(&stacks->b, elem);
}

void	ft_rr(t_stacks *stacks)
{
	ft_ra(stacks);
	ft_rb(stacks);
}
