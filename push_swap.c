/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaid <rsaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:54:31 by rsaid             #+#    #+#             */
/*   Updated: 2023/03/30 03:30:50 by rsaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	push_swap(t_list **stack_a, t_list **stack_b, int position)
{
	int	i;

	i = lsize(*stack_b);
	if (position <= lsize(*stack_b))
	{
		if (position < (0.50 * lsize(*stack_b)))
		{
			while (position > 0)
			{
				rb(stack_b);
				position--;
			}
			pa(stack_a, stack_b);
		}
		else if (position >= (0.50 * lsize(*stack_b)))
		{
			while (position >= (0.50 * lsize(*stack_b)) && position < i)
			{
				rrb(stack_b);
				position++;
			}
			pa(stack_a, stack_b);
		}
	}
}

void	indexer(t_list **stack_a)
{
	int		counter;
	int		lst_size;
	int		num;
	t_list	*tmp;
	t_list	*tmp1;

	counter = 0;
	lst_size = lsize(*stack_a);
	tmp = *stack_a;
	tmp1 = *stack_a;
	while (tmp)
	{
		num = tmp->content;
		while (tmp1)
		{
			if (num < tmp1->content)
				counter++;
			tmp1 = tmp1->next;
		}
		tmp1 = *stack_a;
		tmp->index = lst_size - counter;
		counter = 0;
		tmp = tmp->next;
	}	
}

void	decide_ra_or_rra(t_chunkers	*vars, t_list **stack_a, t_list **stack_b)
{
	if (vars->c < (0.50 * lsize(*stack_a)))
		while (vars->c-- > 1)
			ra(stack_a);
	else if (vars->c >= (0.50 * lsize(*stack_a)))
		while (vars->c++ >= (0.50 * lsize(*stack_a))
			&& (vars->c < lsize(*stack_a)))
			rra(stack_a);
	pb(stack_a, stack_b);
	vars->tmp = *stack_a;
	vars->c = 0;
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (*stack_b == NULL)
		return ;
	else if (stack_b)
	{
		tmp = (*stack_b)->next;
		(*stack_b)->next = (*stack_a);
		stack_a[0] = (*stack_b);
		stack_b[0] = tmp;
	}
	write(1, "pa\n", 3);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
}
