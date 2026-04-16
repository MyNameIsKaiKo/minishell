/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_exec_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 15:57:13 by jleray            #+#    #+#             */
/*   Updated: 2026/04/16 23:56:21 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

void	handle_first(t_ast *tree, t_data data, int pipefd[2])
{
	int	status;

	if (data.filesfd.fdin < 0)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		exit(127);
	}
	close(pipefd[0]);
	if (data.filesfd.fdout > 2)
		close(data.filesfd.fdout);
	data.filesfd.fdout = pipefd[1];
	status = exec_tree(tree->left, data);
	ast_free(&tree->head);
	free_env(*(data.env));
	rl_clear_history();
	exit(status);
}

void	handle_scd(t_ast *tree, t_data data, int pipefd[2])
{
	int	status;

	if (data.filesfd.fdout < 0)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		exit(127);
	}
	close(pipefd[1]);
	if (data.filesfd.fdin > 2)
		close(data.filesfd.fdin);
	data.filesfd.fdin = pipefd[0];
	status = exec_tree(tree->right, data);
	ast_free(&tree->head);
	free_env(*(data.env));
	rl_clear_history();
	exit(status);
}

int	exec_pipe(t_ast *tree, t_data data)
{
	int		pipefd[2];
	pid_t	scd_child;
	pid_t	first_child;
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
	if (data.filesfd.fdin > 2)
		close(data.filesfd.fdin);
	if (data.filesfd.fdout > 2)
		close(data.filesfd.fdout);
	waitpid(first_child, NULL, 0);
	waitpid(scd_child, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (1);
}
