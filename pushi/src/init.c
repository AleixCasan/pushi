/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilla-c <smilla-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 10:45:00 by smilla-c          #+#    #+#             */
/*   Updated: 2026/02/25 10:45:00 by smilla-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
** Checks if the given string contains any space character.
** Returns 1 if a space is found, 0 otherwise.
*/

static int	contains_space(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}
/*
** Parses command-line arguments and initializes stack A.
** Handles both multiple arguments and single argument with spaces.
** Returns 1 if an error occurs.
*/

int	parse_and_init(int argc, char **argv, t_stack *a)
{
	int	ret;

	ret = 0;
	if (argc == 2)
	{
		if (contains_space(argv[1]))
		{
			ret = handle_single_argument(argv[1], a);
			if (ret == 1)
				return (1);
			if (ret == 2)
				return (0);
			return (0);
		}
	}
	if (parse_args(argc, argv, a))
		return (1);
	return (0);
}
