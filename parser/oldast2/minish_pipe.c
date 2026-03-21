/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:54:14 by jleray            #+#    #+#             */
/*   Updated: 2026/02/20 16:54:41 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	handle_child(int pipefd[2], t_node *tree, int side)
{
	int	status;

	if (side == 0)
	{
		dup2(pipefd[0], STDOUT_FILENO);
		status = exec_tree(tree->left);
	}
	else
	{
		dup2(pipefd[1], STDIN_FILENO);
		status = exec_tree(tree->right);
	}
	close(pipefd[0]);
	close(pipefd[1]);
	return (status);
}

int	pipe_exec(t_node *tree)
{
	pid_t	fst_cmd;
	pid_t	scd_cmd;
	int		pipefd[2];
	int		status;

	pipe(pipefd);
	fst_cmd = fork();
	if (fst_cmd == 0)
	{
		status = handle_child(pipefd, tree, 0);
		exit(status);
	}
	scd_cmd = fork();
	if (fst_cmd == 0)
	{
		status = handle_child(pipefd, tree, 0);
		exit(status);
	}
	close(pipefd[0]);
	close(pipefd[1]);
	return (0);
}
