/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilla-c <smilla-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:17:24 by smilla-c          #+#    #+#             */
/*   Updated: 2026/02/20 11:46:56 by smilla-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long	sign;
	long	res;

	sign = 1;
	res = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (sign * res);
}

int	init_stack(t_stack *a, int argc, char **argv)
{
	int		i;
	long	n;

	a->top = NULL;
	a->size = 0;
	i = 1;
	while (i < argc)
	{
		n = ft_atol(argv[i]);
		if (n < -2147483648 || n > 2147483647)
			return (1);
		if (stack_add_back(a, (int)n))
			return (1);
		i++;
	}
	return (0);
}

int	check_invalid_args(int argc, char **argv)
{
	int		i;
	int		j;
	char	*s;

	i = 1;
	while (i < argc)
	{
		s = argv[i];
		j = 0;
		if (s[j] == '-' || s[j] == '+')
			j++;
		if (s[j] == '\0')
			return (1);
		while (s[j])
		{
			if (s[j] < '0' || s[j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_duplicates_args(int argc, char **argv)
{
	int		i;
	int		j;
	long	ni;
	long	nj;

	i = 1;
	while (i < argc)
	{
		ni = ft_atol(argv[i]);
		j = i + 1;
		while (j < argc)
		{
			nj = ft_atol(argv[j]);
			if (ni == nj)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	parse_args(int argc, char **argv, t_stack *a)
{
	if (check_invalid_args(argc, argv))
		return (1);
	if (check_duplicates_args(argc, argv))
		return (1);
	init_stack(a, argc, argv);
	return (0);
}
