/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastelb <acastelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:38:02 by acastelb          #+#    #+#             */
/*   Updated: 2021/05/26 17:44:25 by acastelb         ###   ########.fr       */
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
	stacks->median = values[stacks->size / 2];
	stacks->values = values;
}


void	push_less_median_a_to_b(t_stacks *stacks)
{
	t_dlist	*end;

	end = NULL;
	while (end != stacks->a)
	{
		if (stacks->a->nb < stacks->median)
			ft_pb(stacks, "pb\n");
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

void	sort_less_median_b_to_a(t_stacks *stacks)
{
	t_dlist	*less;

	less = NULL;
	while (stacks->b)
	{
		if (stacks->a->nb > stacks->b->nb &&
				(!less || less->nb < stacks->b->nb))
			ft_pa(stacks, "pa\n");
		else
		{
			if (less && less->nb > stacks->b->nb)
			{
				while (less->nb > stacks->b->nb)
				{
					less = less->prev;
					ft_rra(stacks, "rra\n");
				}
			}
			while (stacks->a->nb < stacks->b->nb)
			{
				less = stacks->a;
				ft_ra(stacks, "ra\n");
			}
		}
	}
}

void	push_more_median_a_to_b(t_stacks *stacks)
{
	while (stacks->a->nb < stacks->median)
		ft_ra(stacks, "ra\n");
	while (stacks->a->nb >= stacks->median)
		ft_pb(stacks, "pb\n");
}

void	sort_more_median_b_to_a(t_stacks *stacks)
{
	t_dlist	*less;

	ft_pa(stacks, "pa\n");
	less = NULL;
	while (stacks->b)
	{
		if (stacks->a->nb > stacks->b->nb &&
				(!less || less->nb < stacks->b->nb))
			ft_pa(stacks, "pa\n");
		else
		{
			if (less && less->nb > stacks->b->nb)
			{
				while (less->nb > stacks->b->nb)
				{
					less = less->prev;
					ft_rra(stacks, "rra\n");
				}
			}
			while (stacks->a->nb < stacks->b->nb)
			{
				less = stacks->a;
				ft_ra(stacks, "ra\n");
			}
		}
	}
}


void	push_and_sort_more_median(t_stacks *stacks)
{
	int		maxi_pos;
	void	(*fct)(t_stacks *, char *);
	char	*s;

	push_more_median_a_to_b(stacks);
	maxi_pos = get_nb_value(stacks->b, stacks, stacks->size - 1);
	if (maxi_pos < ft_dlstsize(stacks->b) / 2)
	{
		fct = ft_rb;
		s = "rb\n";
	}
	else
	{
		fct = ft_rrb;
		s = "rrb\n";
	}
	while (stacks->b->nb != stacks->values[stacks->size -1])
		fct(stacks, s);
	sort_more_median_b_to_a(stacks);
}

void	push_and_sort_less_median(t_stacks *stacks)
{
	int		mini_pos;
	void	(*fct)(t_stacks *, char *);
	char	*s;

	push_less_median_a_to_b(stacks);
	mini_pos = get_nb_value(stacks->b, stacks, 0);
	if (mini_pos < ft_dlstsize(stacks->b) / 2)
	{
		fct = ft_rb;
		s = "rb\n";
	}
	else
	{
		fct = ft_rrb;
		s = "rrb\n";
	}
	while (stacks->b->nb != stacks->values[0])
		fct(stacks, s);
	sort_less_median_b_to_a(stacks);
}

void	second_alg(t_stacks *stacks)
{
	int	i;

	get_median(stacks);
	i = -1;
	while (++i < 2)
	{
		if (i == 0)
			push_and_sort_less_median(stacks);
		else
			push_and_sort_more_median(stacks);
	}
	while (stacks->a->nb != stacks->values[0])
		ft_ra(stacks, "ra\n");
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
	stacks->size = ft_dlstsize(stacks->a);
	second_alg(stacks);
	ft_stacksclear(stacks);
	return (0);
}
