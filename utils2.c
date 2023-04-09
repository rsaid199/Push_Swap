/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaid <rsaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:22:38 by rsaid             #+#    #+#             */
/*   Updated: 2023/04/09 01:45:00 by rsaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	error(char *msg)
{
	write(2, msg, 6);
	exit(1);
}

void	clean_mem(t_mvars vars, char **argv)
{
	free_stack (vars.stack_a);
	free_stack (vars.stack_b);
	ft_free(argv);
	free(argv);
	free(vars.collect);
}

void	init_vars(t_mvars *vars, char **argv)
{
	space_null(argv);
	vars->stack_a = malloc(sizeof(t_list));
	vars->stack_b = malloc(sizeof(t_list));
	*vars->stack_a = NULL;
	*vars->stack_b = NULL;
	vars->i = 0;
	vars->x = 2;
	vars->collect = argv[1];
	vars->collect = ft_strjoin(vars->collect, " ", 0);
	vars->flag = 0;
}

void	free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}

int	ft_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else
			return (1);
	}
	if (str[i] == '\0')
		return (0);
	return (1);
}
