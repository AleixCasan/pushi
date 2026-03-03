/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecasan <alecasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:48:35 by smilla-c          #+#    #+#             */
/*   Updated: 2026/03/03 11:21:05 by smilla-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

// --- DATA STRUCTURES --- //
// t_node: element of a stack

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;
// t_stack: linked list stack

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;
// t_program: container for stacks A and B

typedef struct s_program
{
	t_stack	a;
	t_stack	b;
}	t_program;

// --- FUNCTIONS MAIN --- //

// --- FLAGS / STRATEGY SELECTION --- //
// Handles command-line flags and chooses sorting strategy

int		ft_strcmp(const char *s1, const char *s2);
char	*get_strategy(int argc, char **argv);
void	select_strategy_advanced(char *strategy, t_stack *a, t_stack *b);
void	select_strategy_bench(t_stack *a, t_stack *b);

// --- PARSING --- //
// Functions to validate input, convert strings, and initialize stack

long	ft_atol(const char *str);
int		check_invalid_args(int argc, char **argv);
int		check_duplicates_args(int argc, char **argv);
int		parse_args(int argc, char **argv, t_stack *a);
int		init_stack(t_stack *a, int argc, char **argv);
size_t	ft_strlen(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
size_t	count_words(const char *s, char c);
char	**ft_split(const char *s, char c);

// --- STACK UTILITIES --- //
// Basic operations on linked-list stacks
int		stack_add_back(t_stack *stack, int value);
t_node	*create_node(int value);
int		is_sorted(t_node *stack);
void	free_stack(t_stack *stack);

// --- SORTING STRATEGIES --- //
// Functions that implement different sorting algorithms

void	select_strategy(t_stack *a, t_stack *b, t_bench *bench);
void	simple_sort(t_stack *a, t_stack *b);
void	medium_sort(t_stack *a, t_stack *b);
void	complex_sort(t_stack *a, t_stack *b);
void	adaptive_sort(t_stack *a, t_stack *b);
void	radix_sort(t_stack *a, t_stack *b, t_bench *bench);

// --- FUNCTIONS MOVES --- //
// -- PUSH -- //
void	push(t_stack *src, t_stack *dest);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
// -- SWAP -- //
void	swap(t_stack *stack);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
// -- ROTATE -- //
void	rotate(t_stack *stack);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
// -- REVERSE ROTATE -- //
void	reverse_rotate(t_stack *stack);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

// --- INIT / PARSING HELPERS --- //
// Functions to handle program initialization and single-string arguments

int		handle_single_argument(char *arg, t_stack *a);
int		parse_and_init(int argc, char **argv, t_stack *a);

#endif
