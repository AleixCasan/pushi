/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilla-c <smilla-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:13:57 by smilla-c          #+#    #+#             */
/*   Updated: 2026/02/17 12:34:51 by smilla-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_invalid_args(int argc, char **argv)
{
	int		i;
	int		j;
	char 	*s;

	i = 0;
	while (i < argc)
	{
		*s = argv[i];
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
	}
}

void	check_duplicates_args(int argc, char **argv)
{
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack b;

	if (argc < 2)
		return (write(2, "Error\n", 6),1);
	if (check_invalid_args(argc, argv))
		return (write(2, "Error\n", 6),1);
	if (check_duplicates_args(argc, argv))
		return (write(2, "Error\n", 6),1);

	init_stack(&a, argc, argv);
	init_stack(&b, 0, NULL);

	select_strategy(&a, &b, argc, argv);

	free_stack(&a);
	free_stack(&b);
	return (0);
}
