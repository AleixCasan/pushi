/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecasan <alecasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 19:00:00 by smilla-c          #+#    #+#             */
/*   Updated: 2026/03/06 14:00:00 by alecasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"

static void	radix_pass(t_stack *a, t_stack *b, int bit, t_bench *bench)
{
	int	j;

	j = a->size;
	while (j-- > 0)
	{
		if (((a->top->value >> bit) & 1) == 0)
			pb(a, b, bench);
		else
			ra(a, bench);
	}
	while (b->size)
		pa(a, b, bench);
}

void	radix_sort(t_stack *a, t_stack *b, t_bench *bench)
{
	int	max_bits;
	int	max;
	int	i;

	index_values(a);
	max = a->size - 1;
	max_bits = 0;
	while ((max >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i <= max_bits)
	{
		radix_pass(a, b, i, bench);
		i++;
	}
}
