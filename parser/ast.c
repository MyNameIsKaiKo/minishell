/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 14:50:45 by jleray            #+#    #+#             */
/*   Updated: 2026/04/19 18:16:57 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

static t_ast	*create_left(t_lexer **lexhead, t_lexer *checkpoint,
		t_ast **head, t_ast **curr)
{
	t_lexer	*left;
	t_ast	*node;
	t_ast	*left_node;

	node = *curr;
	if (checkpoint->index > 1)
		left = getleft(lexhead, checkpoint->index);
	else
		left = NULL;
	left_node = make_tree(&left, head);
	if (!left_node && left != NULL)
	{
		ast_free(curr);
		return (NULL);
	}
	return (left_node);
}

static t_ast	*create_right(t_lexer **lexhead, t_ast **head, t_ast **curr)
{
	t_lexer	*right;
	t_ast	*node;
	t_ast	*right_node;

	node = *curr;
	right = getright(*lexhead, node->old_lexindex);
	right_node = make_tree(&right, head);
	if (!right_node && right != NULL)
	{
		ast_free(curr);
		return (NULL);
	}
	return (right_node);
}

static t_ast	*create_treenode(t_lexer **lexhead, t_lexer *checkpoint,
		t_ast **head)
{
	t_ast	*right;
	t_ast	*left;
	t_ast	*node;

	node = nodenew(checkpoint, head);
	if (!node)
		return (NULL);
	right = create_right(lexhead, head, &node);
	if (!right && getright(*lexhead, node->old_lexindex) != NULL)
		return (NULL);
	left = create_left(lexhead, checkpoint, head, &node);
	if (!left && checkpoint->index > 1)
	{
		ast_free(&right);
		return (NULL);
	}
	if (node->type != SUBPROCESS_AST)
		node_add(&node, right, LEFT);
	node_add(&node, left, RIGHT);
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

	if (!lex || !head)
		return (NULL);
	tmp = get_last_cpoint(*lex);
	if (!tmp)
		return (NULL);
	else
		node = create_treenode(lex, tmp, head);
	return (node);
}
