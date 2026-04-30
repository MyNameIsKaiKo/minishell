/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodenew_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 21:13:24 by jleray            #+#    #+#             */
/*   Updated: 2026/04/24 14:20:32 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ast.h"

static int	handle_redir(t_lexer *checkpoint, t_ast *node)
{
	int	output;

	if (!checkpoint->next || checkpoint->next->type != WORD)
		return (-1);
	node->args = malloc(sizeof(char *) * 3);
	if (checkpoint->next->is_squoted || checkpoint->next->is_dquoted)
		node->do_expand = 0;
	if (!node->args)
		return (0);
	node->args[0] = ft_strdup(checkpoint->data);
	node->args[1] = ft_strdup(checkpoint->next->data);
	node->args[2] = NULL;
	output = checkpoint->index + 1;
	return (output);
}

static int	handle_subprocess(t_lexer *checkpoint, t_ast *node, t_ast **head)
{
	char	*content;
	t_lexer	*sub_lex;

	content = ft_strtrim(checkpoint->data, "()");
	sub_lex = lexer(content);
	free(content);
	if (!sub_lex)
		return (-1);
	node->left = make_tree(&sub_lex, head);
	lexer_abs_free(&sub_lex);
	return (checkpoint->index);
}

void	handle_node_data(t_ast **new_node, t_lexer *checkpoint, t_ast **head)
{
	if ((*new_node)->type == CMD_AST)
		(*new_node)->old_lexindex = handle_cmds_nodenew(checkpoint, *new_node);
	else if ((*new_node)->type >= HEREDOC_AST
		&& (*new_node)->type <= REDIR_OUT_AST)
		(*new_node)->old_lexindex = handle_redir(checkpoint, *new_node);
	else if ((*new_node)->type == SUBPROCESS_AST)
		(*new_node)->old_lexindex = handle_subprocess(checkpoint, *new_node,
				head);
	else
	{
		(*new_node)->data = ft_strdup(checkpoint->data);
		(*new_node)->old_lexindex = checkpoint->index;
	}
}
