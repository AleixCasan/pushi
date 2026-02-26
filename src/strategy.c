/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecasan <alecasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:16:23 by smilla-c          #+#    #+#             */
/*   Updated: 2026/02/26 11:46:43 by alecasan         ###   ########.fr       */
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

static void	rotate_to_pos(t_stack *a, int pos)
{
	int	i;

	if (pos <= a->size / 2)
	{
		i = 0;
		while (i++ < pos)
			ra(a);
	}
	else
	{
		i = 0;
		while (i++ < a->size - pos)
			rra(a);
	}
}

void	simple_sort(t_stack *a, t_stack *b, t_bench *bench)
{
	int	to_push;
	int	min_pos;

	if (a->size <= 3)
	{
		select_strategy(a, b, bench);
		return ;
	}
	if (a->size <= 5)
	{
		select_strategy(a, b, bench);
		return ;
	}
	to_push = a->size - 3;
	while (to_push-- > 0)
	{
		min_pos = find_min_pos(a);
		rotate_to_pos(a, min_pos);
		pb(a, b);
	}
	select_strategy(a, b, bench);
	while (b->size)
		pa(a, b);
}

void	medium_sort(t_stack *a, t_stack *b, t_bench *bench)
{
	int	chunk_size;
	int	i;

	chunk_size = a->size / 2 + 1;
	i = 0;
	while (i < chunk_size && a->size > 3)
	{
		pb(a, b);
		i++;
	}
	select_strategy(a, b, bench);
	while (b->size)
		pa(a, b);
}

void	adaptive_sort(t_stack *a, t_stack *b, t_bench *bench)
{
	if (a->size <= 3)
		select_strategy(a, b, bench);
	else if (a->size <= 100)
		medium_sort(a, b, bench);
	else
		radix_sort(a, b, bench);
}
