/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecasan <alecasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 01:41:54 by alecasan          #+#    #+#             */
/*   Updated: 2026/02/26 11:12:43 by alecasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"
/*
** Moves the last element of the stack to the top,
** effectively rotating all elements down by one position.
*/

void	reverse_rotate(t_stack *stack)
{
	t_node	*prev;
	t_node	*last;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	prev = NULL;
	last = stack->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stack->top;
	stack->top = last;
}
/*
** Executes reverse rotate on stack A (rra), stack B (rrb), or both (rrr),
** prints the operation, and updates benchmark.
*/

void	rra(t_stack *a, t_bench *bench)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
	bench_count(bench, "rra");
}

void	rrb(t_stack *b, t_bench *bench)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
	bench_count(bench, "rrb");
}

void	rrr(t_stack *a, t_stack *b, t_bench *bench)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
	bench_count(bench, "rrr");
}
