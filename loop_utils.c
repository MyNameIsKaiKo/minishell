/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:56:50 by nredouan          #+#    #+#             */
/*   Updated: 2026/04/29 14:59:20 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexer	*lex_init(char *tmp, t_data *data, t_env **env_var)
{
	t_lexer	*lex;
	
	add_history(tmp);
	(*data).filesfd.fdin = STDIN_FILENO;
	(*data).filesfd.fdout = STDOUT_FILENO;
	(*data).env = env_var;
	lex = lexer(tmp);
	free(tmp);
	return (lex);
}

int	loop_init(char *tmp, int type)
{
	if (!tmp && type == 0)
	{
		rl_clear_history();
		printf("exit\n");
		return (0);
	}
	if (tmp[0] == '\0' && type == 1)
	{
		free(tmp);
		tmp = NULL;
		return (1);
	}
	return (2);
}

bool	lex_init_error(t_lexer *lex, t_env **env_var)
{
	if (!lex)
	{
		(*env_var)->exit_status = 2;
		ft_putstr_fd("Syntax Error : By lexer in main\n", 2);
		return (false);
	}
	return (true);
}

bool	ast_error_init(t_lexer *lex, t_ast *ast, t_env **env_var)
{
	if (lex && !ast)
	{
		lexer_abs_free(&lex);
		(*env_var)->exit_status = 2;
		ft_putstr_fd("Syntax Error : By ast in main\n", 2);
		return (false);
	}
	lexer_abs_free(&lex);
	return (true);
}
