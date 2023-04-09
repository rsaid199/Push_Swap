/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaid <rsaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:22:43 by rsaid             #+#    #+#             */
/*   Updated: 2023/04/09 04:49:06 by rsaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct main_vars
{
	t_list	**stack_a;
	t_list	**stack_b;
	t_list	*tmp;
	int		i;
	char	*collect;
	int		x;
	int		flag;
}		t_mvars;

typedef struct check_vars
{
	int		i;
	long	tmp;
	char	**args;
	int		x;
}		t_cvars;

typedef struct strjoin
{
	int		i;
	int		s2i;
	char	*z;
}		t_join;

typedef struct chunker
{
	t_list	*tmp;
	int		c;
	int		i;
	int		limit;
	int		index;
}		t_chunkers;

typedef struct sort_vars
{
	t_list	*tmp;
	int		num;
}		t_sort;

void		sa(t_list **stack_a);
void		sb(t_list **stack_b);
void		ss(t_list **stack_a, t_list **stack_b);
long long	ft_atoi(const char *str);
void		ft_lstadd_back(t_list **lst, t_list *new);
t_list		*ft_lstlast(t_list *lst);
int			lsize(t_list *lst);
t_list		*ft_lstnew(int content);
void		pa(t_list **stack_a, t_list **stack_b);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		pb(t_list **stack_a, t_list **stack_b);
void		ra(t_list **stack_a);
void		rb(t_list **stack_b);
void		rr(t_list **stack_a, t_list **stack_b);
void		rra(t_list **stack_a);
void		rrb(t_list **stack_a);
void		push_swap(t_list **stack_a, t_list **stack_b, int index);
int			checker(t_list **stack_b);
void		indexer(t_list **stack_a);
void		chunker(t_list **stack_a, t_list **stack_b);
int			wordcounter(const char *s, char c);
char		*maker(const char *x, int start, int end);
char		**ft_split(char const *s, char c);
void		error(char *msg);
int			check_args(char **argv);
void		ft_free(char **str);
size_t		ft_strlen(const char *s);
void		free_stack(t_list **stack);
void		qoute_checker(char **argv);
int			limit_detect(int i);
char		*ft_strjoin(char *s1, char *s2, int free_flag);
void		clean_mem(t_mvars vars, char **argv);
void		init_vars(t_mvars *vars, char **argv);
void		decide_ra_or_rra(t_chunkers	*vars,
				t_list **stack_a, t_list **stack_b);
int			ft_space(char *str);
void		is_sorted(t_mvars vars, char **argv);
void		sort_5(t_list **stack_a, t_list **stack_b);
int			checker_5(t_list **stack_b);
void		push_swap_5(t_list **stack_a, t_list **stack_b, int position);
void		sort_3(t_list **stack);
int			check_args_checker(char **args, int i);
void		space_null(char **argv);
void		sort3or5(t_list **stack_a, t_list **stack_b);

#endif
