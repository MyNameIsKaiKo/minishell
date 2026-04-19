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

static void	apply_wildcard_totree(t_ast **tree)
{
	char	**to_wild;
	char	**wildcards_sa;
	char	**left;
	char	**right;
	int		i;

	to_wild = (*tree)->args;
	i = 0;
	left = NULL;
	while (to_wild[i])
	{
		if (is_wildcard(to_wild[i], (*tree)->quote_states[i]))
		{
			wildcards_sa = wildcards(to_wild[i]);
			if (i > 0)
				left = get_left_wild(i, to_wild);
			right = get_right_wild(i, to_wild);
			left = ft_arr_join(left, wildcards_sa);
			wildcards_sa = ft_arr_join(left, right);
			free(to_wild);
			to_wild = wildcards_sa;
		}
		i++;
	}
	(*tree)->args = to_wild;
}

static void	apply_expand_totree(t_ast **tree, t_data data)
{
	char	**to_expand;
	char	*tmp;
	size_t	len;
	int		i;

	i = 0;
	to_expand = (*tree)->args;
	while (to_expand[i])
	{
		tmp = to_expand[i];
		tmp = expander(tmp, (*data.env));
		if (!tmp[0])
			free(tmp);
		else
		{
			len = ft_strlen(tmp);
			tmp = supp_quote(tmp);
			if (len > ft_strlen(tmp))
				(*tree)->quote_states[i] = 1;
			free(to_expand[i]);
			to_expand[i] = tmp;
		}
		i++;
	}
}

void	apply_exandwil(t_ast **tree, t_data data)
{
	apply_expand_totree(tree, data);
	apply_wildcard_totree(tree);
}
