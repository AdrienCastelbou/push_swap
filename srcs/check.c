/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastelb <acastelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 09:27:33 by acastelb          #+#    #+#             */
/*   Updated: 2021/05/28 14:10:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int		nb_is_duplicate(t_dlist *a, int nb)
{
	while (a)
	{
		if (a->nb == nb)
			return (1);
		a = a->next;
	}
	return (0);
}

int		is_numeric_value(char *str)
{
	int i;

	i = 0;
	if (str[i] && !ft_isdigit(str[i]) && str[i] != '+' && str[i] != '-')
		return (0);
	while (str[i] && (str[i] == '+' || str[i] == '-'))
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	return (1);
}

int		stack_is_sorted(t_dlist *a)
{
	t_dlist	*elem;
	t_dlist	*to_cmp;

	elem = a;
	while (elem->next)
	{
		to_cmp = elem->next;
		while (to_cmp)
		{
			if (elem->nb > to_cmp->nb)
				return (0);
			to_cmp = to_cmp->next;
		}
		elem = elem->next;
	}
	return (1);
}

int		check_argvs(t_stacks *stacks, char **av)
{
	int	i;
	int	ret;

	ret = 1;
	i = 0;
	while (av[++i])
	{
		ret = get_av_elem(stacks, av[i]);
		if (ret == 0)
			break ;
	}
	if (ret == 0)
		ft_stacksclear(stacks);
	return (ret);
}

int		check_nb_validity(t_stacks *stacks, char *str, int i)
{
	if (!str[i] && !stacks->a)
		return (0);
	if (!is_numeric_value(str + i))
		return (0);
	if (str[i] && !ft_isdigit(str[i]) && str[i] != '+' && str[i] != '-')
		return (0);
	return (1);
}

int		check_and_add_nb(t_stacks *stacks, int nb)
{
	t_dlist *elem;

	elem = NULL;
	if (nb < INT_MIN || nb > INT_MAX || nb_is_duplicate(stacks->a, nb))
		return (0);
	if (!(elem = ft_dlstnew(nb)))
		return (0);
	ft_dlstadd_back(&(stacks->a), elem);
	return (1);
}

int		get_av_elem(t_stacks *stacks, char *str)
{
	long int	nb;
	int			i;

	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == 9 || str[i] == 32))
			i++;
		if (!str[i] && stacks->a)
			return (1);
		if (check_nb_validity(stacks, str, i) == 0)
			return (0);
		nb = ft_atoli(str + i);
		check_and_add_nb(stacks, nb);
		while (str[i] && (str[i] == '+' || str[i] == '-'))
			i++;
		while (str[i] && (ft_isdigit(str[i])))
			i++;
	}
	return (1);
}
