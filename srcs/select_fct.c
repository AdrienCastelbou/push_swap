/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_fct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 14:31:16 by user42            #+#    #+#             */
/*   Updated: 2021/05/29 09:46:23 by acastelb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fct_for_mini_maxi_less_med(int *choice, int mini_pos, int maxi_pos)
{
	if (mini_pos < maxi_pos)
		*choice = mini_pos;
	else
		*choice = maxi_pos;
	return (1);
}

int	fct_for_mini_maxi_sup_med(int *choice, int mini_pos,
		int maxi_pos, int stack_size)
{
	if (mini_pos > maxi_pos)
		*choice = stack_size - mini_pos;
	else
		*choice = stack_size - maxi_pos;
	return (0);
}

int	fct_for_only_mini_less_med(int *choice, int mini_pos,
			int maxi_pos, int stack_size)
{
	if (mini_pos < (stack_size - maxi_pos))
	{
		*choice = mini_pos;
		return (1);
	}
	else
	{
		*choice = stack_size - maxi_pos;
		return (0);
	}
}

int	fct_for_last_cases(int *choice, int mini_pos, int maxi_pos, int stack_size)
{
	if (maxi_pos < (stack_size - mini_pos))
	{
		*choice = maxi_pos;
		return (1);
	}
	else
	{
		*choice = stack_size - mini_pos;
		return (0);
	}
}

int	choose_best_nb(t_stacks *stacks, int *choice)
{
	int	mini_pos;
	int	maxi_pos;
	int	stack_size;

	stack_size = ft_dlstsize(stacks->b);
	mini_pos = get_mini_pos(stacks->b);
	maxi_pos = get_maxi_pos(stacks->b);
	if (mini_pos < stack_size / 2 && maxi_pos < stack_size / 2)
		return (fct_for_mini_maxi_less_med(choice, mini_pos, maxi_pos));
	else if (mini_pos >= stack_size / 2 && maxi_pos >= stack_size / 2)
		return (fct_for_mini_maxi_sup_med(choice, mini_pos,
					maxi_pos, stack_size));
	else if (mini_pos < stack_size / 2 && maxi_pos >= stack_size / 2)
		return (fct_for_only_mini_less_med(choice, mini_pos,
					maxi_pos, stack_size));
	else
		return (fct_for_last_cases(choice, mini_pos,
					maxi_pos, stack_size));
}
