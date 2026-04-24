/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_exec_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 12:53:59 by jleray            #+#    #+#             */
/*   Updated: 2026/04/24 13:41:58 by jleray           ###   ########.fr       */
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

// the first if check recursivly into ny tree in order to check for another trick.
// then execute normaly the redir and return the correct error with perror (still need to test the permission one)
static int	do_all_redirs(t_ast *tree, t_data *data)
{
	int	status;
	int	fd;

	status = 0;
	if (tree->left)
	{
		if (tree->left->type >= HEREDOC_AST
			&& tree->left->type <= REDIR_OUT_AST)
		{
			status = do_all_redirs(tree->left, data);
			if (status != 0)
				return (status);
		}
	}
	if (!ft_strcmp(tree->args[0], "<<"))
	{
		if (data->filesfd.fdin)
			close(data->filesfd.fdin);
		data->filesfd.fdin = tree->heredoc_fd;
	}
	else if (!ft_strcmp(tree->args[0], "<"))
	{
		if (data->filesfd.fdin > 2)
			close(data->filesfd.fdin);
		fd = open(tree->args[1], O_RDONLY);
		if (fd < 0)
		{
			perror("T&J Shell :");
			return (1);
		}
		data->filesfd.fdin = fd;
	}
	else if (!ft_strcmp(tree->args[0], ">") || !ft_strcmp(tree->args[0], ">>"))
	{
		if (exec_redirout_append(&tree, data) == -1)
			return (1);
	}
	return (0);
}

// New exec redir now go on the cmd before every redir ( in case they trick us into many redir )
// then exec do_all_redirs -> the name speak for itself
// if one of the redir return (an error ( 1 ) it will stop everything !);
// if everything is alr it will continue on exec_tree to exec the cmd node !
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
	if (node && node->type == CMD_AST)
		status = exec_tree(node, data);
	else if (node && node->type == HEREDOC_AST)
		status = exec_tree(node->right, data);
	if (data.filesfd.fdin > 2)
		close(data.filesfd.fdin);
	if (data.filesfd.fdout > 2)
		close(data.filesfd.fdout);
	return (status);
}

// int	exec_redir(t_ast *tree, t_data data)
// {
// int	fd;
// int	status;
//
// fd = 0;
// status = 0;
// if (!ft_strcmp(tree->args[0], "<<"))
// {
// if (data.filesfd.fdin > 2)
// close(data.filesfd.fdin);
// fd = tree->heredoc_fd;
// data.filesfd.fdin = fd;
// }
// if (!ft_strcmp(tree->args[0], "<"))
// {
// if (data.filesfd.fdin > 2)
// close(data.filesfd.fdin);
// fd = open(tree->args[1], O_RDONLY);
// data.filesfd.fdin = fd;
// }
// else if (!ft_strcmp(tree->args[0], ">") || !ft_strcmp(tree->args[0], ">>"))
// fd = exec_redirout_append(&tree, &data);
// if (fd == -2)
// {
// (*data.env)->exit_status = 130;
// return (130);
// }
// if (fd <= -1)
// {
// perror("T&J Shell ");
// (*data.env)->exit_status = 1;
// return (1);
// }
// if (tree->left)
// status = exec_tree(tree->left, data);
// if (tree->right)
// status = exec_tree(tree->right, data);
// if (fd > 2)
// close (fd);
// return (status);
// }
