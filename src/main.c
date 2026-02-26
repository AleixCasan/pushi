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

static void	init_stacks(t_stack *a, t_stack *b)
{
	a->top = NULL;
	a->size = 0;
	b->top = NULL;
	b->size = 0;
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_bench	bench;
	char	*strategy;
	int		size;

	if (argc < 2)
		return (0);
	bench_init(&bench, &size);
	size = 0;
	if (!ft_strcmp(argv[1], "--bench"))
	{
		bench.enabled = 1;
		argc--;
		argv++;
	}
	strategy = get_strategy(argc, argv);
	if (argv[1][0] == '-' && argv[1][1] == '-')
	{
		argc--;
		argv++;
	}
	size = argc - 1;
	init_stacks(&a, &b);
	if (parse_and_init(argc, argv, &a))
		return (write(2, "Error\n", 6), 1);
	if (bench.enabled)
		bench_calculate_disorder_stack(&bench, &a);
	run_strategy(strategy, &a, &b, &bench);
	bench_print(&bench);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
