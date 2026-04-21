/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_exec_cmd_exandwil.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 19:38:01 by jleray            #+#    #+#             */
/*   Updated: 2026/04/21 18:28:31 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

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

static void	shift_sarr(t_ast **tree, char **sarr, int i)
{
	int	j;

	j = i;
	while (sarr[j])
	{
		sarr[j] = sarr[j + 1];
		(*tree)->quote_states[j] = (*tree)->quote_states[j + 1];
		j++;
	}
}

static void	replace_to_expand(t_ast **tree, char **to_expand, int i, char *tmp)
{
	size_t	len;
	char	*supped_quotes;

	len = ft_strlen(tmp);
	supped_quotes = supp_quote(tmp);
	if (len > ft_strlen(supped_quotes))
		(*tree)->quote_states[i] = 1;
	to_expand[i] = supped_quotes;
}

static void	apply_expand_totree(t_ast **tree, t_data data)
{
	char	**to_expand;
	char	*tmp;
	int		i;

	i = 0;
	to_expand = (*tree)->args;
	while (to_expand[i])
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
