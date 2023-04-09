/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaid <rsaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:36:15 by rsaid             #+#    #+#             */
/*   Updated: 2023/04/09 01:44:52 by rsaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	ra(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*tmp_head;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	tmp = (*stack_a);
	stack_a[0] = (*stack_a)->next;
	tmp_head = stack_a[0];
	while (*stack_a)
	{
		if ((*stack_a)->next == NULL)
		{
			(*stack_a)->next = tmp;
			tmp->next = NULL;
		}
		*stack_a = (*stack_a)->next;
	}
	stack_a[0] = tmp_head;
	write (1, "ra\n", 3);
}	

void	rb(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmp_head;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	tmp = (*stack_b);
	stack_b[0] = (*stack_b)->next;
	tmp_head = stack_b[0];
	while (*stack_b)
	{
		if ((*stack_b)->next == NULL)
		{
			(*stack_b)->next = tmp;
			tmp->next = NULL;
		}
		*stack_b = (*stack_b)->next;
	}
	stack_b[0] = tmp_head;
	write (1, "rb\n", 3);
}

void	rra(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (*stack_a == NULL)
		return ;
	tmp = *stack_a;
	while (tmp->next)
	{
		tmp2 = tmp;
		tmp = tmp->next;
	}
	tmp->next = *stack_a;
	stack_a[0] = tmp;
	tmp2->next = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (*stack_b == NULL)
		return ;
	tmp = *stack_b;
	while (tmp->next)
	{
		tmp2 = tmp;
		tmp = tmp->next;
	}
	tmp->next = *stack_b;
	stack_b[0] = tmp;
	tmp2->next = NULL;
	write(1, "rrb\n", 4);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_a;
	t_list	**tmp_b;

	if (*stack_a == NULL)
		return ;
	tmp_a = *(stack_a);
	tmp_b = stack_b;
	*stack_a = (*stack_a)->next;
	tmp_a->next = NULL;
	ft_lstadd_front(tmp_b, tmp_a);
	stack_b = tmp_b;
	write(1, "pb\n", 3);
}
