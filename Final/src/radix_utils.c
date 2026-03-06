/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecasan <alecasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 14:00:00 by alecasan          #+#    #+#             */
/*   Updated: 2026/03/06 14:00:00 by alecasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cmp_ints(const void *p1, const void *p2)
{
	const int	a = *(const int *)p1;
	const int	b = *(const int *)p2;

	if (a < b)
		return (-1);
	if (a > b)
		return (1);
	return (0);
}

int	*create_sorted_array(t_stack *a)
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
		arr[i++] = cur->value;
		cur = cur->next;
	}
	qsort(arr, a->size, sizeof(int), cmp_ints);
	return (arr);
}

int	find_index(int *arr, int size, int value)
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

void	index_values(t_stack *a)
{
	int		*sorted;
	t_node	*cur;

	sorted = create_sorted_array(a);
	if (!sorted)
		return ;
	cur = a->top;
	while (cur)
	{
		cur->value = find_index(sorted, a->size, cur->value);
		cur = cur->next;
	}
	free(sorted);
}
