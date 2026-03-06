/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecasan <alecasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:16:23 by smilla-c          #+#    #+#             */
/*   Updated: 2026/03/06 14:00:00 by alecasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"

static int	find_min_pos(t_stack *a)
{
	t_node	*cur;
	int		min;
	int		min_pos;
	int		pos;

	cur = a->top;
	min = cur->value;
	min_pos = 0;
	pos = 0;
	while (cur)
	{
		if (cur->value < min)
		{
			min = cur->value;
			min_pos = pos;
		}
		cur = cur->next;
		pos++;
	}
	return (min_pos);
}

static void	rotate_to_pos(t_stack *a, int pos, t_bench *bench)
{
	int	i;

	if (pos <= a->size / 2)
	{
		i = 0;
		while (i++ < pos)
			ra(a, bench);
	}
	else
	{
		i = 0;
		while (i++ < a->size - pos)
			rra(a, bench);
	}
}

void	simple_sort(t_stack *a, t_stack *b, t_bench *bench)
{
	int	to_push;

	if (a->size <= 5)
		return (select_strategy(a, b, bench));
	to_push = a->size - 3;
	while (to_push-- > 0)
	{
		rotate_to_pos(a, find_min_pos(a), bench);
		pb(a, b, bench);
	}
	select_strategy(a, b, bench);
	while (b->size)
		pa(a, b, bench);
}

void	medium_sort(t_stack *a, t_stack *b, t_bench *bench)
{
	if (a->size <= 5)
		return (select_strategy(a, b, bench));
	index_values(a);
	chunk_sort(a, b, bench);
}

void	adaptive_sort(t_stack *a, t_stack *b, t_bench *bench)
{
	long long	tp;
	long long	d;

	if (a->size <= 3)
		return (select_strategy(a, b, bench));
	if (a->size > 100)
		return (radix_sort(a, b, bench));
	tp = (long long)a->size * (a->size - 1) / 2;
	if (tp == 0)
		tp = 1;
	d = bench->disorder_pairs * 10000 / tp;
	if (d < 2000)
		simple_sort(a, b, bench);
	else if (d < 5000)
		medium_sort(a, b, bench);
	else
		radix_sort(a, b, bench);
}
