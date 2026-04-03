/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 16:32:19 by jleray            #+#    #+#             */
/*   Updated: 2026/04/03 16:58:51 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handler(int signal)
{
	(void)signal;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	main_loop(char **prompt, t_env **env_var, t_silent_env *senv)
{
	char	*tmp;
	t_lexer	*lex;
	t_ast	*ast;
	t_data	data;

	while (1)
	{
		tmp = readline(*prompt);
		if (tmp && tmp[0])
			add_history(tmp);
		if (!ft_strcmp(tmp, "exit"))
		{
			free(tmp);
			rl_clear_history();
			free_env(*env_var);
			free(senv->pwd);
			free(*prompt);
			break ;
		}
		lex = lexer(tmp);
		free(tmp);
		ast = make_tree(&lex);
		lexer_free(&lex);
		data.filesfd.fdin = STDIN_FILENO;
		data.filesfd.fdout = STDOUT_FILENO;
		exec_tree(ast, data);
		rl_clear_history();
		free_env(*env_var);
		free(senv->pwd);
		free(*prompt);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_env			*env_var;
	char			*prompt;
	t_silent_env	senv;

	(void)ac;
	(void)av;
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
	env_var = init_env(envp);
	senv.pwd = getcwd(NULL, 0);
	prompt = build_prompt(&senv);
	if (!prompt || !env_var)
	{
		ft_putendl_fd("minishell: internal fatal error", 2);
		free_env(env_var);
		free(senv.pwd);
		free(prompt);
		return (1);
	}
	main_loop(&prompt, &env_var, &senv);
	return (0);
}
