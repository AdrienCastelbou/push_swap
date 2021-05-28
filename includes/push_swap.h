/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastelb <acastelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:52:14 by acastelb          #+#    #+#             */
/*   Updated: 2021/05/28 14:37:51 by user42           ###   ########.fr       */
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
	int		quart_size;
	int		second_q;
	int		median;
	int		last_q;
	int		*values;
}				t_stacks;


void	ft_stacksclear(t_stacks *stacks);
long int	ft_atoli(const char *str);
int		nb_is_duplicate(t_dlist *a, int nb);
int		is_numeric_value(char *str);
int		stack_is_sorted(t_dlist *a);
int		check_argvs(t_stacks *stacks, char **av);
int		get_av_elem(t_stacks *stacks, char *str);
int	ft_dlstsize(t_dlist *dlst);
t_dlist	*ft_dlstnew(int content);
t_dlist	*ft_dlstlast(t_dlist *dlst);
void	ft_dlstclear(t_dlist **dlst, void (*del)(void *));
void	ft_dlstdelone(t_dlist *dlst, void (*del)(void *));
void	ft_dlstadd_front(t_dlist **adlst, t_dlist *new);
void	ft_dlstadd_back(t_dlist **adlst, t_dlist *new);


void	ft_sb(t_dlist *b, char *s);
void	ft_sa(t_dlist *a, char *s);
void	ft_ss(t_stacks *stacks, char *s);
void	ft_pb(t_stacks *stacks, char *s);
void	ft_pa(t_stacks *stacks, char *s);
void	ft_ra(t_stacks *stacks, char *s);
void	ft_rb(t_stacks *stacks, char *s);
void	ft_rr(t_stacks *stacks, char *s);
void	ft_rra(t_stacks *stacks, char *s);
void	ft_rrb(t_stacks *stacks, char *s);
void	ft_rrr(t_stacks *stacks, char *s);

void	ft_show_stack(t_dlist *lst);
void	ft_stacksclear(t_stacks *stacks);
t_stacks	*ft_stacksnew(void);
void	less_or_egal_three(t_stacks *stacks);
void	run_best_algo(t_stacks *stacks);
void	(*fct_for_mini_maxi_less_med(int *choice, int mini_pos,
			int maxi_pos)) (t_stacks *, char *s);
void	(*fct_for_mini_maxi_sup_med(int *choice, int mini_pos,
			int maxi_pos, int stack_size)) (t_stacks *, char *s);
void	(*fct_for_only_mini_less_med(int *choice, int mini_pos,
			int maxi_pos, int stack_size)) (t_stacks *, char *s);
void	(*fct_for_last_cases(int *choice, int mini_pos, int maxi_pos,
			int stack_size)) (t_stacks *, char *s);
void	(*choose_best_nb(t_stacks *stacks, int *choice)) (t_stacks *, char *s);
int	get_maxi_pos(t_dlist *list);
int	get_mini_pos(t_dlist *list);
