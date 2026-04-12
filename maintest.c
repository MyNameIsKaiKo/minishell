/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 16:32:19 by jleray            #+#    #+#             */
/*   Updated: 2026/04/09 12:04:16 by jleray           ###   ########.fr       */
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

void	main_loop(char **prompt, t_env **env_var)
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
			free(*prompt);
			break ;
		}
		data.filesfd.fdin = STDIN_FILENO;
		data.filesfd.fdout = STDOUT_FILENO;
		data.env = env_var;
		lex = lexer(tmp);
		free(tmp);
		apply_expend(&lex, data);
		apply_wildcard(&lex);
		ast = make_tree(&lex);
		lexer_abs_free(&lex);
		exec_tree(ast, data);
		ast_free(&ast);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_env			*env_var;
	char			*prompt;

	(void)ac;
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
	env_var = init_env(envp, av[0]);
	prompt = build_prompt(env_var->s_pwd);
	if (!prompt || !env_var)
	{
		ft_putendl_fd("minishell: internal fatal error", 2);
		free_env(env_var);
		free(prompt);
		return (1);
	}
	main_loop(&prompt, &env_var);
	return (0);
}
