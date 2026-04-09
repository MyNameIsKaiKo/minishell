/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_exec_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 12:53:59 by jleray            #+#    #+#             */
/*   Updated: 2026/04/09 14:14:46 by jleray           ###   ########.fr       */
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
	return (fd);
}

int	exec_redir(t_ast *tree, t_data data)
{
	int	fd;
	int	status;

	fd = 0;
	if (!ft_strcmp(tree->args[0], "<<"))
		exec_heredoc(tree->args[1], &data);
	if (!ft_strcmp(tree->args[0], "<"))
	{
		if (data.filesfd.fdin > 2)
			close(data.filesfd.fdin);
		fd = open(tree->args[1], O_RDONLY);
		data.filesfd.fdin = fd;
	}
	else if (!ft_strcmp(tree->args[0], ">") || !ft_strcmp(tree->args[0], ">>"))
		fd = exec_redirout_append(&tree, &data);
	if (fd <= -1)
	{
		perror("t&j Shell :");
		return (127);
	}
	if (tree->left)
		status = exec_tree(tree->left, data);
	if (tree->right)
		status = exec_tree(tree->right, data);
	return (status);
}
