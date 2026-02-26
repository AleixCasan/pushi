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

void bench_init(t_bench *b, int size)
{
	memset(b, 0, sizeof(t_bench));
	b->initial_size = size;
	b->strategy_name = "Radix";
	b->complexity = "O(n log n)";
}

void bench_count(t_bench *b, const char *op)
{
	if (!b->enabled)
		return;

	b->total_ops++;

	if (!strcmp(op, "sa")) b->ops.sa++;
	else if (!strcmp(op, "sb")) b->ops.sb++;
	else if (!strcmp(op, "ss")) b->ops.ss++;
	else if (!strcmp(op, "pa")) b->ops.pa++;
	else if (!strcmp(op, "pb")) b->ops.pb++;
	else if (!strcmp(op, "ra")) b->ops.ra++;
	else if (!strcmp(op, "rb")) b->ops.rb++;
	else if (!strcmp(op, "rr")) b->ops.rr++;
	else if (!strcmp(op, "rra")) b->ops.rra++;
	else if (!strcmp(op, "rrb")) b->ops.rrb++;
	else if (!strcmp(op, "rrr")) b->ops.rrr++;
}

void bench_calculate_disorder(t_bench *b, int *arr, int size)
{
	long long total_pairs = (long long)size * (size - 1) / 2;
	long long disorder = 0;

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
				disorder++;
		}
	}
	b->disorder_pairs = disorder;
}

void bench_print(t_bench *b)
{
	if (!b->enabled)
		return;

	double total_pairs = (double)b->initial_size * (b->initial_size - 1) / 2.0;
	double disorder_percent = (b->disorder_pairs / total_pairs) * 100.0;

	fprintf(stderr, "\n=== BENCHMARK ===\n");
	fprintf(stderr, "Disorder index: %.2f%%\n", disorder_percent);
	fprintf(stderr, "Strategy: %s\n", b->strategy_name);
	fprintf(stderr, "Complexity: %s\n", b->complexity);
	fprintf(stderr, "Total operations: %d\n\n", b->total_ops);

	fprintf(stderr, "Operation count:\n");
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