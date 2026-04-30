/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 14:50:45 by jleray            #+#    #+#             */
/*   Updated: 2026/04/21 21:10:33 by jleray           ###   ########.fr       */
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
		*curr = NULL;
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
		*curr = NULL;
		return (NULL);
	}
	return (right_node);
}

static void	add_the_nodes(t_ast **node, t_ast *left, t_ast *right)
{
	if ((*node)->type != SUBPROCESS_AST)
		node_add(node, left, LEFT);
	else if (left != NULL)
		ast_free(&left);
	node_add(node, right, RIGHT);
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
	if (!node)
		return (NULL);
	left = create_left(lexhead, checkpoint, head, &node);
	if (!node)
	{
		ast_free(&right);
		return (NULL);
	}
	add_the_nodes(&node, left, right);
	if ((node->type == PIPE_AST || node->type == OPERATOR_AST) && (!node->left
			|| !node->right))
	{
		ast_free(&node);
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
