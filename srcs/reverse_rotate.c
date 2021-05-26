/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastelb <acastelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 09:34:55 by acastelb          #+#    #+#             */
/*   Updated: 2021/05/26 17:18:35 by acastelb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stacks *stacks, char *s)
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
	if (s)
		ft_putstr_fd(s, STDOUT_FILENO);
}

void	ft_rrb(t_stacks *stacks, char *s)
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
	if (s)
		ft_putstr_fd(s, STDOUT_FILENO);

}

void	ft_rrr(t_stacks *stacks, char *s)
{
	ft_rrb(stacks, NULL);
	ft_rra(stacks, NULL);
	if (s)
		ft_putstr_fd(s, STDOUT_FILENO);

}
