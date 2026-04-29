/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_exec_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 02:17:06 by jleray            #+#    #+#             */
/*   Updated: 2026/04/24 14:21:45 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

static int	sig_int_heredoc(int pipefd[2], int saved_stdin)
{
	if (g_sigint)
	{
		dup2(saved_stdin, STDIN_FILENO);
		close(saved_stdin);
		close(pipefd[1]);
		close(pipefd[0]);
		return (-2);
	}
	return (0);
}

static void	init_heredoc_var(int *saved_stdin)
{
	*saved_stdin = dup(STDIN_FILENO);
	g_sigint = 0;
}

static void	finish_heredoc(int pipefd[2], int saved_stdin)
{
	dup2(saved_stdin, STDIN_FILENO);
	close(saved_stdin);
	close(pipefd[1]);
}

static void	end_heredoc_loop(char *str, int pipefd[2], int do_expand,
		t_data data)
{
	if (do_expand)
		str = expander(str, (*data.env));
	write(pipefd[1], str, ft_strlen(str));
	write(pipefd[1], "\n", 1);
	free(str);
}

int	exec_heredoc(char *delimiter, t_data data, int do_expand)
{
	int		pipefd[2];
	char	*str;
	int		saved_stdin;

	if (pipe(pipefd) == -1)
		return (-1);
	delimiter = supp_quote(delimiter);
	init_heredoc_var(&saved_stdin);
	while (1)
	{
		str = readline("heredoc> ");
		if (sig_int_heredoc(pipefd, saved_stdin) == -2)
			return (-2);
		if (!str || !ft_strcmp(str, delimiter))
		{
			free(str);
			break ;
		}
		end_heredoc_loop(str, pipefd, do_expand, data);
	}
	finish_heredoc(pipefd, saved_stdin);
	return (pipefd[0]);
}
