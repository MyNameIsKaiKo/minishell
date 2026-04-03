/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_exec_cmd_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 11:40:36 by jleray            #+#    #+#             */
/*   Updated: 2026/04/03 17:53:38 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

int	is_builtin(char *str)
{
	if (!ft_strcmp(str, "echo"))
		return (1);
	if (!ft_strcmp(str, "cd"))
		return (1);
	if (!ft_strcmp(str, "pwd"))
		return (1);
	if (!ft_strcmp(str, "export"))
		return (1);
	if (!ft_strcmp(str, "unset"))
		return (1);
	if (!ft_strcmp(str, "env"))
		return (1);
	if (!ft_strcmp(str, "exit"))
		return (1);
	return (0);
}

void	child_init(t_data data)
{
	if (data.filesfd.fdin > 1)
	{
		dup2(data.filesfd.fdin, STDIN_FILENO);
		close(data.filesfd.fdin);
	}
	if (data.filesfd.fdout > 1)
	{
		dup2(data.filesfd.fdout, STDOUT_FILENO);
		close(data.filesfd.fdout);
	}
	return ;
}

static char	**find_directpath(t_env *env)
{
	int		i;
	char	**output;
	char	*path;

	if (ft_strncmp(env->name, "PATH", 4))
		return (NULL);
	output = ft_split(env->value, ':');
	if (!output)
		return (NULL);
	i = 0;
	while (output[i++])
	{
		path = output[i - 1];
		output[i - 1] = ft_strjoin(path, "/");
		if (!output[i - 1])
		{
			free_sarr(output);
			return (NULL);
		}
		free(path);
	}
	return (output);
}

char	**find_path(t_data data)
{
	t_env	**env;
	char	**paths;

	env = data.env;
	while (*env)
	{
		if (!ft_strncmp((*env)->name, "PATH", 4))
			break ;
		(*env) = (*env)->next;
	}
	if (!env)
		return (NULL);
	paths = find_directpath(*env);
	if (!paths)
		return (NULL);
	return (paths);
}

char	*find_cmdpath(char **paths, char *cmd)
{
	int		i;
	char	*path;

	i = 0;
	if ((cmd[0] == '/' || ft_strncmp(cmd, "./", 2) == 0) && access(cmd,
			X_OK) == 0)
	{
		path = ft_strdup(cmd);
		return (path);
	}
	while (paths[i])
	{
		path = ft_strjoin(paths[i], cmd);
		if (!path)
			return (NULL);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}
