/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_exec_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 19:02:17 by jleray            #+#    #+#             */
/*   Updated: 2026/04/15 20:35:42 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

int	exec_child(t_ast *tree, t_data data)
{
	char	**paths;
	char	*path;
	char	**env;

	child_init(data);
	paths = find_path(data);
	if (!paths)
		cmd_error(tree->args[0], &tree->head, data.env);
	path = find_cmdpath(paths, tree->args[0]);
	if (!path)
		cmd_path_error(paths, tree->args[0], &tree, data.env);
	env = reverse_env(data.env);
	if (!env)
		cmd_env_error(paths, path, &tree, data.env);
	execve(path, tree->args, env);
	free_all_in_child(&tree, data.env);
	free(path);
	free_sarr(paths);
	free_sarr(env);
	exit(1);
}

int	exec_cmd(t_ast *tree, t_data data)
{
	pid_t	cmd;
	int		status;
	int		sig;

	status = 0;
	if (!tree || !tree->args || !tree->args[0])
		return (1);
	if (is_builtin(tree->args[0]))
		status = exec_builtin(tree, data);
	else
	{
		cmd = fork();
		if (cmd == 0)
			exec_child(tree, data);
		waitpid(cmd, &status, 0);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
		else if (WIFSIGNALED(status))
		{
			sig = WTERMSIG(status);
			if (sig == SIGINT)
				return (130);
		}
	}
	return (status);
}
