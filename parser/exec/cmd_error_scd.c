/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_error_scd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 19:47:34 by jleray            #+#    #+#             */
/*   Updated: 2026/04/24 11:57:57 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

void	directory_error(char **paths, char *cmd, t_ast **tree, t_env **env)
{
	char	*error_msg;
	char	*tmp;
	int		size;

	tmp = ft_strdup("T&J Shell : ");
	error_msg = ft_strjoin(tmp, cmd);
	free(tmp);
	tmp = error_msg;
	error_msg = ft_strjoin(tmp, ": Is a directory");
	free(tmp);
	tmp = error_msg;
	error_msg = ft_strjoin(tmp, "\n");
	size = ft_strlen(error_msg);
	write(2, error_msg, size);
	free(tmp);
	free(error_msg);
	free_sarr(paths);
	free_all_in_child(tree, env);
	exit(126);
}

void	cmd_permision_denied(char **paths, t_ast **tree, t_env **env)
{
	struct stat	st;
	char		*cmd;

	cmd = (*tree)->args[0];
	if (stat(cmd, &st) == 0 && S_ISDIR(st.st_mode))
		directory_error(paths, cmd, tree, env);
	perror("T&J Shell ");
	free_sarr(paths);
	free_all_in_child(tree, env);
	if (access(cmd, X_OK) && S_ISREG(st.st_mode))
		exit(126);
	exit(127);
}
