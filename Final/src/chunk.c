/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecasan <alecasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:00:00 by alecasan          #+#    #+#             */
/*   Updated: 2026/03/06 14:00:00 by alecasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"

static int	find_max_b(t_stack *b)
{
	t_node	*cur;
	int		max;
	int		max_pos;
	int		pos;

	cur = b->top;
	max = cur->value;
	max_pos = 0;
	pos = 0;
	while (cur)
	{
		if (cur->value > max)
		{
			max = cur->value;
			max_pos = pos;
		}
		cur = cur->next;
		pos++;
	}
	return (max_pos);
}

static void	rotate_b(t_stack *b, int pos, t_bench *bench)
{
	int	i;

	if (pos <= b->size / 2)
	{
		i = 0;
		while (i++ < pos)
			rb(b, bench);
	}
	else
	{
		i = 0;
		while (i++ < b->size - pos)
			rrb(b, bench);
	}
}

static int	find_in_range(t_stack *a, t_range r)
{
	t_node	*cur;
	int		pos;

	pos = 0;
	cur = a->top->next;
	while (cur)
	{
		if (cur->value >= r.lo && cur->value <= r.hi)
			return (pos + 1);
		cur = cur->next;
		pos++;
	}
	return (-1);
}

static void	push_chunk(t_stack *a, t_stack *b, t_range r, t_bench *bench)
{
	int	rem;
	int	pos;
	int	i;

	rem = r.hi - r.lo + 1;
	while (rem > 0 && a->size > 0)
	{
		if (a->top->value >= r.lo && a->top->value <= r.hi)
		{
			pb(a, b, bench);
			rem--;
			continue ;
		}
		pos = find_in_range(a, r);
		if (pos < 0)
			break ;
		i = 0;
		if (pos <= a->size / 2)
			while (i++ < pos)
				ra(a, bench);
		else
			while (i++ < a->size - pos)
				rra(a, bench);
	}
}

void	chunk_sort(t_stack *a, t_stack *b, t_bench *bench)
{
	int		n;
	int		cs;
	t_range	r;

	n = a->size;
	cs = 1;
	while (cs * cs < n)
		cs++;
	r.lo = 0;
	while (r.lo < n)
	{
		r.hi = r.lo + cs - 1;
		push_chunk(a, b, r, bench);
		r.lo += cs;
	}
	while (b->size)
	{
		rotate_b(b, find_max_b(b), bench);
		pa(a, b, bench);
	}
}
