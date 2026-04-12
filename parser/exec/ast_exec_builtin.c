/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_exec_builtin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 11:43:54 by jleray            #+#    #+#             */
/*   Updated: 2026/04/09 12:36:25 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

static void	builtin_init(t_data *data)
{
	if (data->filesfd.fdin > 2)
	{
		data->filesfd.fdintmp = dup(STDIN_FILENO);
		dup2(data->filesfd.fdin, STDIN_FILENO);
		close(data->filesfd.fdin);
	}
	if (data->filesfd.fdout > 2)
	{
		data->filesfd.fdouttmp = dup(STDOUT_FILENO);
		dup2(data->filesfd.fdout, STDOUT_FILENO);
		close(data->filesfd.fdout);
	}
}

static void	buildin_closefd(t_data *data)
{
	if (data->filesfd.fdin > 2)
	{
		dup2(data->filesfd.fdintmp, data->filesfd.fdin);
		close(data->filesfd.fdintmp);
	}
	if (data->filesfd.fdout > 2)
	{
		dup2(data->filesfd.fdouttmp, data->filesfd.fdout);
		close(data->filesfd.fdouttmp);
	}
}

static int	find_builtin(t_ast *tree, t_data data)
{
	t_env	**env;
	int		status;

	env = data.env;
	status = 0;
	if (!ft_strcmp(tree->args[0], "echo"))
		echo(tree->args + 1, *env);
	return (status);
}

int	exec_builtin(t_ast *tree, t_data data)
{
	builtin_init(&data);
	find_builtin(tree, data);
	buildin_closefd(&data);
	return (0);
}
