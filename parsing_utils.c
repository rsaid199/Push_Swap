/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaid <rsaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 05:09:25 by rsaid             #+#    #+#             */
/*   Updated: 2023/04/08 22:20:17 by rsaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-' || num[0] == '+')
		i++;
	if (ft_strlen(num) == 1 && !ft_isdigit(num[0]))
		return (0);
	while (num[i])
	{
		if (!ft_isdigit(num[i]) && num[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

static int	contains(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

int	check_args(char **argv)
{
	t_cvars	vars;
	int		x;

	vars.i = 0;
	x = check_args_checker(argv, vars.i);
	return (x);
}

int	check_args_checker(char **args, int i)
{
	long	tmp;

	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!ft_isnum(args[i]))
			return (0);
		if (contains(tmp, args, i))
			return (0);
		if (tmp < -2147483648 || tmp > 2147483647)
			return (0);
		i++;
	}
	return (1);
}
