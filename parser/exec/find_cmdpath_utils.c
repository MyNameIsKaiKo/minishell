/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmdpath_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:39:54 by jleray            #+#    #+#             */
/*   Updated: 2026/04/29 12:39:54 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

char	*find_cmdpath_utils(t_ast **tree, t_env **env, char **paths)
{
	char		*cmd;
	char		*path;
	struct stat	st;

	cmd = (*tree)->args[0];
	if (stat(cmd, &st) == 0 && S_ISREG(st.st_mode) && !access(cmd, X_OK))
	{
		path = ft_strdup(cmd);
		return (path);
	}
	if (stat(cmd, &st) == 0 && S_ISDIR(st.st_mode))
		directory_error(paths, cmd, tree, env);
	return (NULL);
}
