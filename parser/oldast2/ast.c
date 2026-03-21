/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 13:40:04 by jleray            #+#    #+#             */
/*   Updated: 2026/03/13 14:34:13 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

// Add a step to check for heredoc, append and redir before word.
t_ast	*make_tree(char *str, t_ast **head)
{
	t_lexer	*lex;
	t_lexer	*tmp;
	t_ast	*ast;

	lex = lexer(str);
	ast = NULL;
	tmp = get_last_op(lex, OPERATOR);
	if (!tmp)
		tmp = get_last_op(lex, PIPE);
	if (tmp)
	{
		ast = create_treenodes(lex, tmp, head);
		if (!ast)
			return (NULL);
	}
	else
		ast = nodenew(lex->data, WORD, head);
	return (ast);
}
