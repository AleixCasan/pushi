/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecasan <alecasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 00:34:56 by alecasan          #+#    #+#             */
/*   Updated: 2026/02/26 11:07:56 by alecasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"

void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
}

void	sa(t_stack *a, t_bench *bench)
{
	swap(a);
	write(1, "sa\n", 3);
	bench_count(bench, "sa");
}

void	sb(t_stack *b, t_bench *bench)
{
	swap(b);
	write(1, "sb\n", 3);
	bench_count(bench, "sb");
}

void	ss(t_stack *a, t_stack *b, t_bench *bench)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
	bench_count(bench, "ss");
}
