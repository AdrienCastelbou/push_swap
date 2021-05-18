/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastelb <acastelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:38:02 by acastelb          #+#    #+#             */
/*   Updated: 2021/05/18 14:16:13 by acastelb         ###   ########.fr       */
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
	ft_lstclear(&(stacks->a), free);
	ft_lstclear(&(stacks->b), free);
	free(stacks);
	stacks = NULL;
}

int		nb_is_duplicate(t_list *a, int nb)
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
	t_list		*elem;
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
		if (!(elem = ft_lstnew(nb)))
			return (0);
		ft_lstadd_back(&(stacks->a), elem);
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

void	ft_sb(t_list *b)
{
	int	temp;

	if (!b || !b->next)
		return ;
	temp = b->nb;
	b->nb = b->next->nb;
	b->next->nb = temp;
	printf("sb\n");
}

void	ft_sa(t_list *a)
{
	int	temp;

	if (!a || !a->next)
		return ;
	temp = a->nb;
	a->nb = a->next->nb;
	a->next->nb = temp;
	printf("sa\n");
}

void	ft_ss(t_stacks *stacks)
{
	ft_sa(stacks->a);
	ft_sb(stacks->b);
	printf("ss\n");
}

void	ft_pb(t_stacks *stacks)
{
	t_list	*elem;
	if (!stacks->a)
		return ;
	elem = stacks->a->next;
	ft_lstadd_front(&stacks->b, stacks->a);
	stacks->a = elem;
	printf("pb\n");
}

void	ft_pa(t_stacks *stacks)
{
	t_list	*elem;
	if (!stacks->b)
		return ;
	elem = stacks->b->next;
	ft_lstadd_front(&stacks->a, stacks->b);
	stacks->b = elem;
	printf("pa\n");
}

void	ft_show_stack(t_list *lst)
{
	while (lst)
	{
		printf("%d\n", lst->nb);
		lst = lst->next;
	}
	printf("---\n");
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
	ft_show_stack(stacks->a);
	ft_pb(stacks);
ft_pa(stacks);
	ft_show_stack(stacks->a);
	ft_show_stack(stacks->b);
}
