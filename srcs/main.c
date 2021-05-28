/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastelb <acastelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:38:02 by acastelb          #+#    #+#             */
/*   Updated: 2021/05/28 14:53:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	get_median(t_stacks *stacks)
{
	int		*values;
	int		i;
	t_dlist	*elem;

	if (!(values = malloc(sizeof(int) * stacks->size)))
		return ;
	elem = stacks->a;
	i = -1;
	while (++i < stacks->size && elem)
	{
		values[i] = elem->nb;
		elem = elem->next;
	}
	sort_values(stacks->size, values);
	stacks->quart_size = stacks->size / 4;
	stacks->second_q = values[stacks->quart_size];
	stacks->median = values[stacks->size / 2];
	stacks->last_q = values[stacks->quart_size * 3];
	stacks->values = values;
}

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

int		get_nb_value(t_dlist *list, t_stacks *stacks, int pos)
{
	int i;

	i = 0;
	while (list)
	{
		if (list->nb == stacks->values[pos])
			break ;
		list = list->next;
		i++;
	}
	return (i);
}

int	get_mini_pos(t_dlist *list)
{
	int		i;
	int		pos;
	t_dlist	*min;

	i = 0;
	pos = 0;
	min = list;
	while (list)
	{
		if (min->nb > list->nb)
		{
			pos = i;
			min = list;
		}
		i++;
		list = list->next;
	}
	return (pos);
}

int	get_maxi_pos(t_dlist *list)
{
	int		i;
	int		pos;
	t_dlist	*maxi;

	i = 0;
	pos = 0;
	maxi = list;
	while (list)
	{
		if (maxi->nb < list->nb)
		{
			pos = i;
			maxi = list;
		}
		list = list->next;
		i++;
	}
	return (pos);
}

void	place_best_nb_on_top(t_stacks *stacks)
{
	int		mov_nb;
	void	(*fct)(t_stacks *, char *);
	char	*s;
	int		i;

	fct = choose_best_nb(stacks, &mov_nb);
	if (fct == &ft_rb)
		s = "rb\n";
	else
		s = "rrb\n";
	i = -1;
	while (++i < mov_nb)
		fct(stacks, s);
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

void	put_less_on_top(t_stacks *stacks, int n)
{
	if (get_nb_value(stacks->a, stacks, n) <
			(stacks->size / 2))
		while (stacks->a->nb != stacks->values[n])
			ft_ra(stacks, "ra\n");
	else
		while (stacks->a->nb != stacks->values[n])
			ft_rra(stacks, "rra\n");
}

void	less_or_egal_five(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (stacks->size - i > 3)
	{
		put_less_on_top(stacks, i);
		ft_pb(stacks, "pb\n");
		i++;
	}
	less_or_egal_three(stacks);
	while (stacks->b)
		ft_pa(stacks, "pa\n");
}

void	less_or_egal_hundred(t_stacks *stacks)
{
	push_and_sort_less_median(stacks);
	push_and_sort_more_median(stacks);
}

void	run_best_algo(t_stacks *stacks)
{
	if (stacks->size == 1)
		return ;
	else if (stacks->size <= 3)
		less_or_egal_three(stacks);
	else if (stacks->size <= 5)
		less_or_egal_five(stacks);
	else if (stacks->size <= 100)
		less_or_egal_hundred(stacks);
	else
		more_hundred(stacks);
	put_less_on_top(stacks, 0);
}

int		main(int ac, char **argv)
{
	t_stacks	*stacks;

	stacks = NULL;
	if (ac == 1)
		return (0);
	if (!(stacks = ft_stacksnew()))
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (1);
	}
	if (!check_argvs(stacks, argv))
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (1);
	}
	if (stack_is_sorted(stacks->a))
		return (0);
	get_stack_infos(stacks);
	run_best_algo(stacks);
	ft_stacksclear(stacks);
	return (0);
}
