/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilla-c <smilla-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:48:35 by smilla-c          #+#    #+#             */
/*   Updated: 2026/02/18 10:44:06 by smilla-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_node
{
	int	value;
	struct s_node	*next;
} t_node;i

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

//---DECLARACION DE STACKS GLOBALES--- //


t_stack	a;
t_stack	b;


// --- FUNCIONES MAIN --- //

long	ft_atol(const char *str)
int		check_invalid_args(int argc, char **argv);
void	check_duplicates_args(int argc, char **argv);

// --- FUNCIONES MOVES --- //
void	push(t_node **from, t_node **to);
void	swap(t_node **stack);
void	rotate(t_node **stack);
void	reverse_rotate(t_node **stack);

int		is_sorted(t_node **stack);
t_node	*create_node(int value);

#endif

