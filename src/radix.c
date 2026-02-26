/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecasan <alecasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 19:00:00 by smilla-c          #+#    #+#             */
/*   Updated: 2026/02/26 11:34:44 by alecasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"
#include <stdlib.h>

static int	cmp_ints(const void *p1, const void *p2)
{
	const int	ia = *(const int *)p1;
	const int	ib = *(const int *)p2;

	if (ia < ib)
		return (-1);
	if (ia > ib)
		return (1);
	return (0);
}

static int	*create_sorted_array(t_stack *a)
{
	int		*arr;
	t_node	*cur;
	int		i;

	arr = malloc(sizeof(int) * a->size);
	if (!arr)
		return (NULL);
	i = 0;
	cur = a->top;
	while (cur)
	{
		arr[i] = cur->value;
		i++;
		cur = cur->next;
	}
	qsort(arr, a->size, sizeof(int), cmp_ints);
	return (arr);
}

static int	find_index(int *arr, int size, int value)
{
	int	l;
	int	r;
	int	m;

	l = 0;
	r = size - 1;
	while (l <= r)
	{
		m = (l + r) / 2;
		if (arr[m] == value)
			return (m);
		if (arr[m] < value)
			l = m + 1;
		else
			r = m - 1;
	}
	return (-1);
}

static void	index_values(t_stack *a)
{
	int		*sorted;
	t_node	*cur;
	int		idx;

	sorted = create_sorted_array(a);
	if (!sorted)
		return ;
	cur = a->top;
	while (cur)
	{
		idx = find_index(sorted, a->size, cur->value);
		cur->value = idx;
		cur = cur->next;
	}
	free(sorted);
}

void	radix_sort(t_stack *a, t_stack *b, t_bench *bench)
{
	int		i;
	int		max_bits;
	int		max;
	int		j;

	index_values(a);
	max = a->size - 1;
	max_bits = 0;
	while ((max >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i <= max_bits)
	{
		j = a->size;
		while (j-- > 0)
		{
			if (((a->top->value >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
		}
		while (b->size)
			pa(a, b);
		i++;
	}
}
