/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:18:50 by nredouan          #+#    #+#             */
/*   Updated: 2026/03/02 11:43:42 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*build_prompt(void)
{
	char	*prompt;
	char	*tmp;

	tmp = getcwd(NULL, 256);
	prompt = ft_strjoin("\033[35m<T&J minishell>", tmp);
	free(tmp);
	// if (!prompt)
	// 	ft_exit();//TODO envoyer qqch a tout ce qui doit etre libérer, fermer etc...
	tmp = prompt;
	prompt = ft_strjoin(prompt, "$ \033[0m");
	// if (!prompt)
	// 	ft_exit();//TODO envoyer qqch a tout ce qui doit etre libérer, fermer etc...
	free(tmp);
	return (prompt);
}
