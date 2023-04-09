/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaid <rsaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:39:56 by rsaid             #+#    #+#             */
/*   Updated: 2023/04/09 04:27:26 by rsaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	space_null(char **argv)
{
	int	i;
	int	j;

	j = 1;
	while (argv[j])
	{
		i = 0;
		while (argv[j][i] == ' ')
			i++;
		if (argv[j][i] == '\0')
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		j++;
	}
}

static void	loop_b(t_mvars *vars)
{
	while (*vars->stack_b)
	{
		vars->i = checker(vars->stack_b);
		push_swap(vars->stack_a, vars->stack_b, vars->i);
	}
}

void	sort3or5(t_list **stack_a, t_list **stack_b)
{
	if (lsize(*stack_a) == 5)
		sort_5(stack_a, stack_b);
	else if (lsize(*stack_a) == 3)
		sort_3(stack_a);
	else
		chunker(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_mvars	vars;

	if (argc == 1)
		return (0);
	init_vars(&vars, argv);
	while (vars.x < argc)
		vars.collect = ft_strjoin(vars.collect, argv[vars.x++], 1);
	argv = ft_split(vars.collect, ' ');
	vars.flag = check_args(argv);
	if (vars.flag == 0)
		return (clean_mem(vars, argv), write(2, "Error\n", 6));
	while (argv[vars.i])
	{
		vars.tmp = ft_lstnew(ft_atoi(argv[vars.i++]));
		ft_lstadd_back(vars.stack_a, vars.tmp);
	}
	is_sorted(vars, argv);
	indexer(vars.stack_a);
	sort3or5(vars.stack_a, vars.stack_b);
	loop_b(&vars);
	clean_mem(vars, argv);
}
