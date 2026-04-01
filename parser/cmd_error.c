/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 12:26:04 by jleray            #+#    #+#             */
/*   Updated: 2026/03/29 12:36:09 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

int	cmd_path_error(char **args, char **paths, char *cmd)
{
	char	*error_msg;
	char	*tmp;
	int		size;

	tmp = ft_strdup("Command not found :");
	error_msg = ft_strjoin(tmp, cmd);
	free(tmp);
	tmp = error_msg;
	error_msg = ft_strjoin(tmp, "\n");
	size = ft_strlen(error_msg);
	write(2, error_msg, size);
	free(tmp);
	free(error_msg);
	free_sarr(paths);
	free_sarr(args);
	return (127);
}

int	cmd_error(char *cmd)
{
	char	*error_msg;
	char	*tmp;
	int		size;

	tmp = ft_strdup("Command not found :");
	error_msg = ft_strjoin(tmp, cmd);
	free(tmp);
	tmp = error_msg;
	error_msg = ft_strjoin(tmp, "\n");
	size = ft_strlen(error_msg);
	write(2, error_msg, size);
	free(tmp);
	free(error_msg);
	return (127);
}
