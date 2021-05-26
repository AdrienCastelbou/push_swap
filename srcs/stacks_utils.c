/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastelb <acastelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 09:38:43 by acastelb          #+#    #+#             */
/*   Updated: 2021/05/26 09:41:11 by acastelb         ###   ########.fr       */
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

void	ft_show_stack(t_dlist *lst)
{
	while (lst)
	{
		printf("%d\n", lst->nb);
		lst = lst->next;
	}
	printf("---\n");
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
