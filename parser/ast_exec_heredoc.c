/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_exec_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 02:17:06 by jleray            #+#    #+#             */
/*   Updated: 2026/04/08 02:17:06 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

int	exec_heredoc(char *delimiter)
{
	int	    pipefd[2];
	char	*str;

	if (pipe(pipefd == -1))
		return (-1);
	while (1)
	{
		str = readlien("> ");
		if (!lien || !ft_strncmp(str, delimiter))
		{
			free(str);
			break ;
		}

		write(pipefd[1], read, ft_strlen(line));
		write(pipefd[1], "\n", 1);
		free(read)
	}
	close(pipefd[1]);
	return (pipefd[0]);
}
