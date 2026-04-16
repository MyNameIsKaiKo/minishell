/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 14:50:45 by jleray            #+#    #+#             */
/*   Updated: 2026/04/15 22:50:39 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

static t_ast	*create_treenode(t_lexer **lexhead, t_lexer *checkpoint,
		t_ast **head)
{
	t_lexer	*right;
	t_lexer	*left;
	t_ast	*node;

	node = nodenew(checkpoint, head);
	if (!node)
		return (NULL);
	right = getright(*lexhead, node->old_lexindex);
	if (checkpoint->index > 1)
		left = getleft(lexhead, checkpoint->index);
	else
		left = NULL;
	node_add(&node, make_tree(&left, head), LEFT);
	node_add(&node, make_tree(&right, head), RIGHT);
	if (node->type == PIPE_AST || node->type == OPERATOR_AST)
	{
		if (!node->left || !node->right)
			return (NULL);
	}
	return (node);
}

t_ast	*make_tree(t_lexer **lex, t_ast **head)
{
	t_lexer	*tmp;
	t_ast	*node;

	tmp = get_last_cpoint(*lex);
	if (!tmp)
		return (NULL);
	else
		node = create_treenode(lex, tmp, head);
	return (node);
}
