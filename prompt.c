/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:18:50 by nredouan          #+#    #+#             */
/*   Updated: 2026/02/19 12:18:35 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*build_prompt(t_env *env_var)
{
	char	*prompt;
	char	*tmp;

	prompt = ft_strjoin("\033[35m<T&J minishell>", env_var->pwd);
	// if (!prompt)
	// 	ft_exit();//TODO envoyer qqch a tout ce qui doit etre libérer, fermer etc...
	tmp = prompt;
	prompt = ft_strjoin(prompt, "$ \033[0m");
	// if (!prompt)
	// 	ft_exit();//TODO envoyer qqch a tout ce qui doit etre libérer, fermer etc...
	free(tmp);
	return (prompt);
}

void	change_prompt(t_env *env_var)
{
	char	cwd[256];

	getcwd(cwd, sizeof(cwd));
	free(env_var->old_pwd);
	env_var->old_pwd = ft_strdup(env_var->pwd);
	// if (!env_var->old_pwd)
	// 	ft_exit();//TODO envoyer qqch a tout ce qui doit etre libérer, fermer etc...
	free(env_var->pwd);
	env_var->pwd = ft_strdup(cwd);
	// if (!env_var->pwd)
	// 	ft_exit();//TODO envoyer qqch a tout ce qui doit etre libérer, fermer etc...
}
