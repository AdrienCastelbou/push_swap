/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastelb <acastelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 09:33:13 by acastelb          #+#    #+#             */
/*   Updated: 2021/05/26 09:33:45 by acastelb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_sb(t_dlist *b)
{
	int	temp;

	if (!b || !b->next)
		return ;
	temp = b->nb;
	b->nb = b->next->nb;
	b->next->nb = temp;
}

void	ft_sa(t_dlist *a)
{
	int	temp;

	if (!a || !a->next)
		return ;
	temp = a->nb;
	a->nb = a->next->nb;
	a->next->nb = temp;
}

void	ft_ss(t_stacks *stacks)
{
	ft_sa(stacks->a);
	ft_sb(stacks->b);
}
