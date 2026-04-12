/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 15:30:36 by jleray            #+#    #+#             */
/*   Updated: 2026/03/22 21:13:21 by jleray           ###   ########.fr       */
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
	if ((current >= WORD && current <= SUBPROCESS) && lex_type >= current
		&& lex_type > SUBPROCESS)
		return (1);
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

	if (!lex || !*lex)
		return (NULL);
	if (index <= 1)
		return (NULL);
	tmp = *lex;
	while (tmp && tmp->next && tmp->next->index != index)
		tmp = tmp->next;
	if (tmp)
		tmp->next = NULL;
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
