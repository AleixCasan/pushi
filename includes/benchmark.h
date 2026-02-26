/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecasan <alecasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 10:46:16 by alecasan          #+#    #+#             */
/*   Updated: 2026/02/26 11:26:56 by alecasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BENCHMARK_H
#define BENCHMARK_H

typedef struct s_ops
{
	int sa;
	int sb;
	int ss;
	int pa;
	int pb;
	int ra;
	int rb;
	int rr;
	int rra;
	int rrb;
	int rrr;
}	t_ops;

typedef struct s_bench
{
	int     enabled;
	int     total_ops;
	t_ops   ops;
	int     initial_size;
	int     disorder_pairs;
	const char *strategy_name;
	const char *complexity;
}	t_bench;

void	bench_init(t_bench *b, int size);
void	bench_count(t_bench *b, const char *op);
void	bench_calculate_disorder(t_bench *b, int *arr, int size);
void	bench_print(t_bench *b);

#endif
