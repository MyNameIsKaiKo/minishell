/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_exec_wildcards.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:57:09 by jleray            #+#    #+#             */
/*   Updated: 2026/04/21 18:42:55 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

int	is_wildcard(char *str, int state)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			state = 1;
		if (str[i] == '*' && !state)
			return (1);
		i++;
	}
	return (0);
}

static void	set_quotes_states(t_ast **tree, int old_i, int add, int total)
{
	int	*new_quotes;
	int	j;
	int	k;

	new_quotes = malloc(sizeof(int) * total);
	if (!new_quotes)
		return ;
	j = 0;
	k = 0;
	while (j < total)
	{
		if (j >= old_i && j < old_i + add)
			new_quotes[j] = 0;
		else
		{
			new_quotes[j] = (*tree)->quote_states[k];
			k++;
		}
		j++;
	}
	free((*tree)->quote_states);
	(*tree)->quote_states = new_quotes;
}

static char	**get_left_wild(int count, char **old_args)
{
	int		i;
	char	**output;

	i = 0;
	output = malloc(sizeof(char *) * (count + 1));
	if (!output)
		return (NULL);
	while (i < count)
	{
		output[i] = old_args[i];
		i++;
	}
	output[i] = NULL;
	return (output);
}

static char	**get_right_wild(int count, char **old_args)
{
	int		i;
	int		right_size;
	char	**output;

	i = count + 1;
	right_size = 0;
	while (old_args[i + right_size])
		right_size++;
	output = malloc(sizeof(char *) * (right_size + 1));
	if (!output)
		return (NULL);
	right_size = 0;
	while (old_args[i])
	{
		output[right_size] = old_args[i];
		i++;
		right_size++;
	}
	output[right_size] = NULL;
	return (output);
}

void	make_wildcard(t_ast **tree, char ***to_wild, int *i)
{
	char	**wilds;
	char	**left;
	int		wild_count;

	left = NULL;
	wilds = wildcards((*to_wild)[*i]);
	wild_count = arr_len(wilds);
	if (*i > 0)
		left = get_left_wild(*i, *to_wild);
	left = ft_arr_join(left, wilds);
	wilds = ft_arr_join(left, get_right_wild(*i, *to_wild));
	set_quotes_states(tree, *i, wild_count, arr_len(wilds));
	free((*to_wild)[*i]);
	free(*to_wild);
	*to_wild = wilds;
	*i += wild_count - 1;
}
