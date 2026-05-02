/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_do_all_heredoc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:07:22 by jleray            #+#    #+#             */
/*   Updated: 2026/04/24 14:17:53 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include <signal.h>

int	do_all_heredocs(t_ast *tree, t_data data)
{
	if (!tree)
		return (0);
	if (tree->type >= HEREDOC_AST && tree->type <= REDIR_OUT_AST)
	{
		if (!ft_strcmp(tree->args[0], "<<"))
		{
			signal(SIGINT, handler_heredoc);
			signal(SIGQUIT, SIG_IGN);
			tree->heredoc_fd = exec_heredoc(tree->args[1], data,
					tree->do_expand);
			signal(SIGINT, handler);
			signal(SIGQUIT, SIG_IGN);
			if (tree->heredoc_fd == -2)
				return (-2);
		}
	}
	if (do_all_heredocs(tree->left, data) == -2)
		return (-2);
	if (do_all_heredocs(tree->right, data) == -2)
		return (-2);
	return (0);
}
