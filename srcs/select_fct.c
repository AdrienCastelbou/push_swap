/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_fct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 14:31:16 by user42            #+#    #+#             */
/*   Updated: 2021/05/28 14:32:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	(*fct_for_mini_maxi_less_med(int *choice, int mini_pos,
			int maxi_pos)) (t_stacks *, char *s)
{
	if (mini_pos < maxi_pos)
		*choice = mini_pos;
	else
		*choice = maxi_pos;
	return (&ft_rb);
}

void	(*fct_for_mini_maxi_sup_med(int *choice, int mini_pos,
			int maxi_pos, int stack_size)) (t_stacks *, char *s)
{
	if (mini_pos > maxi_pos)
		*choice = stack_size - mini_pos;
	else
		*choice = stack_size - maxi_pos;
	return (&ft_rrb);
}

void	(*fct_for_only_mini_less_med(int *choice, int mini_pos,
			int maxi_pos, int stack_size)) (t_stacks *, char *s)
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

void	(*fct_for_last_cases(int *choice, int mini_pos, int maxi_pos,
			int stack_size)) (t_stacks *, char *s)
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

void	(*choose_best_nb(t_stacks *stacks, int *choice)) (t_stacks *, char *s)
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
