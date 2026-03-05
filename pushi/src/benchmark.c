/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecasan <alecasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:17:24 by smilla-c          #+#    #+#             */
/*   Updated: 2026/02/26 11:48:59 by alecasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "benchmark.h"

void	bench_init(t_bench *b, int size)
{
	memset(b, 0, sizeof(t_bench));
	b->initial_size = size;
	b->strategy_name = "Radix";
	b->complexity = "O(n log n)";
}

void	bench_count(t_bench *b, const char *op)
{
	if (!b->enabled)
		return ;
	b->total_ops++;
	if (!strcmp(op, "sa") || !strcmp(op, "sb") || !strcmp(op, "ss"))
	{
		if (!strcmp(op, "sa"))
			b->ops.sa++;
		else if (!strcmp(op, "sb"))
			b->ops.sb++;
		else
			b->ops.ss++;
	}
	else if (!strcmp(op, "pa") || !strcmp(op, "pb"))
	{
		if (!strcmp(op, "pa"))
			b->ops.pa++;
		else
			b->ops.pb++;
	}
	else if (!strcmp(op, "ra") || !strcmp(op, "rb") || !strcmp(op, "rr"))
	{
		if (!strcmp(op, "ra"))
			b->ops.ra++;
		else if (!strcmp(op, "rb"))
			b->ops.rb++;
		else
			b->ops.rr++;
	}
	else if (!strcmp(op, "rra") || !strcmp(op, "rrb") || !strcmp(op, "rrr"))
	{
		if (!strcmp(op, "rra"))
			b->ops.rra++;
		else if (!strcmp(op, "rrb"))
			b->ops.rrb++;
		else
			b->ops.rrr++;
	}
}

void	bench_calculate_disorder(t_bench *b, int *arr, int size)
{
	long long	disorder;
	int			i;
	int			j;

	disorder = 0;
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
				disorder++;
			j++;
		}
		i++;
	}
	b->disorder_pairs = disorder;
}

void	bench_print(t_bench *b)
{
	double	total_pairs;
	double	disorder_percent;

	if (!b->enabled)
		return ;
	total_pairs = (double)b->initial_size
		* (b->initial_size - 1) / 2.0;
	disorder_percent = (b->disorder_pairs / total_pairs) * 100.0;
	fprintf(stderr, "\n=== BENCHMARK ===\n");
	fprintf(stderr, "Disorder index: %.2f%%\n", disorder_percent);
	fprintf(stderr, "Strategy: %s\n", b->strategy_name);
	fprintf(stderr, "Complexity: %s\n", b->complexity);
	fprintf(stderr, "Total operations: %d\n\n", b->total_ops);
	fprintf(stderr, "sa: %d\n", b->ops.sa);
	fprintf(stderr, "sb: %d\n", b->ops.sb);
	fprintf(stderr, "ss: %d\n", b->ops.ss);
	fprintf(stderr, "pa: %d\n", b->ops.pa);
	fprintf(stderr, "pb: %d\n", b->ops.pb);
	fprintf(stderr, "ra: %d\n", b->ops.ra);
	fprintf(stderr, "rb: %d\n", b->ops.rb);
	fprintf(stderr, "rr: %d\n", b->ops.rr);
	fprintf(stderr, "rra: %d\n", b->ops.rra);
	fprintf(stderr, "rrb: %d\n", b->ops.rrb);
	fprintf(stderr, "rrr: %d\n", b->ops.rrr);
}
