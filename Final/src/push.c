/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecasan <alecasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 00:28:06 by alecasan          #+#    #+#             */
/*   Updated: 2026/02/26 11:14:08 by alecasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"
/*
** Moves the top element from src stack to dest stack.
** Adjusts the sizes of both stacks accordingly.
*/

void	push(t_stack *src, t_stack *dest)
{
	t_node	*temp;

	if (!src || !src->top)
		return ;
	temp = src->top;
	src->top = src->top->next;
	temp->next = dest->top;
	dest->top = temp;
	src->size--;
	dest->size++;
}
/*
** Executes the push operation from stack B to A (pa) or
** from A to B (pb), prints the operation and updates benchmark.
*/

void	pa(t_stack *a, t_stack *b, t_bench *bench)
{
	push(b, a);
	write(1, "pa\n", 3);
	bench_count(bench, "pa");
}

void	pb(t_stack *a, t_stack *b, t_bench *bench)
{
	push(a, b);
	write(1, "pb\n", 3);
	bench_count(bench, "pb");
}
