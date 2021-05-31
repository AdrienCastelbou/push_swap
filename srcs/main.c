/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastelb <acastelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:38:02 by acastelb          #+#    #+#             */
/*   Updated: 2021/05/31 10:54:18 by acastelb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_less_on_top(t_stacks *stacks, int n)
{
	if (get_nb_value(stacks->a, stacks, n) < (stacks->size / 2))
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
	if (stack_is_sorted(stacks->a))
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

int	main(int ac, char **argv)
{
	t_stacks	*stacks;

	stacks = NULL;
	if (ac == 1)
		return (0);
	stacks = ft_stacksnew();
	if (!(stacks))
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (1);
	}
	if (!check_argvs(stacks, argv))
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (1);
	}
	get_stack_infos(stacks);
	run_best_algo(stacks);
	ft_stacksclear(stacks);
	return (0);
}
