/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastelb <acastelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:38:02 by acastelb          #+#    #+#             */
/*   Updated: 2021/05/24 16:50:09 by acastelb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_stacks	*ft_stacksnew(void)
{
	t_stacks	*stacks;

	if (!(stacks = malloc(sizeof(t_stacks))))
		return (NULL);
	stacks->a = NULL;
	stacks->b = NULL;
	return (stacks);
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

void	ft_stacksclear(t_stacks *stacks)
{
	if (!stacks)
		return ;
	ft_dlstclear(&(stacks->a), free);
	ft_dlstclear(&(stacks->b), free);
	free(stacks);
	stacks = NULL;
}

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

int		get_av_elem(t_stacks *stacks, char *str)
{
	t_dlist		*elem;
	long int	nb;
	int			i;

	elem = NULL;
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == 9 ||str[i] == 32))
			i++;
		if (!str[i] && !stacks->a)
			return (0);
		else if (!str[i] && stacks->a)
			return (1);
		if (!is_numeric_value(str + i))
			return (0);
		if (str[i] && !ft_isdigit(str[i]) && str[i] != '+' && str[i] != '-')
			return (0);
		nb = ft_atoli(str + i);
		if (nb < INT_MIN || nb > INT_MAX || nb_is_duplicate(stacks->a, nb))
			return (0);
		if (!(elem = ft_dlstnew(nb)))
			return (0);
		ft_dlstadd_back(&(stacks->a), elem);
		while (str[i] && (str[i] == '+' || str[i] == '-'))
			i++;
		while (str[i] && (ft_isdigit(str[i])))
			i++;
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

void	ft_sb(t_dlist *b)
{
	int	temp;

	if (!b || !b->next)
		return ;
	temp = b->nb;
	b->nb = b->next->nb;
	b->next->nb = temp;
}

void	ft_sa(t_dlist *a)
{
	int	temp;

	if (!a || !a->next)
		return ;
	temp = a->nb;
	a->nb = a->next->nb;
	a->next->nb = temp;
}

void	ft_ss(t_stacks *stacks)
{
	ft_sa(stacks->a);
	ft_sb(stacks->b);
}

void	ft_pb(t_stacks *stacks)
{
	t_dlist	*elem;
	if (!stacks->a)
		return ;
	elem = stacks->a->next;
	elem->prev = NULL;
	ft_dlstadd_front(&stacks->b, stacks->a);
	stacks->a = elem;
}

void	ft_pa(t_stacks *stacks)
{
	t_dlist	*elem;
	if (!stacks->b)
		return ;
	elem = stacks->b->next;
	if (elem)
		elem->prev = NULL;
	ft_dlstadd_front(&stacks->a, stacks->b);
	stacks->b = elem;
}

void	ft_ra(t_stacks *stacks)
{
	t_dlist *elem;

	if (!stacks->a || !stacks->a->next)
		return ;
	elem = stacks->a;
	stacks->a = elem->next;
	stacks->a->prev = NULL;
	elem->next = NULL;
	ft_dlstadd_back(&stacks->a, elem);
}

void	ft_rb(t_stacks *stacks)
{
	t_dlist *elem;

	if (!stacks->b || !stacks->b->next)
		return ;
	elem = stacks->b;
	stacks->b = elem->next;
	stacks->b->prev = NULL;
	elem->next = NULL;
	ft_dlstadd_back(&stacks->b, elem);
}

void	ft_rr(t_stacks *stacks)
{
	ft_ra(stacks);
	ft_rb(stacks);
}

void	ft_rra(t_stacks *stacks)
{
	t_dlist	*last;
	t_dlist	*elem;

	if (!stacks->a || !stacks->a->next)
		return ;
	elem = stacks->a;
	while (elem->next->next)
		elem = elem->next;
	last = elem->next;
	last->prev = NULL;
	elem->next = NULL;
	ft_dlstadd_front(&stacks->a, last);
}

void	ft_rrb(t_stacks *stacks)
{
	t_dlist	*last;
	t_dlist	*elem;

	if (!stacks->b || !stacks->b->next)
		return ;
	elem = stacks->b;
	while (elem->next->next)
		elem = elem->next;
	last = elem->next;
	last->prev = NULL;
	elem->next = NULL;
	ft_dlstadd_front(&stacks->b, last);
}

void	ft_rrr(t_stacks *stacks)
{
	ft_rrb(stacks);
	ft_rra(stacks);
}

void	ft_show_stack(t_dlist *lst)
{
	while (lst)
	{
		printf("%d\n", lst->nb);
		lst = lst->next;
	}
	printf("---\n");
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
		ft_sa(stacks->a); // 3-1-2 
	else if (first > middle && middle > last) // 3-2-1
		ft_sa(stacks->a); //2-3-1
	else if (middle == last || (first > middle && first < last)) // 2-1-3
		ft_sa(stacks->a);
	first = stacks->a->nb;
	middle = stacks->a->next->nb;
	last = ft_dlstlast(stacks->a)->nb;
	if (first > middle && first > last && middle < last) // 3-1-2
		ft_ra(stacks);
	else if (first < middle && first > last) // 2-3-1
		ft_rra(stacks);
}

t_dlist *a_partition(t_stacks *stacks, t_dlist *head, t_dlist *last, t_dlist **n_last)
{
	if (!head || !last)
		return (NULL);
	if (stacks->a != head)
	{
		while (stacks->a != head)
		{
			ft_pb(stacks);
			ft_putstr_fd("pb\n", STDOUT_FILENO);
		}
	}
	while (stacks->a != last)
	{
		if (stacks->a->nb < last->nb)
		{
			ft_pb(stacks);
			ft_putstr_fd("pb\n", STDOUT_FILENO);
		}
		else
		{
			*n_last = stacks->a;
			ft_ra(stacks);
			ft_putstr_fd("ra\n", STDOUT_FILENO);
		}
	}
	return (last);
}

t_dlist *b_partition(t_stacks *stacks, t_dlist *head, t_dlist *last, t_dlist **n_last)
{
	if (!head || !head || !last)
		return (NULL);
	if (stacks->b != head)
	{
		while (stacks->b && stacks->b != head)
		{
			ft_pa(stacks);
			ft_putstr_fd("pa\n", STDOUT_FILENO);
		}
	}
	while (stacks->b && stacks->b != last)
	{
		if (stacks->b->nb > last->nb)
		{
			ft_pa(stacks);
			ft_putstr_fd("pa\n", STDOUT_FILENO);
		}
		else
		{
			*n_last = stacks->b;
			ft_rb(stacks);
			ft_putstr_fd("rb\n", STDOUT_FILENO);
		}
	}
	return (last);

}

void	lquick_sort(t_stacks *stacks, t_dlist *a_head, t_dlist *a_last, t_dlist *b_head, t_dlist *b_last)
{
	t_dlist	*a_pivot;
	t_dlist	*b_pivot;
	t_dlist	*na_last;
	t_dlist	*nb_last;

	if ((!a_head || !a_last || a_head == a_last) && (!b_head || !b_last || b_head == b_last))
		return ;
	if (a_last && a_head == a_last->next && b_last && b_head == b_last->next)
		return ;
	na_last = NULL;
	nb_last = NULL;
	a_pivot = a_partition(stacks, a_head, a_last, &na_last);
	if (b_head == NULL)
		b_head = stacks->b;
	if (b_last == NULL)
		b_last = ft_dlstlast(b_head);
	b_pivot = b_partition(stacks, b_head, b_last, &nb_last);
	if (a_pivot && b_pivot)
		lquick_sort(stacks, stacks->a, a_pivot->prev, stacks->b, b_pivot->prev);
	else if (!b_pivot)
		lquick_sort(stacks, stacks->a, a_pivot->prev, stacks->b, b_pivot);
	if (a_pivot && b_pivot)
		lquick_sort(stacks, a_pivot->next, na_last, b_pivot->next, nb_last);
	else if (!b_pivot)
		lquick_sort(stacks, a_pivot->next, na_last, b_pivot, nb_last);
}

void	set_lquick_sort(t_stacks *stacks)
{
	t_dlist	*a_head;
	t_dlist	*a_last;
	t_dlist	*b_head;
	t_dlist	*b_last;

	a_head = stacks->a;
	a_last = ft_dlstlast(a_head);
	b_head = stacks->b;
	b_last = ft_dlstlast(b_head);
	lquick_sort(stacks, a_head, a_last, b_head, b_last);
	if (stacks->b)
	{
		ft_pa(stacks);
		ft_putstr_fd("pa\n", STDOUT_FILENO);
	}
}

void	run_best_algo(t_stacks *stacks)
{
	if (stacks->size == 1)
		return ;
	else if (stacks->size <= 3)
		return (less_or_egal_three(stacks));
	else
		set_lquick_sort(stacks);
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
	stacks->size = ft_dlstsize(stacks->a);
	//ft_show_stack(stacks->a);
	set_lquick_sort(stacks);
	//ft_show_stack(stacks->a);
	ft_stacksclear(stacks);
}
