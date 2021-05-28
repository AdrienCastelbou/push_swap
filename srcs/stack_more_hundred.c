/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_more_hundred.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 14:47:54 by user42            #+#    #+#             */
/*   Updated: 2021/05/28 14:51:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_size(int *values, int start, int end)
{
	int	i;
	int	j;

	i = 0;
	while (values[i] < start)
		i++;
	j = 0;
	while (values[i + j] != end)
		j++;
	return (j);
}

void	push_quart_a_to_b(t_stacks *stacks, int start, int end)
{
	int		chunk_size;
	int		i;
	t_dlist	*end_lst;

	chunk_size = get_chunk_size(stacks->values, start, end);
	i = 0;
	end_lst = NULL;
	while (i < chunk_size && stacks->a != end_lst)
	{
		if (stacks->a->nb < end && stacks->a->nb >= start)
		{
			i += 1;
			ft_pb(stacks, "pb\n");
		}
		else
		{
			if (!end_lst)
				end_lst = stacks->a;
			ft_ra(stacks, "ra\n");
		}
	}
}

void	push_and_sort_quart(t_stacks *stacks, int start, int end)
{
	push_quart_a_to_b(stacks, start, end);
	while (stacks->b)
	{
		place_best_nb_on_top(stacks);
		if (stacks->b->nb < stacks->a->nb)
			ft_pa(stacks, "pa\n");
		else
			ft_ra(stacks, "ra\n");
	}
}

void	more_hundred(t_stacks *stacks)
{
	push_and_sort_quart(stacks, stacks->last_q,
			stacks->values[stacks->size - 1]);
	push_and_sort_quart(stacks, stacks->median, stacks->last_q);
	push_and_sort_quart(stacks, stacks->second_q, stacks->median);
	push_and_sort_quart(stacks, *(stacks->values), stacks->second_q);
}
