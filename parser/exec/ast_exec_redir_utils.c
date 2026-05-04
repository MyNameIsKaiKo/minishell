/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_exec_redir_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:44:51 by nredouan          #+#    #+#             */
/*   Updated: 2026/05/04 15:45:17 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

int	fix_heredoc_command_after(t_ast **trees, t_data *data)
{
	t_ast	*tree;
	int		status;

	tree = *trees;
	status = 0;
	if (tree->right && tree->right->type >= HEREDOC_AST
		&& tree->right->type <= REDIR_OUT_AST)
	{
		status = do_all_redirs(tree->right, data);
		if (status != 0)
			return (status);
	}
	return (0);
}
