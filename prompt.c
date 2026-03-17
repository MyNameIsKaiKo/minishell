/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:18:50 by nredouan          #+#    #+#             */
/*   Updated: 2026/03/17 09:46:39 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*build_prompt(void)
{
	char	*prompt;
	char	*tmp;

	tmp = getcwd(NULL, 256);
	if (!tmp)
		return (NULL);
	prompt = ft_strjoin("\033[35m<T&J minishell>", tmp);
	free(tmp);
	if (!prompt)
		return (NULL);
	tmp = prompt;
	prompt = ft_strjoin(prompt, "$ \033[0m");
	free(tmp);
	if (!prompt)
		return (NULL);
	return (prompt);
}
