/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:11:45 by user42            #+#    #+#             */
/*   Updated: 2021/06/01 09:06:05 by acastelb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_nb_validity(t_stacks *stacks, char *str, int i)
{
	int	j;

	j = 0;
	if (!str[i] && !stacks->a)
		return (0);
	if (!is_numeric_value(str + i))
		return (0);
	if (str[i] && !ft_isdigit(str[i]) && str[i] != '+' && str[i] != '-')
		return (0);
	while (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i + j]))
		j++;
	if (j > 10)
		return (0);
	return (1);
}

int	check_and_add_nb(t_stacks *stacks, long int nb)
{
	t_dlist	*elem;

	elem = NULL;
	if (nb < INT_MIN || nb > INT_MAX || nb_is_duplicate(stacks->a, nb))
		return (0);
	elem = ft_dlstnew(nb);
	if (!(elem))
		return (0);
	ft_dlstadd_back(&(stacks->a), elem);
	return (1);
}
