/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecasan <alecasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 11:57:46 by smilla-c          #+#    #+#             */
/*   Updated: 2026/02/26 11:42:55 by alecasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"

static void	sort_three(t_stack *a)
{
	if (a->top->value > a->top->next->value)
	{
		if (a->top->value < a->top->next->next->value)
			sa(a);
		else if (a->top->next->value > a->top->next->next->value)
		{
			sa(a);
			rra(a);
		}
		else
			ra(a);
	}
	else if (a->top->next->value > a->top->next->next->value)
	{
		if (a->top->value > a->top->next->next->value)
			rra(a);
		else
		{
			ra(a);
			sa(a);
		}
	}
}

static int	find_min_pos_in_stack(t_stack *a)
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

static void	push_min_to_b(t_stack *a, t_stack *b)
{
	int	pos;
	int	i;

	pos = find_min_pos_in_stack(a);
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
	pb(a, b);
}

static void	sort_five(t_stack *a, t_stack *b)
{
	int	to_push;

	to_push = a->size - 3;
	while (to_push-- > 0)
		push_min_to_b(a, b);
	sort_three(a);
	while (b->size)
		pa(a, b);
}

void	select_strategy(t_stack *a, t_stack *b, t_bench *bench)
{
	if (a->size == 0 || is_sorted(a->top))
		return ;
	if (a->size == 2)
	{
		if (a->top->value > a->top->next->value)
			sa(a);
		return ;
	}
	if (a->size == 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_five(a, b);
	else
		radix_sort(a, b);
}
