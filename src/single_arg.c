/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilla-c <smilla-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 10:40:00 by smilla-c          #+#    #+#             */
/*   Updated: 2026/02/25 11:17:21 by smilla-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_tokens(char **tokens)
{
	int	cnt;

	cnt = 0;
	while (tokens[cnt])
		cnt++;
	return (cnt);
}

static void	free_tokens_array(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

static int	build_and_parse(char **tokens, t_stack *a)
{
	char	**new_argv;
	int		cnt;
	int		i;

	cnt = count_tokens(tokens);
	new_argv = malloc(sizeof(char *) * (cnt + 1));
	if (!new_argv)
		return (free_tokens_array(tokens), 1);
	new_argv[0] = NULL;
	i = -1;
	while (++i < cnt)
		new_argv[i + 1] = tokens[i];
	if (parse_args(cnt + 1, new_argv, a))
		return (free_tokens_array(tokens), free(new_argv), 1);
	free(new_argv);
	free_tokens_array(tokens);
	return (0);
}

int	handle_single_argument(char *arg, t_stack *a)
{
	char	**tokens;
	int		cnt;
	int		ret;

	tokens = ft_split(arg, ' ');
	if (!tokens)
		return (1);
	cnt = count_tokens(tokens);
	if (cnt == 0)
	{
		free(tokens);
		return (2);
	}
	ret = build_and_parse(tokens, a);
	return (ret);
}
