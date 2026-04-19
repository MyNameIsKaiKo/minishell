/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_exec_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 19:02:17 by jleray            #+#    #+#             */
/*   Updated: 2026/04/19 19:37:15 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

int	exec_child(t_ast *tree, t_data data)
{
	char	**paths;
	char	*path;
	char	**env;

	if (ft_strcmp(tree->args[0], ".") == 0)
		exit_on_point(&tree, data.env, data);
	child_init(data);
	paths = find_path(data);
	path = find_cmdpath(paths, &tree, data.env);
	if (!path)
		cmd_path_error(paths, tree->args[0], &tree, data.env);
	env = reverse_env(data.env);
	if (!env)
		cmd_env_error(paths, path, &tree, data.env);
	execve(path, tree->args, env);
	perror("T&J Shell");
	free_all_in_child(&tree, data.env);
	free(path);
	free_sarr(paths);
	free_sarr(env);
	exit(126);
}

static int	handle_empty_cmd(t_ast *tree, t_data data)
{
	if (!tree->args[0] || tree->args[0][0] == '\0')
	{
		if (tree->args[0] && tree->args[0][0] == '\0')
		{
			write(2, "T&J Shell : command not founct\n", 31);
			(*data.env)->exit_status = 127;
			return (127);
		}
		return (0);
	}
	return (1);
}

static int	exec_non_builtin(t_ast *tree, t_data data)
{
	int		status;
	pid_t	cmd;

	cmd = fork();
	if (cmd == 0)
		exec_child(tree, data);
	if (data.filesfd.fdin > 2)
		close(data.filesfd.fdin);
	if (data.filesfd.fdout > 2)
		close(data.filesfd.fdout);
	waitpid(cmd, &status, 0);
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		status = 128 + WTERMSIG(status);
	return (status);
}

int	exec_cmd(t_ast *tree, t_data data)
{
	int		status;

	status = 0;
	status = handle_empty_cmd(tree, data);
	if (status != 1)
		return (status);
	if (!tree || !tree->args || !tree->args[0])
		return (0);
	if (is_builtin(tree->args[0]))
		status = exec_builtin(tree, data);
	else
		status = exec_non_builtin(tree, data);
	(*data.env)->exit_status = status;
	return (status);
}
