/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodenew.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 20:19:58 by jleray            #+#    #+#             */
/*   Updated: 2026/04/24 14:15:55 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ast.h"

static void	get_ast_type(t_lexer *checkpoint, t_ast **ast)
{
	const t_token_type	type = checkpoint->type;

	if (type == HEREDOC)
		(*ast)->type = HEREDOC_AST;
	else if (type == APPEND)
		(*ast)->type = APPEND_AST;
	else if (type == REDIR_IN)
		(*ast)->type = REDIR_IN_AST;
	else if (type == REDIR_OUT)
		(*ast)->type = REDIR_OUT_AST;
	else if (type == WORD)
		(*ast)->type = CMD_AST;
	else if (type == OPERATOR)
		(*ast)->type = OPERATOR_AST;
	else if (type == PIPE)
		(*ast)->type = PIPE_AST;
	else if (type == SUBPROCESS)
		(*ast)->type = SUBPROCESS_AST;
}

t_ast	*nodenew(t_lexer *checkpoint, t_ast **head)
{
	t_ast	*new_node;

	new_node = malloc(sizeof(t_ast));
	if (!new_node)
		return (NULL);
	if (head && !(*head))
		*head = new_node;
	if (!head)
		new_node->head = new_node;
	else
		new_node->head = *head;
	new_node->args = NULL;
	new_node->data = NULL;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->quote_states = NULL;
	new_node->heredoc_fd = -1;
	new_node->old_lexindex = -1;
	new_node->do_expand = 1;
	get_ast_type(checkpoint, &new_node);
	handle_node_data(&new_node, checkpoint, head);
	if (new_node->old_lexindex == -1)
	{
		ast_free(&new_node);
		return (NULL);
	}
	return (new_node);
}
