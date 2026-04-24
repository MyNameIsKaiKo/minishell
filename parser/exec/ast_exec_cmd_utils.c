/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_exec_cmd_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 11:40:36 by jleray            #+#    #+#             */
/*   Updated: 2026/04/24 13:28:08 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

void	child_init(t_data data)
{
	if (data.filesfd.fdin > 2)
	{
		dup2(data.filesfd.fdin, STDIN_FILENO);
		close(data.filesfd.fdin);
	}
	if (data.filesfd.fdout > 2)
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
	t_env	*tmp;

	if (!data.env)
		return (NULL);
	env = data.env;
	tmp = *env;
	while (tmp)
	{
		if (!ft_strncmp(tmp->name, "PATH", 4))
			break ;
		tmp = tmp->next;
	}
	if (!tmp)
		return (NULL);
	paths = find_directpath(tmp);
	if (!paths)
		return (NULL);
	return (paths);
}

static char	*join_the_path(char **paths, char *cmd)
{
	int		i;
	char	*path;

	i = 0;
	if (!paths)
		return (NULL);
	while (paths[i++])
	{
		path = ft_strjoin(paths[i - 1], cmd);
		if (!path)
			return (NULL);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
	}
	return (NULL);
}

char	*find_cmdpath(char **paths, t_ast **tree, t_env **env)
{
	char		*path;
	struct stat	st;
	char		*cmd;

	cmd = (*tree)->args[0];
	if (cmd[0] == '/')
	{
		if (stat(cmd, &st) == 0 && S_ISREG(st.st_mode) && !access(cmd, X_OK))
		{
			path = ft_strdup(cmd);
			return (path);
		}
		if (stat(cmd, &st) == 0 && S_ISDIR(st.st_mode) && !access(cmd, X_OK))
			directory_error(paths, cmd, tree, env);
	}
	else if (!ft_strncmp(cmd, "./", 2))
	{
		if (!access(cmd, X_OK))
		{
			path = ft_strdup(cmd);
			return (path);
		}
		else
			cmd_permision_denied(paths, tree, env);
	}
	path = join_the_path(paths, cmd);
	return (path);
}
