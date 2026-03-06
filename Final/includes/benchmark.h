/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecasan <alecasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 10:46:16 by alecasan          #+#    #+#             */
/*   Updated: 2026/03/06 14:00:00 by alecasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BENCHMARK_H
# define BENCHMARK_H

# include <stddef.h>

typedef struct s_stack	t_stack;

typedef struct s_ops
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_ops;

typedef struct s_bench
{
	int			enabled;
	int			total_ops;
	t_ops		ops;
	int			initial_size;
	long long	disorder_pairs;
	const char	*strategy_name;
	const char	*complexity;
}	t_bench;

void	*ft_memset(void *s, int c, size_t n);
void	bench_init(t_bench *b, int size);
void	bench_count(t_bench *b, const char *op);
void	bench_calculate_disorder_stack(t_bench *b, t_stack *a);
void	bench_print(t_bench *b);

#endif
