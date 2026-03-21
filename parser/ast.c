/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 14:50:45 by jleray            #+#    #+#             */
/*   Updated: 2026/03/21 19:47:50 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_ast	*create_treenode(t_lexer **lexhead, t_lexer *checkpoint, t_ast **ast)
{
	t_lexer	*right;
	t_lexer	*left;
	t_ast	*node;

	node = nodenew(lexhead, checkpoint, ast);
	if (!node)
	{
		// todo node_free
		return (NULL);
	}
	left = getleft(*lexhead, node->old_lexindex);
	right = getright(*lexhead, node->old_lexindex);
	node_add(&node, make_tree(&left, ast), LEFT);
	node_add(&node, make_tree(&right, ast), RIGHT);
	return (node);
}

t_ast	*make_tree(t_lexer **lex, t_ast **ast)
{
	t_lexer	*tmp;
	t_ast	*node;

	tmp = get_last_cpoint(*lex);
	if (!tmp)
		return (NULL);
	else
	{
		node = create_treenode(lex, tmp, ast);
		if (!node)
			return (NULL);
	}
	return (node);
}
