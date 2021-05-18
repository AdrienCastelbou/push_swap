/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastelb <acastelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:37:10 by acastelb          #+#    #+#             */
/*   Updated: 2021/05/18 10:47:34 by acastelb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*elem;
	t_list	*mlst;

	if (!(lst) || !(elem = ft_lstnew(f(lst->nb))))
		return (NULL);
	mlst = elem;
	lst = lst->next;
	while (lst)
	{
		if (!(elem = ft_lstnew(f(lst->nb))))
		{
			ft_lstclear(&mlst, del);
			return (mlst);
		}
		ft_lstadd_back(&mlst, elem);
		lst = lst->next;
	}
	return (mlst);
}
