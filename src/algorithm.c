/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilla-c <smilla-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 11:57:46 by smilla-c          #+#    #+#             */
/*   Updated: 2026/02/20 12:04:45 by smilla-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack *a)
{
	if (a->top->value > a->top->next->value)
	{
		if (a->top->value < a->top->next->next->value)
			sa(&a->top);
		else if (a->top->next->value > a->top->next->next->value)
		{
			sa(&a->top);
			rra(&a->top);
		}
		else
			ra(&a->top);
	}
	else if (a->top->next->value > a->top->next->next->value)
	{
		if (a->top->value > a->top->next->next->value)
			rra(&a->top);
		else
		{
			ra(&a->top);
			sa(&a->top);
		}
	}
}

static void	sort_five(t_stack *a, t_stack *b)
{
	pb(&a->top, &b->top);
	pb(&a->top, &b->top);
	sort_three(a);
	pa(&b->top, &a->top);
	if (b->size)
		pa(&b->top, &a->top);
}

static void	radix_sort(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (!is_sorted(a->top) && i < 32)
	{
		if ((a->top->value >> i & 1) == 0)
			pb(&a->top, &b->top);
		else
			ra(&a->top);
		i++;
	}
	while (b->size)
		pa(&b->top, &a->top);
}

void	select_strategy(t_stack *a, t_stack *b)
{
	if (a->size == 0 || is_sorted(a->top))
		return ;
	if (a->size == 2)
	{
		if (a->top->value > a->top->next->value)
			sa(&a->top);
		return ;
	}
	if (a->size == 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_five(a, b);
	else
		radix_sort(a, b);
}
