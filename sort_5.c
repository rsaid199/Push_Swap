/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaid <rsaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:42:40 by rsaid             #+#    #+#             */
/*   Updated: 2023/04/09 04:51:08 by rsaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	push_swap_5(t_list **stack_a, t_list **stack_b, int position)
{
	int	i;

	i = lsize(*stack_a);
	if (position <= lsize(*stack_a))
	{
		if (position < (0.50 * lsize(*stack_a)))
		{
			while (position > 0)
			{
				ra(stack_a);
				position--;
			}
			pb(stack_a, stack_b);
		}
		else if (position >= (0.50 * lsize(*stack_a)))
		{
			while (position >= (0.50 * lsize(*stack_a)) && position < i)
			{
				rra(stack_a);
				position++;
			}
			pb(stack_a, stack_b);
		}
	}
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	t_sort	vars;

	vars.num = 0;
	vars.tmp = *stack_a;
	while (vars.tmp && lsize(*stack_b) != 2)
	{
		if (vars.tmp->index <= 2)
		{
			push_swap_5(stack_a, stack_b, vars.num);
			vars.tmp = *stack_a;
			vars.num = 0;
		}
		vars.tmp = vars.tmp->next;
		vars.num++;
		if (vars.tmp->next == NULL && vars.tmp->index > 2)
		{
			vars.tmp = *stack_a;
			vars.num = 0;
		}
	}
	if ((*stack_b)->content < (*stack_b)->next->content)
		sb(stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_3(t_list **stack)
{
	t_list	*tmp;
	int		num;

	tmp = *stack;
	num = checker_5(stack);
	if (num == 1)
		ra(stack);
	else if (num == 2)
		rra(stack);
	tmp = *stack;
	if (tmp->content > tmp->next->content)
		sa(stack);
}

int	checker_5(t_list **stack_b)
{
	int		num;
	int		num2;
	int		position;
	t_list	*tmp;

	position = 1;
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
