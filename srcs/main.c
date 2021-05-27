/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastelb <acastelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:38:02 by acastelb          #+#    #+#             */
/*   Updated: 2021/05/27 10:50:25 by acastelb         ###   ########.fr       */
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
			ft_ra(stacks, "ra\n");
	}
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
