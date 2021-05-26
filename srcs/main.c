/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastelb <acastelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:38:02 by acastelb          #+#    #+#             */
/*   Updated: 2021/05/26 11:19:01 by acastelb         ###   ########.fr       */
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
		{
			ft_pb(stacks);
			//ft_putstr_fd("pb\n", STDOUT_FILENO);
		}
		else
		{
			if (!end)
				end = stacks->a;
			ft_ra(stacks);
			//ft_putstr_fd("ra\n", STDOUT_FILENO);
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

	less = stacks->a;
	while (stacks->b)
	{
		if (stacks->a->nb > stacks->b->nb)
		{
			ft_pa(stacks);
			//ft_putstr_fd("pa\n", STDOUT_FILENO);
		}
		else
		{
			while (stacks->a->nb < stacks->b->nb && (less->nb > stacks->b->nb ||
						less->nb < stacks->a->nb))
			{
				less = stacks->a;
				ft_ra(stacks);
				//ft_putstr_fd("ra\n", STDOUT_FILENO);
			}
		}
	}
}

void	push_and_sort_less_median(t_stacks *stacks)
{
	int	less_nb_pos;
	int	greather_nb_pos;

	push_less_median_a_to_b(stacks);
	less_nb_pos = get_nb_value(stacks->b, stacks, 0);
	greather_nb_pos = get_nb_value(stacks->b, stacks, (stacks->size / 2) - 1);
	
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
			;//push_and_sort_more_median(stacks);
	}
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
	ft_show_stack(stacks->a);
	ft_show_stack(stacks->b);
	ft_stacksclear(stacks);
	return (0);
}
