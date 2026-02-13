/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:18:50 by nredouan          #+#    #+#             */
/*   Updated: 2026/02/13 15:39:02 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "include/libft/libft.h"

void	handler(int signal)
{
	(void)signal;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
}

int	main(void)
{
	char	*str;
	char	*tmp;
	char	cwd[256];

	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
	getcwd(cwd, sizeof(cwd));
	str = ft_strjoin("\033[35m<T&J minishell>", cwd);
	tmp = str;
	str = ft_strjoin(str, "$ \033[0m");
	free (tmp);
	while (1)
	{
		tmp = readline(str);
		add_history(tmp);
		printf("Commande: %s\n", tmp);
		if (tmp == NULL || !ft_strncmp("exit", tmp, 5))
		{
			free(tmp);
			break ;
		}
		free(tmp);
	}
	free(str);
}
