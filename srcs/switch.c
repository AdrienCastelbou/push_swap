/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastelb <acastelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 09:33:13 by acastelb          #+#    #+#             */
/*   Updated: 2021/05/28 14:11:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_sb(t_dlist *b, char *s)
{
	int	temp;

	if (!b || !b->next)
		return ;
	temp = b->nb;
	b->nb = b->next->nb;
	b->next->nb = temp;
	if (s)
		ft_putstr_fd(s, STDOUT_FILENO);
}

void	ft_sa(t_dlist *a, char *s)
{
	int	temp;

	if (!a || !a->next)
		return ;
	temp = a->nb;
	a->nb = a->next->nb;
	a->next->nb = temp;
	if (s)
		ft_putstr_fd(s, STDOUT_FILENO);
}

void	ft_ss(t_stacks *stacks, char *s)
{
	ft_sa(stacks->a, NULL);
	ft_sb(stacks->b, NULL);
	if (s)
		ft_putstr_fd(s, STDOUT_FILENO);
}
