/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastelb <acastelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 09:42:36 by acastelb          #+#    #+#             */
/*   Updated: 2021/05/28 14:39:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_stack_infos(t_stacks *stacks)
{
	stacks->size = ft_dlstsize(stacks->a);
	get_median(stacks);
}

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

long int	ft_atoli(const char *str)
{
	int			i;
	int			is_neg;
	long int	result;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	is_neg = 1;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			is_neg *= -1;
		i++;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * is_neg);
}

void		less_or_egal_three(t_stacks *stacks)
{
	int		first;
	int		middle;
	int		last;

	first = stacks->a->nb;
	middle = stacks->a->next->nb;
	last = ft_dlstlast(stacks->a)->nb;
	if (first < middle && middle <= last)
		return ;
	if (first < middle && middle > last && last > first)
		ft_sa(stacks->a, "sa\n");
	else if (first > middle && middle > last)
		ft_sa(stacks->a, "sa\n");
	else if (middle == last || (first > middle && first < last))
		ft_sa(stacks->a, "sa\n");
	first = stacks->a->nb;
	middle = stacks->a->next->nb;
	last = ft_dlstlast(stacks->a)->nb;
	if (first > middle && first > last && middle < last)
		ft_ra(stacks, "ra\n");
	else if (first < middle && first > last)
		ft_rra(stacks, "rra\n");
}
