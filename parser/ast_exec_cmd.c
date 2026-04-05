/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_exec_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 19:02:17 by jleray            #+#    #+#             */
/*   Updated: 2026/04/04 11:59:46 by jleray           ###   ########.fr       */
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
		return (cmd_error(tree->args[0]));
	path = find_cmdpath(paths, tree->args[0]);
	if (!path)
		return (0);
	env = reverse_env(data.env);
	if (!env)
		return (0);
	if (execve(path, tree->args, env) == -1)
	{
		free(path);
		free_sarr(paths);
		free_sarr(env);
		return (0);
	}
	return (1);
}

int	exec_cmd(t_ast *tree, t_data data)
{
	pid_t	cmd;
	int		status;

	status = 0;
	printf("\nExecuting command : %s\n", tree->args[0]);
	if (is_builtin(tree->args[0]))
		exec_builtin(tree, data);
	else
	{
		cmd = fork();
		if (cmd == 0)
			status = exec_child(tree, data);
		waitpid(cmd, NULL, 0);
		if (status != 1)
			printf("TODO : Status return and status error \n");
	}
	return (1);
}
