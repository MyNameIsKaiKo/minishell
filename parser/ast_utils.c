/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:00:33 by jleray            #+#    #+#             */
/*   Updated: 2026/03/12 17:19:57 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_lexer	*get_last_op(t_lexer *lex, t_token_type operator)
{
	t_lexer	*output;

	output = NULL;
	while (lex)
	{
		if (lex->type == operator)
			output = lex;
		lex = lex->next;
	}
	return (output);
}

static t_lexer	*getside(t_lexer *lex, t_side side, int op_index)
{
	t_lexer	*tmp;

	if (side == LEFT)
	{
		tmp = find_by_index(lex, op_index - 1);
		return (tmp);
	}
	else if (side == RIGHT)
	{
		tmp = find_by_index(lex, op_index + 1);
		return (tmp);
	}
	return (NULL);
}

t_ast	*create_treenodes(t_lexer *lex, t_lexer *is_op, t_ast **head)
{
	t_ast	*ast;
	t_lexer	*right;
	t_lexer	*left;

	left = getside(lex, LEFT, is_op->index);
	right = getside(lex, RIGHT, is_op->index);
	ast = nodenew(is_op->data, is_op->type, head);
	if (!ast)
	{
		ast_free(head);
		return (NULL);
	}
	node_add(&ast, nodenew(left->data, left->type, head), LEFT);
	node_add(&ast, nodenew(right->data, right->type, head), RIGHT);
	return (ast);
}
