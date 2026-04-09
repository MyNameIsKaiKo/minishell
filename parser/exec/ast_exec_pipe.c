/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_exec_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 15:57:13 by jleray            #+#    #+#             */
/*   Updated: 2026/04/09 13:29:36 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

void	handle_first(t_ast *tree, t_data data, int pipefd[2])
{
	if (data.filesfd.fdin < 0)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		exit(127);
	}
	dup2(data.filesfd.fdin, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(data.filesfd.fdin);
	close(pipefd[0]);
	close(pipefd[1]);
	exit(exec_tree(tree->left, data));
}

void	handle_scd(t_ast *tree, t_data data, int pipefd[2])
{
	if (data.filesfd.fdout < 0)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		exit(127);
	}
	dup2(pipefd[0], STDIN_FILENO);
	dup2(data.filesfd.fdout, STDOUT_FILENO);
	close(data.filesfd.fdout);
	close(pipefd[0]);
	close(pipefd[1]);
	exit(exec_tree(tree->right, data));
}

int	exec_pipe(t_ast *tree, t_data data)
{
	int		pipefd[2];
	pid_t	first_child;
	pid_t	scd_child;
	int		status;

	if (pipe(pipefd))
		return (pipe_error(data));
	first_child = fork();
	if (first_child == 0)
		handle_first(tree, data, pipefd);
	scd_child = fork();
	if (scd_child == 0)
		handle_scd(tree, data, pipefd);
	close(pipefd[0]);
	close(pipefd[1]);
	close(data.filesfd.fdin);
	close(data.filesfd.fdout);
	waitpid(first_child, NULL, 0);
	waitpid(scd_child, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}
