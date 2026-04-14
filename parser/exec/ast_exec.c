/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 14:43:30 by jleray            #+#    #+#             */
/*   Updated: 2026/04/11 16:53:20 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

int	exec_operator(t_ast *tree, t_data data)
{
	int		output;
	t_env	**env;

	env = data.env;
	if (!ft_strncmp(tree->data, "&&", 2))
	{
		output = exec_tree(tree->left, data);
		if (output == 0 && (*env)->is_valid_exit != 1)
			output = exec_tree(tree->right, data);
		return (output);
	}
	else if (!ft_strncmp(tree->data, "||", 2))
	{
		output = exec_tree(tree->left, data);
		if (output && (*env)->is_valid_exit != 1)
			output = exec_tree(tree->right, data);
		return (output);
	}
	return (1);
}

int	exec_subprocess(t_ast *tree, t_data data)
{
	int	output;
	pid_t	subprocess;

	output = 0;
	subprocess = fork();
	if (subprocess == -1)
		return (1);
	if (subprocess == 0)
	{
		status = exec_tree(tree->left, data);
		exit(status);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}
	
	return (output);
}

int	exec_tree(t_ast *tree, t_data data)
{
	int	output;

	output = 0;
	if (!tree)
		return (127);
	if (tree->type == OPERATOR_AST)
		output = exec_operator(tree, data);
	else if (tree->type == PIPE_AST)
		output = exec_pipe(tree, data);
	else if (tree->type >= HEREDOC_AST && tree->type <= REDIR_OUT_AST)
		output = exec_redir(tree, data);
	else if (tree->type == SUBPROCESS_AST)
		output = exec_subprocess(tree, data);
	else
		output = exec_cmd(tree, data);
	return (output);
}
