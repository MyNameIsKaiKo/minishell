/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 14:43:30 by jleray            #+#    #+#             */
/*   Updated: 2026/03/28 19:02:02 by jleray           ###   ########.fr       */
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

int	exec_pipe(t_ast *tree)
{
	(void)tree;
	return (0);
}

int	exec_redir(t_ast *tree)
{
	int	fd;

	fd = 0;
	if (!ft_strcmp(tree->args[0], "<"))
	{
		fd = open(tree->args[1], O_RDONLY);
		tree->filesfd.fdin = fd;
	}
	else if (!ft_strcmp(tree->args[0], ">") || !ft_strcmp(tree->args[0], ">>"))
	{
		fd = open(tree->args[1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
		tree->filesfd.fdout = fd;
	}
	if (tree->left)
		exec_tree(tree->left);
	if (tree->right)
		exec_tree(tree->right);
	return (fd);
}

int	exec_subprocess(t_ast *tree)
{
	if (tree->type == SUBPROCESS_AST)
	{
		if (!exec_tree(tree->left))
			return (0);
	}
	return (1);
}

int	exec_tree(t_ast *tree)
{
	int	output;

	output = 0;
	tree->filesfd.fdin = -1;
	tree->filesfd.fdout = -1;
	if (tree->type == OPERATOR_AST)
		output = exec_operator(tree);
	else if (tree->type == PIPE_AST)
		output = exec_pipe(tree);
	else if (tree->type >= HEREDOC_AST && tree->type <= REDIR_OUT_AST)
		output = exec_redir(tree);
	else if (tree->type == SUBPROCESS_AST)
		output = exec_subprocess(tree);
	else
		output = exec_cmds(tree);
	return (output);
}
