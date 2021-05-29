/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastelb <acastelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 09:38:43 by acastelb          #+#    #+#             */
/*   Updated: 2021/05/29 11:12:47 by user42           ###   ########.fr       */
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
	stacks->values = NULL;
	return (stacks);
}

void		ft_show_stack(t_dlist *lst)
{
	while (lst)
	{
		printf("%d\n", lst->nb);
		lst = lst->next;
	}
	printf("---\n");
}

void		ft_stacksclear(t_stacks *stacks)
{
	if (!stacks)
		return ;
	if (stacks->a)
		ft_dlstclear(&(stacks->a), free);
	if (stacks->b)
		ft_dlstclear(&(stacks->b), free);
	if (stacks->values)
		free(stacks->values);
	free(stacks);
	stacks = NULL;
}
