/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaid <rsaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:48:16 by rsaid             #+#    #+#             */
/*   Updated: 2023/03/28 23:35:53 by rsaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

char	*ft_strjoin(char *s1, char *s2, int free_flag)
{
	t_join	vars;

	vars.i = 0;
	vars.s2i = 0;
	if (!s1 || !s2)
		return (NULL);
	vars.z = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!vars.z)
		return (NULL);
	while (s1[vars.i] != '\0')
	{
		vars.z[vars.i] = s1[vars.i];
		vars.i++;
	}
	while (s2[vars.s2i] != '\0')
	{
		vars.z[vars.i] = s2[vars.s2i];
		vars.i++;
		vars.s2i++;
	}
	vars.z[vars.i] = ' ';
	vars.z[++vars.i] = '\0';
	if (free_flag == 1)
		free(s1);
	return (vars.z);
}

long long	ft_atoi(const char *str)
{
	int		i;
	long	nb;
	int		neg;

	neg = 0;
	nb = 0;
	i = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		neg = 1;
	if (*str == '-' || *str == '+')
		str++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (str[i] - 48) + (10 * nb);
		i++;
	}
	if (neg == 1)
		nb = nb * -1;
	return (nb);
}

void	qoute_checker(char **argv)
{
	int	x;

	x = 0;
	while (argv[x])
	{
		if (!ft_strlen(argv[x]) || !ft_space(argv[x]))
			error("Error\n");
		x++;
	}
}
