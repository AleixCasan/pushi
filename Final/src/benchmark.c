/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecasan <alecasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:17:24 by smilla-c          #+#    #+#             */
/*   Updated: 2026/03/06 14:00:00 by alecasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "benchmark.h"
#include "push_swap.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*ptr = (unsigned char)c;
		ptr++;
		n--;
	}
	return (s);
}

void	bench_init(t_bench *b, int size)
{
	ft_memset(b, 0, sizeof(t_bench));
	b->initial_size = size;
	b->strategy_name = "Adaptive";
	b->complexity = "O(n log n)";
}

static void	bench_count_op(t_bench *b, const char *op)
{
	if (!ft_strcmp(op, "sa"))
		b->ops.sa++;
	else if (!ft_strcmp(op, "sb"))
		b->ops.sb++;
	else if (!ft_strcmp(op, "ss"))
		b->ops.ss++;
	else if (!ft_strcmp(op, "pa"))
		b->ops.pa++;
	else if (!ft_strcmp(op, "pb"))
		b->ops.pb++;
	else if (!ft_strcmp(op, "ra"))
		b->ops.ra++;
	else if (!ft_strcmp(op, "rb"))
		b->ops.rb++;
	else if (!ft_strcmp(op, "rr"))
		b->ops.rr++;
	else if (!ft_strcmp(op, "rra"))
		b->ops.rra++;
	else if (!ft_strcmp(op, "rrb"))
		b->ops.rrb++;
	else if (!ft_strcmp(op, "rrr"))
		b->ops.rrr++;
}

void	bench_count(t_bench *b, const char *op)
{
	if (!b->enabled)
		return ;
	b->total_ops++;
	bench_count_op(b, op);
}

void	bench_calculate_disorder_stack(t_bench *b, t_stack *a)
{
	t_node		*ci;
	t_node		*cj;
	long long	d;

	d = 0;
	ci = a->top;
	while (ci)
	{
		cj = ci->next;
		while (cj)
		{
			if (ci->value > cj->value)
				d++;
			cj = cj->next;
		}
		ci = ci->next;
	}
	b->disorder_pairs = d;
}
