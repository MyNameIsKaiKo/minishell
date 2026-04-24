/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 16:32:19 by jleray            #+#    #+#             */
/*   Updated: 2026/04/24 11:22:53 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	main_loop(char **prompt, t_env **env_var)
{
	char	*tmp;
	t_lexer	*lex;
	t_ast	*ast;
	t_data	data;
	t_ast	*head;

	while (1)
	{
		tmp = readline(*prompt);
		if (!tmp)
		{
			rl_clear_history();
			printf("exit\n");
			break ;
		}
		if (tmp[0] == '\0')
		{
			free(tmp);
			continue ;
		}
		add_history(tmp);
		data.filesfd.fdin = STDIN_FILENO;
		data.filesfd.fdout = STDOUT_FILENO;
		data.env = env_var;
		lex = lexer(tmp);
		free(tmp);
		if (!lex)
		{
			(*env_var)->exit_status = 2;
			ft_putstr_fd("Syntax Error : By lexer in main\n", 2);
			continue ;
		}
		head = NULL;
		ast = make_tree(&lex, &head);
		if (lex && !ast)
		{
			lexer_abs_free(&lex);
			(*env_var)->exit_status = 2;
			ft_putstr_fd("Syntax Error : By ast in main\n", 2);
			continue ;
		}
		lexer_abs_free(&lex);
		signal(SIGINT, handler_exec);
		if (do_all_heredocs(ast) == -1)
			((*data.env)->exit_status = 130);
		else
			exec_tree(ast, data);
		signal(SIGINT, handler);
		ast_free(&ast);
		if ((*env_var)->is_valid_exit)
		{
			rl_clear_history();
			break ;
		}
	}
}

int	main(int ac, char **av, char **envp)
{
	t_env	*env_var;
	int		output;
	char	*prompt;

	(void)ac;
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
	env_var = init_env(envp, av[0]);
	prompt = build_prompt(env_var->s_pwd);
	env_var->prompt = &prompt;
	if (!env_var || !(*env_var->prompt))
	{
		ft_putendl_fd("minishell: internal fatal error", 2);
		free_env(env_var);
		return (1);
	}
	main_loop(env_var->prompt, &env_var);
	output = env_var->exit_status;
	free_env(env_var);
	return (output);
}
