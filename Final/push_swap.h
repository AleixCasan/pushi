/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecasan <alecasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:13:57 by smilla-c          #+#    #+#             */
/*   Updated: 2026/03/05 14:00:00 by alecasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

/* ── Data structures ─────────────────────────────────────────────────────── */

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

typedef struct s_range
{
	int	lo;
	int	hi;
}	t_range;

/* Forward declaration so push_swap.h can reference t_bench without details */
typedef struct s_bench	t_bench;

/* ── ft_split / string utils  (ft_split.c) ──────────────────────────────── */
size_t		ft_strlen(const char *s);
char		*ft_substr(const char *s, unsigned int start, size_t len);
char		**ft_split(const char *s, char c);

/* ── String / flag utils  (flags.c) ─────────────────────────────────────── */
int			ft_strcmp(const char *s1, const char *s2);
char		*get_strategy(int argc, char **argv);

/* ── Stack utils  (stack_utils.c) ───────────────────────────────────────── */
t_node		*create_node(int value);
int			stack_add_back(t_stack *stack, int value);
int			is_sorted(t_node *stack);
void		free_stack(t_stack *stack);

/* ── Parsing  (parsing.c) ───────────────────────────────────────────────── */
long		ft_atol(const char *str);
int			check_invalid_args(int argc, char **argv);
int			check_duplicates_args(int argc, char **argv);
int			init_stack(t_stack *a, int argc, char **argv);
int			parse_args(int argc, char **argv, t_stack *a);

/* ── Single-argument handling  (single_arg.c) ───────────────────────────── */
int			handle_single_argument(char *arg, t_stack *a);

/* ── Init  (init.c) ─────────────────────────────────────────────────────── */
int			parse_and_init(int argc, char **argv, t_stack *a);

/* ── Operations: swap  (swap.c) ─────────────────────────────────────────── */
void		swap(t_stack *stack);
void		sa(t_stack *a, t_bench *bench);
void		sb(t_stack *b, t_bench *bench);
void		ss(t_stack *a, t_stack *b, t_bench *bench);

/* ── Operations: push  (push.c) ─────────────────────────────────────────── */
void		push(t_stack *src, t_stack *dest);
void		pa(t_stack *a, t_stack *b, t_bench *bench);
void		pb(t_stack *a, t_stack *b, t_bench *bench);

/* ── Operations: rotate  (rotate.c) ────────────────────────────────────── */
void		rotate(t_stack *stack);
void		ra(t_stack *a, t_bench *bench);
void		rb(t_stack *b, t_bench *bench);
void		rr(t_stack *a, t_stack *b, t_bench *bench);

/* ── Operations: reverse rotate  (reverse_rotate.c) ────────────────────── */
void		reverse_rotate(t_stack *stack);
void		rra(t_stack *a, t_bench *bench);
void		rrb(t_stack *b, t_bench *bench);
void		rrr(t_stack *a, t_stack *b, t_bench *bench);

/* ── Radix utils  (radix_utils.c) ───────────────────────────────────────── */
int			cmp_ints(const void *p1, const void *p2);
int			*create_sorted_array(t_stack *a);
int			find_index(int *arr, int size, int value);
void		index_values(t_stack *a);

/* ── Algorithms  (algorithm.c / radix.c) ───────────────────────────────── */
void		select_strategy(t_stack *a, t_stack *b, t_bench *bench);
void		radix_sort(t_stack *a, t_stack *b, t_bench *bench);

/* ── Strategies  (strategy.c) ───────────────────────────────────────────── */
void		simple_sort(t_stack *a, t_stack *b, t_bench *bench);
void		medium_sort(t_stack *a, t_stack *b, t_bench *bench);
void		adaptive_sort(t_stack *a, t_stack *b, t_bench *bench);
void		chunk_sort(t_stack *a, t_stack *b, t_bench *bench);

#endif
