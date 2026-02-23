/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilla-c <smilla-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:13:57 by smilla-c          #+#    #+#             */
/*   Updated: 2026/02/20 12:05:09 by smilla-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

// Función auxiliar: selecciona la estrategia según flag
static void	run_strategy(char *strategy, t_stack *a, t_stack *b)
{
	void	(*sort_fn)(t_stack*, t_stack*);

	sort_fn = adaptive_sort; // por defecto
	if (!ft_strcmp(strategy, "--simple"))
		sort_fn = simple_sort;
	else if (!ft_strcmp(strategy, "--medium"))
		sort_fn = medium_sort;
	else if (!ft_strcmp(strategy, "--complex"))
		sort_fn = radix_sort;

	sort_fn(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	*strategy;

	if (argc < 2)
		return (0);

	strategy = get_strategy(argc, argv);

	if (argc > 1 && argv[1][0] == '-')
	{
		argc--;
		argv++;
	}

	a.top = NULL;
	a.size = 0;
	b.top = NULL;
	b.size = 0;

	if (parse_args(argc, argv, &a))
		return (write(2, "Error\n", 6), 1);

	run_strategy(strategy, &a, &b);

	free_stack(&a);
	free_stack(&b);
	return (0);
}
