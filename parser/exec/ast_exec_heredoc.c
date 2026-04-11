/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_exec_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 02:17:06 by jleray            #+#    #+#             */
/*   Updated: 2026/04/11 17:22:29 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

int	exec_heredoc(char *delimiter, t_data *data)
{
	int		pipefd[2];
	char	*str;

	if (pipe(pipefd) == -1)
		return (-1);
	while (1)
	{
		str = readline("> ");
		if (!str || !ft_strcmp(str, delimiter))
		{
			free(str);
			break ;
		}
		write(pipefd[1], str, ft_strlen(str));
		write(pipefd[1], "\n", 1);
		free(str);
	}
	close(pipefd[1]);
	data->filesfd.fdin = pipefd[0];
	return (pipefd[0]);
}
