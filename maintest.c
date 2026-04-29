/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 16:32:19 by jleray            #+#    #+#             */
/*   Updated: 2026/04/29 15:01:22 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exec_loop(t_data data, t_ast *ast)
{
	signal(SIGINT, handler_exec);
	if (do_all_heredocs(ast, data) == -1)
		((*data.env)->exit_status = 130);
	else
		exec_tree(ast, data);
	signal(SIGINT, handler);
	ast_free(&ast);
}

static bool	loop_exit(t_env **env_var)
{
	if ((*env_var)->is_valid_exit)
	{
		rl_clear_history();
		return (true);
	}
	return (false);
}

static t_ast	*make_make_tree(t_lexer *lex)
{
	t_ast	*head;
	t_ast	*ast;

	head = NULL;
	ast = make_tree(&lex, &head);
	return (ast);
}

static void	main_loop(char **prompt, t_env **env_var)
{
	char	*tmp;
	t_lexer	*lex;
	t_ast	*ast;
	t_data	data;

	while (1)
	{
		g_sigint = 0;
		tmp = readline(*prompt);
		if (loop_init(tmp, 0) == 0)
			break ;
		else if (loop_init(tmp, 1) == 1)
			continue ;
		if (g_sigint == 130)
			(*env_var)->exit_status = 130;
		lex = lex_init(tmp, &data, env_var);
		if (!lex_init_error(lex, env_var))
			continue ;
		ast = make_make_tree(lex);
		if (!ast_error_init(lex, ast, env_var))
			continue ;
		exec_loop(data, ast);
		if (loop_exit(env_var))
			break ;
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
	prompt = build_prompt(env_var->pwd_s);
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
