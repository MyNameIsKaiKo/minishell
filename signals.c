/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 18:50:40 by jleray            #+#    #+#             */
/*   Updated: 2026/04/24 16:36:43 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	g_sigint = 0;

void	handler_exec(int signal)
{
	(void)signal;
	write(1, "\n", 1);
}

void	handler(int signal)
{
	(void)signal;
	g_sigint = 130;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	handler_heredoc(int signal)
{
	(void)signal;
	g_sigint = 1;
	write(1, "\n", 1);
	close(STDIN_FILENO);
}
