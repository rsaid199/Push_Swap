/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaid <rsaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:55:39 by rsaid             #+#    #+#             */
/*   Updated: 2023/03/28 20:44:50 by rsaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	wordcounter(const char *s, char c)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			x++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (x);
}

char	*maker(const char *x, int start, int end)
{
	char	*z;
	int		i;

	i = 0;
	z = malloc(sizeof(char) * (end - start) + 1);
	while (start < end)
	{
		z[i] = x[start];
		start++;
		i++;
	}
	z[i] = 0;
	return (z);
}

char	**ft_split(char const *s, char c)
{
	char	**splitret;
	int		dpcounter;
	int		start;
	size_t	end;

	if (!s)
		return (NULL);
	splitret = malloc((wordcounter(s, c) + 1) * sizeof(char *));
	if (!splitret)
		return (0);
	dpcounter = 0;
	start = -1;
	end = -1;
	while (++end <= ft_strlen(s))
	{
		if (s[end] != c && start < 0)
			start = end;
		else if ((s[end] == c || end == ft_strlen(s)) && start >= 0)
		{
			splitret[dpcounter++] = maker(s, start, end);
			start = -1;
		}
	}
	splitret[dpcounter] = 0;
	return (splitret);
}
