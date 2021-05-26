/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastelb <acastelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 09:42:36 by acastelb          #+#    #+#             */
/*   Updated: 2021/05/26 17:23:59 by acastelb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	less_or_egal_three(t_stacks *stacks)
{
	int		first;
	int		middle;
	int		last;

	first = stacks->a->nb;
	middle = stacks->a->next->nb;
	last = ft_dlstlast(stacks->a)->nb;
	if (first < middle && middle <= last)
		return ;
	if (first < middle && middle > last && last > first) //1-3-2
		ft_sa(stacks->a, "sa\n"); // 3-1-2
	else if (first > middle && middle > last) // 3-2-1
		ft_sa(stacks->a, "sa\n"); //2-3-1
	else if (middle == last || (first > middle && first < last)) // 2-1-3
		ft_sa(stacks->a, "sa\n");
	first = stacks->a->nb;
	middle = stacks->a->next->nb;
	last = ft_dlstlast(stacks->a)->nb;
	if (first > middle && first > last && middle < last) // 3-1-2
		ft_ra(stacks, "ra\n");
	else if (first < middle && first > last) // 2-3-1
		ft_rra(stacks, "rra\n");
}

void	run_best_algo(t_stacks *stacks)
{
	if (stacks->size == 1)
		return ;
	else if (stacks->size <= 3)
		return (less_or_egal_three(stacks));
}
