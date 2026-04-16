/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 12:26:04 by jleray            #+#    #+#             */
/*   Updated: 2026/04/16 18:29:26 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

void	free_all_in_child(t_ast **tree, t_env **env)
{
	t_ast	*node;

	node = *tree;
	if (env)
		free_env(*env);
	ast_free(&node->head);
	rl_clear_history();
}

int	cmd_path_error(char **paths, char *cmd, t_ast **tree, t_env **env)
{
	char	*error_msg;
	char	*tmp;
	int		size;

	tmp = ft_strdup("Command not found : ");
	error_msg = ft_strjoin(tmp, cmd);
	free(tmp);
	tmp = error_msg;
	error_msg = ft_strjoin(tmp, "\n");
	size = ft_strlen(error_msg);
	write(2, error_msg, size);
	free(tmp);
	free(error_msg);
	free_sarr(paths);
	free_all_in_child(tree, env);
	exit(127);
}

void	cmd_env_error(char **paths, char *path, t_ast **tree, t_env **env)
{
	t_ast	*node;

	node = *tree;
	free_sarr(paths);
	free(path);
	cmd_error(node->args[0], &node->head, env);
}

int	cmd_error(char *cmd, t_ast **tree, t_env **env)
{
	char	*error_msg;
	char	*tmp;
	int		size;

	tmp = ft_strdup("Command not found : ");
	error_msg = ft_strjoin(tmp, cmd);
	free(tmp);
	tmp = error_msg;
	error_msg = ft_strjoin(tmp, "\n");
	size = ft_strlen(error_msg);
	write(2, error_msg, size);
	free(tmp);
	free(error_msg);
	free_all_in_child(tree, env);
	exit(0);
}
