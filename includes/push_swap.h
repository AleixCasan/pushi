/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilla-c <smilla-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:48:35 by smilla-c          #+#    #+#             */
/*   Updated: 2026/02/18 13:21:13 by smilla-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

// --- STRUCTURES --- //
typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

typedef struct s_program
{
	t_stack	a;
	t_stack	b;
}	t_program;

// --- FUNCTIONS MAIN --- //

// --- PARSING --- //
long	ft_atol(const char *str);
int		check_invalid_args(int argc, char **argv);
int		check_duplicates_args(int argc, char **argv);
int		parse_args(int argc, char **argv, t_stack *a);

// --- FUNCTIONS MOVES --- //
// -- PUSH -- //
void	push(t_node **src, t_node **dest);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
// -- SWAP -- //
void	swap(t_node **stack);
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
// -- ROTATE -- //
void	rotate(t_node **stack);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
// -- REVERSE ROTATE -- //
void	reverse_rotate(t_node **stack);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

int		is_sorted(t_node **stack);
t_node	*create_node(int value);

#endif
