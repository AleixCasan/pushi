/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecasan <alecasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 14:00:00 by alecasan          #+#    #+#             */
/*   Updated: 2026/03/06 14:00:00 by alecasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "benchmark.h"
#include "push_swap.h"

static void	put_err(const char *s)
{
	write(2, s, ft_strlen(s));
}

static void	put_int_err(int n)
{
	char	buf[12];
	int		i;
	int		neg;

	neg = (n < 0);
	if (neg)
		n = -n;
	i = 11;
	buf[i] = '\0';
	if (n == 0)
		buf[--i] = '0';
	while (n > 0)
	{
		buf[--i] = '0' + (n % 10);
		n /= 10;
	}
	if (neg)
		buf[--i] = '-';
	write(2, buf + i, 11 - i);
}

static void	put_percent(long long num, long long den)
{
	long long	s;

	s = num * 10000 / den;
	put_int_err((int)(s / 100));
	put_err(".");
	if (s % 100 < 10)
		put_err("0");
	put_int_err((int)(s % 100));
	put_err("%");
}

static void	bench_print_ops(t_bench *b)
{
	put_err("[bench] sa: ");
	put_int_err(b->ops.sa);
	put_err("  sb: ");
	put_int_err(b->ops.sb);
	put_err("  ss: ");
	put_int_err(b->ops.ss);
	put_err("  pa: ");
	put_int_err(b->ops.pa);
	put_err("  pb: ");
	put_int_err(b->ops.pb);
	put_err("\n[bench] ra: ");
	put_int_err(b->ops.ra);
	put_err("  rb: ");
	put_int_err(b->ops.rb);
	put_err("  rr: ");
	put_int_err(b->ops.rr);
	put_err("  rra: ");
	put_int_err(b->ops.rra);
	put_err("  rrb: ");
	put_int_err(b->ops.rrb);
	put_err("  rrr: ");
	put_int_err(b->ops.rrr);
	put_err("\n");
}

void	bench_print(t_bench *b)
{
	long long	tp;

	if (!b->enabled)
		return ;
	tp = (long long)b->initial_size * (b->initial_size - 1) / 2;
	put_err("[bench] disorder:   ");
	if (tp > 0)
		put_percent(b->disorder_pairs, tp);
	else
		put_err("0.00%");
	put_err("\n[bench] strategy:   ");
	put_err(b->strategy_name);
	put_err(" / ");
	put_err(b->complexity);
	put_err("\n[bench] total_ops:  ");
	put_int_err(b->total_ops);
	put_err("\n");
	bench_print_ops(b);
}
