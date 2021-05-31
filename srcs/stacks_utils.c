/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastelb <acastelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 09:38:43 by acastelb          #+#    #+#             */
/*   Updated: 2021/05/31 11:12:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*ft_stacksnew(void)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (!(stacks))
		return (NULL);
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->values = NULL;
	return (stacks);
}

void	ft_stacksclear(t_stacks *stacks)
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
