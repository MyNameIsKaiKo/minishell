/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_exec_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 12:53:59 by jleray            #+#    #+#             */
/*   Updated: 2026/05/04 14:29:38 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

static int	exec_redirout_append(t_ast **tree, t_data *data)
{
	int	fd;

	fd = 0;
	if (data->filesfd.fdout > 2)
		close(data->filesfd.fdout);
	if (!ft_strcmp((*tree)->args[0], ">"))
		fd = open((*tree)->args[1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
	else
		fd = open((*tree)->args[1], O_CREAT | O_APPEND | O_WRONLY, 0644);
	data->filesfd.fdout = fd;
	if (fd < 0)
	{
		perror("T&J Shell ");
		return (-1);
	}
	return (fd);
}

static int	exec_redirin(t_ast **tree, t_data *data)
{
	int	fd;

	fd = 0;
	if (data->filesfd.fdin > 2)
		close(data->filesfd.fdin);
	fd = open((*tree)->args[1], O_RDONLY);
	if (fd < 0)
	{
		perror("T&J Shell :");
		return (-1);
	}
	data->filesfd.fdin = fd;
	return (fd);
}

static int	go_left_redirs(t_ast **trees, t_data *data, int *status)
{
	t_ast	*tree;

	tree = *trees;
	if (tree->left)
	{
		if (tree->left->type >= HEREDOC_AST
			&& tree->left->type <= REDIR_OUT_AST)
		{
			*status = do_all_redirs(tree->left, data);
			if (*status != 0)
				return (*status);
		}
	}
	return (1025);
}

int	do_all_redirs(t_ast *tree, t_data *data)
{
	int	status;

	status = 0;
	if (go_left_redirs(&tree, data, &status) != 1025)
		return (status);
	if (!ft_strcmp(tree->args[0], "<<"))
	{
		if (data->filesfd.fdin)
			close(data->filesfd.fdin);
		data->filesfd.fdin = tree->heredoc_fd;
	}
	else if (!ft_strcmp(tree->args[0], "<"))
	{
		if (exec_redirin(&tree, data) == -1)
			return (1);
	}
	else if (!ft_strcmp(tree->args[0], ">") || !ft_strcmp(tree->args[0], ">>"))
	{
		if (exec_redirout_append(&tree, data) == -1)
			return (1);
	}
	status = fix_heredoc_command_after(&tree, data);
	if (status != 0)
		return (status);
	return (0);
}

int	exec_redir(t_ast *tree, t_data data)
{
	t_ast	*node;
	int		status;

	node = tree;
	status = 0;
	while (node && node->type >= HEREDOC_AST && node->type <= REDIR_OUT_AST)
		node = node->left;
	if (!node)
		node = tree;
	status = do_all_redirs(tree, &data);
	if (status != 0)
	{
		(*data.env)->exit_status = 1;
		return (status);
	}
	if (node && (node->type == CMD_AST || node->type == SUBPROCESS_AST))
		status = exec_tree(node, data);
	else if (node && node->type == HEREDOC_AST && node->right
		&& node->right->type == CMD_AST)
		status = exec_tree(node->right, data);
	if (data.filesfd.fdin > 2)
		close(data.filesfd.fdin);
	if (data.filesfd.fdout > 2)
		close(data.filesfd.fdout);
	return (status);
}
