/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:48:12 by nredouan          #+#    #+#             */
/*   Updated: 2026/02/17 12:49:06 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	handler(int signal)
{
	(void)signal;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
}

int	main(void)
{
	char	*prompt;
	char	*tmp;
	t_env	env_var;

	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
	init_env(&env_var);
	prompt = build_prompt(&env_var);
	while (1)
	{
		tmp = readline(prompt);
		add_history(tmp);
		//fais des trucs
		if (tmp == NULL || !ft_strncmp("exit", tmp, 5))
		{
			free(tmp);
			break ;
		}
		if (!ft_strncmp("cd", tmp, 2))
		{
			free(prompt);
			if (ft_strlen(tmp) == 2)
				prompt = cd(NULL, &env_var);
			else
				prompt = cd(tmp, &env_var);
		}
		free(tmp);
	}
	clear_history();
	free_env(&env_var);
	free(prompt);
}
