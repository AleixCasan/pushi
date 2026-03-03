/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilla-c <smilla-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 11:40:52 by smilla-c          #+#    #+#             */
/*   Updated: 2026/02/20 11:41:46 by smilla-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
** Adds a new node with the given value at the end of the stack.
** Returns 0 on success, 1 if memory allocation fails.
*/

int	stack_add_back(t_stack *stack, int value)
{
	t_node	*new;
	t_node	*last;

	new = create_node(value);
	if (!new)
		return (1);
	if (!stack->top)
	{
		stack->top = new;
		stack->size++;
		return (0);
	}
	last = stack->top;
	while (last->next)
		last = last->next;
	last->next = new;
	stack->size++;
	return (0);
}
/*
** Creates a new stack node with the given value.
** Returns a pointer to the node or NULL on allocation failure.
*/

t_node	*create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}
/*
** Checks if the stack is sorted in ascending order.
** Returns 1 if sorted, 0 otherwise.
*/

int	is_sorted(t_node *stack)
{
	t_node	*current;

	if (!stack)
		return (1);
	current = stack;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
/*
** Frees all nodes in the stack and resets its top and size.
*/

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	stack->top = NULL;
	stack->size = 0;
}
