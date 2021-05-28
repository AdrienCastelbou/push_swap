/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastelb <acastelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:38:02 by acastelb          #+#    #+#             */
/*   Updated: 2021/05/28 13:30:34 by acastelb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_switch(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

void	sort_values(int size, int *values)
{
	int i;
	int j;

	i = -1;
	while (++i < size - 1)
	{
		j = i;
		while (++j < size)
			if (values[i] > values[j])
				ft_switch(values + i, values + j);
	}
}

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
			break;
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

void	(*choose_best_nb(t_stacks *stacks, int *choice))
(t_stacks *, char *s)
{
	int	mini_pos;
	int	maxi_pos;
	int	stack_size;

	stack_size = ft_dlstsize(stacks->b);
	mini_pos = get_mini_pos(stacks->b);
	maxi_pos = get_maxi_pos(stacks->b);
	if (mini_pos < stack_size / 2 && maxi_pos < stack_size / 2)
	{
		if (mini_pos < maxi_pos)
			*choice = mini_pos;
		else
			*choice = maxi_pos;
		return (&ft_rb);
	}
	else if (mini_pos >= stack_size / 2 && maxi_pos >= stack_size / 2)
	{
		if (mini_pos > maxi_pos)
			*choice = stack_size - mini_pos;
		else
			*choice = stack_size - maxi_pos;
		return (&ft_rrb);
	}
	else if (mini_pos < stack_size / 2 && maxi_pos >= stack_size / 2)
	{
		if (mini_pos < (stack_size - maxi_pos))
		{
			*choice = mini_pos;
			return (&ft_rb);
		}
		else
		{
			*choice = stack_size - maxi_pos;
			return (&ft_rrb);
		}
	}
	else
	{
		if (maxi_pos < (stack_size - mini_pos))
		{
			*choice = maxi_pos;
			return (&ft_rb);
		}
		else
		{
			*choice = stack_size - mini_pos;
			return (&ft_rrb);
		}
	}
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

void	second_alg(t_stacks *stacks)
{
	push_and_sort_less_median(stacks);
	push_and_sort_more_median(stacks);
}

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

void push_quart_a_to_b(t_stacks *stacks, int start, int end)
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


void	third_alg(t_stacks *stacks)
{
	push_and_sort_quart(stacks, stacks->last_q, stacks->values[stacks->size - 1]);
	push_and_sort_quart(stacks, stacks->median, stacks->last_q);
	push_and_sort_quart(stacks, stacks->second_q, stacks->median);
	push_and_sort_quart(stacks, *(stacks->values), stacks->second_q);
}

void	get_stack_infos(t_stacks *stacks)
{
	stacks->size = ft_dlstsize(stacks->a);
	get_median(stacks);
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

void	run_best_algo(t_stacks *stacks)
{
	if (stacks->size == 1)
		return ;
	else if (stacks->size <= 3)
		less_or_egal_three(stacks);
	else if (stacks->size <= 5)
		less_or_egal_five(stacks);
	else if (stacks->size <= 100)
		second_alg(stacks);
	else
		third_alg(stacks);
	put_less_on_top(stacks, 0);
}

int		main(int ac, char **argv)
{
	t_stacks	*stacks;

	stacks = NULL;
	if (ac == 1)
		return(0);
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
