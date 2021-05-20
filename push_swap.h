/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastelb <acastelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:52:14 by acastelb          #+#    #+#             */
/*   Updated: 2021/05/20 09:14:42 by acastelb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

typedef struct s_dlist {
	int				nb;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}				t_dlist;

typedef struct	s_stacks {
	t_dlist	*a;
	t_dlist	*b;
	int		size;
}				t_stacks;

int	ft_dlstsize(t_dlist *dlst);
t_dlist	*ft_dlstnew(int content);
t_dlist	*ft_dlstlast(t_dlist *dlst);
void	ft_dlstclear(t_dlist **dlst, void (*del)(void *));
void	ft_dlstdelone(t_dlist *dlst, void (*del)(void *));
void	ft_dlstadd_front(t_dlist **adlst, t_dlist *new);
void	ft_dlstadd_back(t_dlist **adlst, t_dlist *new);
