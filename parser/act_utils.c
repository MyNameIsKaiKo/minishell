/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 15:30:36 by jleray            #+#    #+#             */
/*   Updated: 2026/03/22 17:32:24 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

static int	is_a_checkpoint(t_token_type lex_type, t_token_type current)
{
	if (!current && (lex_type >= WORD && lex_type <= OPERATOR))
		return (1);
	if (current == OPERATOR && lex_type >= current)
		return (1);
	if (current == PIPE && lex_type >= current)
		return (1);
	if ((current >= REDIR_IN && current <= APPEND) && lex_type >= current)
		return (1);
	if ((current >= WORD && current <= SUBPROCESS) && lex_type >= current)
		return (0);
	return (0);
}

t_lexer	*get_last_cpoint(t_lexer *lex)
{
	t_lexer	*output;

	if (!lex)
		return (NULL);
	output = lex;
	if (!lex->next)
		return (lex);
	while (lex)
	{
		if (is_a_checkpoint(lex->type, output->type))
			output = lex;
		lex = lex->next;
	}
	return (output);
}

t_lexer	*getleft(t_lexer **lex, int index)
{
	t_lexer	*tmp;

	tmp = *lex;
	if (index - 1 == 1)
	{
		tmp->next = NULL;
		return (tmp);
	}
	else
	{
		while (tmp->index != index - 1)
			tmp = tmp->next;
		tmp->next = NULL;
	}
	indexing_lex(lex);
	return (*lex);
}

t_lexer	*getright(t_lexer *lex, int index)
{
	t_lexer	*tmp;

	tmp = find_by_index(lex, index + 1);
	if (tmp)
	{
		indexing_lex(&tmp);
		return (tmp);
	}
	return (NULL);
}
