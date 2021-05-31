/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastelb <acastelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 17:34:02 by acastelb          #+#    #+#             */
/*   Updated: 2021/05/31 10:23:30 by acastelb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*elem;

	if (!alst)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	elem = *alst;
	while (elem->next)
		elem = elem->next;
	elem->next = new;
}
