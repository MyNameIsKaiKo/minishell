/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_exec_cmd_exandwil.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 19:38:01 by jleray            #+#    #+#             */
/*   Updated: 2026/04/19 21:49:16 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

static void	set_quotes_states(t_ast **tree, int old_i, int add, int total)
{
	int	*new_quotes;
	int	j;
	int	k;

	new_quotes = malloc(sizeof(int) * total);
	if(!new_quotes)
		return ;
	j = 0;
	k = 0;
	while(j < total)
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

static int	is_wildcard(char *str, int state)
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

static void	make_wildcard(t_ast **tree, char ***to_wild, int *i)
{
	char	**wilds;
	char	**left;
	int	wild_count;

	left = NULL;
	wilds = wildcards((*to_wild)[*i]);
	wild_count = arr_len(wilds);
	if (*i > 0)
		left = get_left_wild(*i, *to_wild);
	left = ft_arr_join(left, wilds);
	wilds = ft_arr_join(left, get_right_wild(*i, *to_wild));
	set_quotes_states(tree, *i, wild_count, arr_len(wilds));
	free(*to_wild);
	*to_wild = wilds;
	*i += wild_count - 1;
}

static void	apply_wildcard_totree(t_ast **tree)
{
	char	**to_wild;
	int		i;

	to_wild = (*tree)->args;
	i = 0;
	while (to_wild[i])
	{
		if (is_wildcard(to_wild[i], (*tree)->quote_states[i]))
			make_wildcard(tree, &to_wild, &i);
		i++;
	}
	(*tree)->args = to_wild;
}

static	void shift_sarr(t_ast **tree, char **sarr, int i)
{
	int	j;

	j = i;
	while(sarr[j])
	{
		sarr[j] = sarr[j + 1];
		(*tree)->quote_states[j] = (*tree)->quote_states[j + 1];
		j++;
	}
}

static void replace_to_expand(t_ast **tree, char **to_expand, int i, char *tmp)
{
	size_t len;
	char *supped_quotes;

	len = ft_strlen(tmp);
	supped_quotes = supp_quote(tmp);
	if (len > ft_strlen(supped_quotes))
		(*tree)->quote_states[i] = 1;
	free(to_expand[i]);
	to_expand[i] = supped_quotes;
}

static void	apply_expand_totree(t_ast **tree, t_data data)
{
	char	**to_expand;
	char *tmp;
	int	i;

	i = 0;
	to_expand = (*tree)->args;
	while(to_expand[i])
	{
		tmp = expander(to_expand[i], *(data.env));
		if (!tmp || !tmp[0])
		{
			if (tmp)
				free(tmp);
			shift_sarr(tree, to_expand, i);
			continue ;
		}
		replace_to_expand(tree, to_expand, i, tmp);
		i++;
	}
}

void	apply_exandwil(t_ast **tree, t_data data)
{
	apply_expand_totree(tree, data);
	apply_wildcard_totree(tree);
}
