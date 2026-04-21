/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_exec_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 02:17:06 by jleray            #+#    #+#             */
/*   Updated: 2026/04/16 20:30:02 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

int	exec_heredoc(char *delimiter)
{
	int		pipefd[2];
	char	*str;
	int		saved_stdin;

	if (pipe(pipefd) == -1)
		return (-1);
	saved_stdin = dup(STDIN_FILENO);
	g_sigint = 0;
	while (1)
	{
		str = readline("heredoc> ");
		if (g_sigint)
		{
			dup2(saved_stdin, STDIN_FILENO);
			close(saved_stdin);
			close(pipefd[1]);
			close(pipefd[0]);
			return (-2);
		}
		if (!str || !ft_strcmp(str, delimiter))
		{
			free(str);
			break ;
		}
		write(pipefd[1], str, ft_strlen(str));
		write(pipefd[1], "\n", 1);
		free(str);
	}
	dup2(saved_stdin, STDIN_FILENO);
	close(saved_stdin);
	close(pipefd[1]);
	return (pipefd[0]);
}
