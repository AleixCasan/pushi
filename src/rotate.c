/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecasan <alecasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 00:41:12 by alecasan          #+#    #+#             */
/*   Updated: 2026/02/26 11:10:45 by alecasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"
/*
** Moves the top element of the stack to the bottom,
** effectively rotating all elements up by one position.
*/

void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	first = stack->top;
	stack->top = first->next;
	last = stack->top;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}
/*
** Executes rotate on stack A (ra), stack B (rb), or both (rr),
** prints the operation, and updates benchmark.
*/

void	ra(t_stack *a, t_bench *bench)
{
	rotate(a);
	write(1, "ra\n", 3);
	bench_count(bench, "ra");
}

void	rb(t_stack *b, t_bench *bench)
{
	rotate(b);
	write(1, "rb\n", 3);
	bench_count(bench, "rb");
}

void	rr(t_stack *a, t_stack *b, t_bench *bench)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
	bench_count(bench, "rr");
}
