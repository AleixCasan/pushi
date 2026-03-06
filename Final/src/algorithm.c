/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecasan <alecasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 11:57:46 by smilla-c          #+#    #+#             */
/*   Updated: 2026/03/05 14:00:00 by alecasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"
/*
** Sorts a stack of exactly three elements in ascending order.
** Uses only sa, ra, rra operations.
*/

static void	sort_three(t_stack *a, t_bench *bench)
{
	if (a->top->value > a->top->next->value)
	{
		if (a->top->value < a->top->next->next->value)
			sa(a, bench);
		else if (a->top->next->value > a->top->next->next->value)
		{
			sa(a, bench);
			rra(a, bench);
		}
		else
			ra(a, bench);
	}
	else if (a->top->next->value > a->top->next->next->value)
	{
		if (a->top->value > a->top->next->next->value)
			rra(a, bench);
		else
		{
			sa(a, bench);
			ra(a, bench);
		}
	}
}
/*
** Returns the position of the minimum value in the stack.
*/

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
/*
** Rotates the stack to bring the minimum element on top,
** then pushes it to stack B.
*/

static void	push_min_to_b(t_stack *a, t_stack *b, t_bench *bench)
{
	int	pos;
	int	i;

	pos = find_min_pos_in_stack(a);
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
	pb(a, b, bench);
}
/*
** Sorts a stack of up to five elements.
*/

static void	sort_five(t_stack *a, t_stack *b, t_bench *bench)
{
	int	to_push;

	to_push = a->size - 3;
	while (to_push-- > 0)
		push_min_to_b(a, b, bench);
	sort_three(a, bench);
	while (b->size)
		pa(a, b, bench);
}
/*
** Selects the sorting strategy based on the size of stack A.
*/

void	select_strategy(t_stack *a, t_stack *b, t_bench *bench)
{
	if (a->size == 0 || is_sorted(a->top))
		return ;
	if (a->size == 2)
	{
		if (a->top->value > a->top->next->value)
			sa(a, bench);
		return ;
	}
	if (a->size == 3)
		sort_three(a, bench);
	else if (a->size <= 5)
		sort_five(a, b, bench);
	else
		radix_sort(a, b, bench);
}
