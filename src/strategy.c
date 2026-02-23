/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilla-c <smilla-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:16:23 by smilla-c          #+#    #+#             */
/*   Updated: 2026/02/20 13:16:32 by smilla-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(t_stack *a, t_stack *b)
{
	while (!is_sorted(a->top))
	{
		if (a->top->value > a->top->next->value)
			sa(&a->top);
		else if (a->size > 3)
			pb(&a->top, &b->top);
		if (b->size)
			pa(&b->top, &a->top);
	}
}

void	medium_sort(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	i;

	chunk_size = a->size / 2 + 1;
	i = 0;
	while (i < chunk_size && a->size > 3)
	{
		pb(&a->top, &b->top);
		i++;
	}
	select_strategy(a, b);
	while (b->size)
		pa(&b->top, &a->top);
}

void	adaptive_sort(t_stack *a, t_stack *b)
{
	if (a->size <= 3)
		select_strategy(a, b);
	else if (a->size <= 100)
		medium_sort(a, b);
	else
		radix_sort(a, b);
}
