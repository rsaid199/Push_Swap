/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunking_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaid <rsaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 05:39:19 by rsaid             #+#    #+#             */
/*   Updated: 2023/03/30 01:39:28 by rsaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

int	checker(t_list **stack_b)
{
	int		num;
	int		num2;
	int		position;
	t_list	*tmp;

	position = 0;
	tmp = *stack_b;
	num = tmp->content;
	while (tmp)
	{
		num2 = tmp->content;
		if (num < num2)
			num = num2;
		tmp = tmp->next;
	}
	tmp = *stack_b;
	while (tmp->next)
	{
		if (tmp->content == num)
			break ;
		position++;
		tmp = tmp->next;
	}
	return (position);
}

void	chunker(t_list **stack_a, t_list **stack_b)
{
	t_chunkers	vars;

	vars.i = lsize(*stack_a);
	vars.c = 0;
	vars.tmp = *stack_a;
	vars.limit = limit_detect(vars.i);
	vars.index = vars.limit;
	while (vars.tmp)
	{
		if (vars.tmp->index <= vars.limit)
			decide_ra_or_rra(&vars, stack_a, stack_b);
		else
			vars.tmp = vars.tmp->next;
		vars.c++;
		if ((vars.tmp) && (vars.tmp->next == NULL)
			&& (vars.tmp->index > vars.limit) && (vars.limit < vars.i))
		{
			vars.limit += vars.index;
			vars.tmp = *stack_a;
			vars.c = 0;
		}
	}
}

int	limit_detect(int i)
{
	int	limit;

	if (i <= 100)
		limit = 20;
	else
		limit = 50;
	return (limit);
}

void	is_sorted(t_mvars vars, char **argv)
{
	t_list	*tmp;
	int		num;
	int		num2;

	tmp = *vars.stack_a;
	if (lsize(*vars.stack_a) == 1)
	{
		clean_mem(vars, argv);
		exit (0);
	}
	while (tmp)
	{
		num = tmp->content;
		if (tmp->next != NULL)
			num2 = tmp->next->content;
		if (num > num2)
			return ;
		tmp = tmp->next;
	}
	clean_mem(vars, argv);
	exit (0);
}
