/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_less_hundred.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 14:57:16 by user42            #+#    #+#             */
/*   Updated: 2021/05/28 15:01:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_less_median_a_to_b(t_stacks *stacks)
{
	t_dlist	*end;
	int		i;
	int		stack_mid;

	stack_mid = (stacks->size / 2);
	i = 0;
	end = NULL;
	while (i < stack_mid && end != stacks->a)
	{
		if (stacks->a->nb < stacks->median)
		{
			i += 1;
			ft_pb(stacks, "pb\n");
		}
		else
		{
			if (!end)
				end = stacks->a;
			ft_ra(stacks, "ra\n");
		}
	}
}

void	push_and_sort_less_median(t_stacks *stacks)
{
	push_less_median_a_to_b(stacks);
	while (stacks->b)
	{
		place_best_nb_on_top(stacks);
		if (stacks->b->nb < stacks->a->nb)
			ft_pa(stacks, "pa\n");
		else
			ft_ra(stacks, "ra\n");
	}
}

void	push_more_median_a_to_b(t_stacks *stacks)
{
	while (stacks->a->nb < stacks->median)
		ft_ra(stacks, "ra\n");
	while (stacks->a->nb >= stacks->median)
		ft_pb(stacks, "pb\n");
}

void	push_and_sort_more_median(t_stacks *stacks)
{
	push_more_median_a_to_b(stacks);
	place_best_nb_on_top(stacks);
	ft_pa(stacks, "pa\n");
	while (stacks->b)
	{
		place_best_nb_on_top(stacks);
		if (stacks->b->nb < stacks->a->nb)
			ft_pa(stacks, "pa\n");
		else
		{
			ft_ra(stacks, "ra\n");
			ft_pa(stacks, "pa\n");
		}
	}
}

void	less_or_egal_hundred(t_stacks *stacks)
{
	push_and_sort_less_median(stacks);
	push_and_sort_more_median(stacks);
}
