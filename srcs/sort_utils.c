/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:03:36 by user42            #+#    #+#             */
/*   Updated: 2021/05/31 10:56:26 by acastelb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_median(t_stacks *stacks)
{
	int		*values;
	int		i;
	t_dlist	*elem;

	values = malloc(sizeof(int) * stacks->size);
	if (!(values))
		return ;
	elem = stacks->a;
	i = -1;
	while (++i < stacks->size && elem)
	{
		values[i] = elem->nb;
		elem = elem->next;
	}
	sort_values(stacks->size, values);
	stacks->quart_size = stacks->size / 4;
	stacks->second_q = values[stacks->quart_size];
	stacks->median = values[stacks->size / 2];
	stacks->last_q = values[stacks->quart_size * 3];
	stacks->values = values;
}

int	get_nb_value(t_dlist *list, t_stacks *stacks, int pos)
{
	int	i;

	i = 0;
	while (list)
	{
		if (list->nb == stacks->values[pos])
			break ;
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

void	place_best_nb_on_top(t_stacks *stacks)
{
	int		mov_nb;
	void	(*fct)(t_stacks *, char *);
	char	*s;
	int		i;

	if (choose_best_nb(stacks, &mov_nb))
		fct = ft_rb;
	else
		fct = ft_rrb;
	if (fct == &ft_rb)
		s = "rb\n";
	else
		s = "rrb\n";
	i = -1;
	while (++i < mov_nb)
		fct(stacks, s);
}
