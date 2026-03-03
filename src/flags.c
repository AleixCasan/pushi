/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilla-c <smilla-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:51:17 by smilla-c          #+#    #+#             */
/*   Updated: 2026/02/20 12:51:36 by smilla-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
** Compares two strings and returns 0 if equal,
** positive if s1 > s2, negative if s1 < s2.
*/

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
/*
** Determines the sorting strategy based on command-line flags.
** Returns the strategy string or exits with error if unknown flag.
*/

char	*get_strategy(int argc, char **argv)
{
	if (argc > 1 && argv[1][0] == '-' && argv[1][1] == '-')
	{
		if (!ft_strcmp(argv[1], "--simple"))
			return ("--simple");
		if (!ft_strcmp(argv[1], "--medium"))
			return ("--medium");
		if (!ft_strcmp(argv[1], "--complex"))
			return ("--complex");
		if (!ft_strcmp(argv[1], "--adaptive"))
			return ("--adaptive");
		if (!ft_strcmp(argv[1], "--bench"))
			return ("--bench");
		write(2, "Error\n", 6);
		exit(1);
	}
	return ("--adaptive");
}
