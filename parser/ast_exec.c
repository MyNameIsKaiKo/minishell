/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 14:43:30 by jleray            #+#    #+#             */
/*   Updated: 2026/04/03 16:53:24 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

int	exec_operator(t_ast *tree, t_data data)
{
	int	output;

	if (!ft_strncmp(tree->data, "&&", 2))
	{
		output = exec_tree(tree->left, data);
		if (output)
			exec_tree(tree->right, data);
		return (1);
	}
	else if (!ft_strncmp(tree->data, "||", 2))
	{
		output = exec_tree(tree->left, data);
		if (!output)
			exec_tree(tree->right, data);
		return (1);
	}
	return (0);
}

int	exec_redir(t_ast *tree, t_data data)
{
	int	fd;

	fd = 0;
	if (!ft_strcmp(tree->args[0], "<"))
	{
		if (data.filesfd.fdin > 2)
			close(data.filesfd.fdin);
		fd = open(tree->args[1], O_RDONLY);
		data.filesfd.fdin = fd;
	}
	else if (!ft_strcmp(tree->args[0], ">") || !ft_strcmp(tree->args[0], ">>"))
	{
		if (data.filesfd.fdout > 2)
			close(data.filesfd.fdout);
		if (!ft_strcmp(tree->args[0], ">"))
			fd = open(tree->args[1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
		else
			fd = open(tree->args[1], O_CREAT | O_APPEND | O_WRONLY, 0644);
		data.filesfd.fdout = fd;
	}
	if (tree->left)
		exec_tree(tree->left, data);
	if (tree->right)
		exec_tree(tree->right, data);
	return (fd);
}

int	exec_subprocess(t_ast *tree, t_data data)
{
	if (tree->type == SUBPROCESS_AST)
	{
		if (!exec_tree(tree->left, data))
			return (0);
	}
	return (1);
}

int	exec_tree(t_ast *tree, t_data data)
{
	int	output;

	output = 0;
	if (tree->type == OPERATOR_AST)
		output = exec_operator(tree, data);
	else if (tree->type == PIPE_AST)
		output = exec_pipe(tree, data);
	else if (tree->type >= HEREDOC_AST && tree->type <= REDIR_OUT_AST)
		output = exec_redir(tree, data);
	else if (tree->type == SUBPROCESS_AST)
		output = exec_subprocess(tree, data);
	else
		output = exec_cmd(tree, data);
	return (output);
}
