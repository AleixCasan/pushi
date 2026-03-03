/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecasan <alecasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:13:57 by smilla-c          #+#    #+#             */
/*   Updated: 2026/02/26 11:27:25 by alecasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"
/*
** Selects the sorting strategy based on the given flag
** and executes the corresponding sorting function.
*/
static void	run_strategy(char *strategy, t_stack *a, t_stack *b, t_bench *bench)
{
	void	(*sort_fn)(t_stack*, t_stack*, t_bench*);

	sort_fn = adaptive_sort;
	if (!ft_strcmp(strategy, "--simple"))
		sort_fn = simple_sort;
	else if (!ft_strcmp(strategy, "--medium"))
		sort_fn = medium_sort;
	else if (!ft_strcmp(strategy, "--complex"))
		sort_fn = radix_sort;
	sort_fn(a, b, bench);
}
/*
** Initializes both stacks by setting them empty
** (no elements and size equal to zero).
*/

static void	init_stacks(t_stack *a, t_stack *b)
{
	a->top = NULL;
	a->size = 0;
	b->top = NULL;
	b->size = 0;
}
/*
** Detects the --bench flag, enables benchmark mode
** and adjusts argc/argv to ignore the flag.
*/

static int	handle_bench_flag(int *argc, char ***argv, t_bench *bench)
{
	if (*argc > 1 && !ft_strcmp((*argv)[1], "--bench"))
	{
		bench->enabled = 1;
		(*argc)--;
		(*argv)++;
		return (1);
	}
	return (0);
}
/*
** Initializes stacks and parses input arguments.
** Returns 1 if an error occurs during parsing.
*/

static int	setup_stacks(int argc, char **argv, t_stack *a, t_stack *b)
{
	init_stacks(a, b);
	if (parse_and_init(argc, argv, a))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}
/*
** Entry point of the program.
** Parses arguments, initializes stacks, selects strategy,
** runs the sorting algorithm and handles benchmark mode.
*/

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_bench	bench;
	char	*strategy;

	if (argc < 2)
		return (0);
	bench_init(&bench, argc - 1);
	handle_bench_flag(&argc, &argv, &bench);
	strategy = get_strategy(argc, argv);
	if (setup_stacks(argc, argv, &a, &b))
		return (1);
	if (bench.enabled)
		bench_calculate_disorder_stack(&bench, &a);
	run_strategy(strategy, &a, &b, &bench);
	if (bench.enabled)
		bench_print(&bench);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
