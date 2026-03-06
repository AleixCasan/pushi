/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecasan <alecasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:13:57 by smilla-c          #+#    #+#             */
/*   Updated: 2026/03/06 14:00:00 by alecasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"

static void	run_strategy(char *s, t_stack *a, t_stack *b, t_bench *bench)
{
	if (!ft_strcmp(s, "--simple"))
		simple_sort(a, b, bench);
	else if (!ft_strcmp(s, "--medium"))
		medium_sort(a, b, bench);
	else if (!ft_strcmp(s, "--complex"))
		radix_sort(a, b, bench);
	else
		adaptive_sort(a, b, bench);
}

static void	bench_set(t_bench *bench, char *s)
{
	if (!ft_strcmp(s, "--simple"))
	{
		bench->strategy_name = "Simple";
		bench->complexity = "O(n^2)";
	}
	else if (!ft_strcmp(s, "--medium"))
	{
		bench->strategy_name = "Medium";
		bench->complexity = "O(n√n)";
	}
	else if (!ft_strcmp(s, "--complex"))
	{
		bench->strategy_name = "Complex";
		bench->complexity = "O(n log n)";
	}
	else
	{
		bench->strategy_name = "Adaptive";
		bench->complexity = "O(n log n)";
	}
}

static int	setup(int *ac, char ***av, t_stack *a, t_stack *b)
{
	a->top = NULL;
	a->size = 0;
	b->top = NULL;
	b->size = 0;
	if (*ac > 1 && (*av)[1][0] == '-' && (*av)[1][1] == '-')
	{
		(*ac)--;
		(*av)++;
	}
	if (parse_and_init(*ac, *av, a))
		return (write(2, "Error\n", 6), 1);
	return (0);
}

static void	bench_run(t_bench *bench, char *s, t_stack *a)
{
	bench->initial_size = a->size;
	bench_set(bench, s);
	bench_calculate_disorder_stack(bench, a);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_bench	bench;
	char	*strategy;

	if (argc < 2)
		return (0);
	bench_init(&bench, 0);
	if (argc > 1 && !ft_strcmp(argv[1], "--bench"))
	{
		bench.enabled = 1;
		argc--;
		argv++;
	}
	strategy = get_strategy(argc, argv);
	if (setup(&argc, &argv, &a, &b))
		return (1);
	if (bench.enabled)
		bench_run(&bench, strategy, &a);
	run_strategy(strategy, &a, &b, &bench);
	if (bench.enabled)
		bench_print(&bench);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
