/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 14:50:45 by jleray            #+#    #+#             */
/*   Updated: 2026/04/11 16:58:30 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

static t_ast	*create_treenode(t_lexer **lexhead, t_lexer *checkpoint)
{
	t_lexer	*right;
	t_lexer	*left;
	t_ast	*node;

	node = nodenew(checkpoint);
	if (!node)
		return (NULL);
	right = getright(*lexhead, node->old_lexindex);
	if (checkpoint->index > 1)
		left = getleft(lexhead, node->old_lexindex);
	else
		left = NULL;
	node_add(&node, make_tree(&left), LEFT);
	node_add(&node, make_tree(&right), RIGHT);
	if (node->type == PIPE_AST || node->type == OPERATOR_AST)
	{
		if (!node->left || !node->right)
		{
			ft_putstr_fd("Syntax Error\n", 2);
			ast_free(&node);
			return (NULL);
		}
	}
	return (node);
}

t_ast	*make_tree(t_lexer **lex)
{
	t_lexer	*tmp;
	t_ast	*node;

	tmp = get_last_cpoint(*lex);
	if (!tmp)
		return (NULL);
	else
		node = create_treenode(lex, tmp);
	return (node);
}
