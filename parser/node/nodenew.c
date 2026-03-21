/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodenew.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 15:22:27 by jleray            #+#    #+#             */
/*   Updated: 2026/03/21 19:38:36 by jleray           ###   ########.fr       */
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

// TODO ON RETURN 0 PRINT SYNTAX ERROR
static int	handle_cmd(t_lexer **lexhead, t_lexer *checkpoint, t_ast **node)
{
	const int	index = checkpoint->index;
	t_lexer		*next;
	t_lexer		*merged_lex;

	next = find_by_index(*lexhead, index + 1);
	if (next && !ft_strncmp(next->data, "-", 1))
	{
		merged_lex = lexer_merge(lexhead, index, index + 1, checkpoint->type);
		(*node)->data = ft_strdup(merged_lex->data);
		return (merged_lex->index);
	}
	else
		(*node)->data = ft_strdup(checkpoint->data);
	return (checkpoint->index);
}

// TODO ON RETURN 0 PRINT SYNTAX ERROR
static int	handle_redir(t_lexer **lexhead, t_lexer *checkpoint, t_ast **node)
{
	const int	index = checkpoint->index;
	t_lexer		*next;
	t_lexer		*merged_lex;

	next = find_by_index(*lexhead, index + 1);
	if (!next || next->type != WORD)
		return (0);
	merged_lex = lexer_merge(lexhead, index, index + 1, checkpoint->type);
	(*node)->data = ft_strdup(merged_lex->data);
	(*node)->old_lexindex = merged_lex->index;
	return (merged_lex->index);
}

static int	handle_data(t_lexer **lexhead, t_lexer *checkpoint, t_ast **node)
{
	const t_token_ast	type = (*node)->type;
	int					output;

	output = 0;
	if (type == HEREDOC_AST || type == APPEND_AST || type == REDIR_IN_AST
		|| type == REDIR_OUT_AST)
		output = handle_redir(lexhead, checkpoint, node);
	if (type == CMD_AST)
		output = handle_cmd(lexhead, checkpoint, node);
	else
	{
		(*node)->data = ft_strdup(checkpoint->data);
		output = checkpoint->index;
	}
	return (output);
}

t_ast	*nodenew(t_lexer **lexhead, t_lexer *checkpoint, t_ast **ast)
{
	t_ast	*new_node;
	int		index;

	new_node = malloc(sizeof(t_ast));
	if (!new_node)
		return (NULL);
	if (!*ast)
		*ast = new_node;
	new_node->head = *ast;
	get_ast_type(checkpoint, &new_node);
	new_node->left = NULL;
	new_node->right = NULL;
	index = handle_data(lexhead, checkpoint, &new_node);
	if (index == 0)
	{
		free(new_node->data);
		return (NULL);
	}
	else
		new_node->old_lexindex = index;
	return (new_node);
}
