/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 14:43:30 by jleray            #+#    #+#             */
/*   Updated: 2026/03/28 15:17:20 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

int	exec_operator(t_ast *tree)
{
	int	output;

	if (!ft_strncmp(tree->data, "&&", 2))
	{
		output = exec_tree(tree);
		if (output)
			exec_tree(tree);
		return (1);
	}
	else if (ft_strncmp(tree->data, "||", 2))
	{
		output = exec_tree(tree);
		if (!output)
			exec_tree(tree);
		return (1);
	}
	return (0);
}

int	exec_tree(t_ast *tree)
{
	if (tree->type == OPERATOR_AST)
	{
		if (!exec_operator(tree))
			return (0);
	}
	else if (tree->type == PIPE_AST)
	{
		if (!exec_pipe(tree))
			return (0);
	}
	else if (tree->type >= HEREDOC_AST && tree->type <= REDIR_OUT_AST)
	{
		if (!exec_redir(tree))
			return (0);
	}
	else
	{
		if (!exec_cmd(tree))
			return (0);
	}
	return (1);
}
