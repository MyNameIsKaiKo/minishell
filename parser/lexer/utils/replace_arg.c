/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 21:26:23 by jleray            #+#    #+#             */
/*   Updated: 2026/04/16 23:16:22 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

static t_lexer	*find_to_replace(t_lexer *lex)
{
	t_lexer	*tmp;
	t_lexer	*is_args;

	tmp = lex;
	while (tmp && tmp->type != HEREDOC)
		tmp = tmp->next;
	if (!tmp)
		return (NULL);
	if (tmp->index == 1)
		return (NULL);
	is_args = find_by_index(lex, tmp->index + 2);
	if (!is_args)
		return (NULL);
	if (is_args->data[0] == '-')
		return (is_args);
	return (NULL);
}

void	replace_arg(t_lexer **lex)
{
	t_lexer	*to_replace;
	t_lexer	*is_cmd;
	t_lexer	*is_heredoc;
	t_lexer	*is_eof;

	to_replace = find_to_replace(*lex);
	if (!to_replace)
		return ;
	is_cmd = find_by_index(*lex, to_replace->index - 3);
	is_heredoc = find_by_index(*lex, to_replace->index - 2);
	is_eof = find_by_index(*lex, to_replace->index - 1);
	lexer_set_next(&is_eof, to_replace->next);
	lexer_set_next(&to_replace, is_heredoc);
	lexer_set_next(&is_cmd, to_replace);
	indexing_lex(lex);
	return ;
}
