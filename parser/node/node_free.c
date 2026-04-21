/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 12:53:25 by jleray            #+#    #+#             */
/*   Updated: 2026/04/21 18:55:42 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ast.h"

void	ast_free(t_ast **ast)
{
	t_ast	*tmp;
	int		i;

	if (!ast || !*ast)
		return ;
	tmp = *ast;
	ast_free(&tmp->right);
	ast_free(&tmp->left);
	if (tmp->quote_states)
		free(tmp->quote_states);
	if (tmp->args)
	{
		i = -1;
		while (tmp->args[++i])
			free(tmp->args[i]);
		free(tmp->args);
	}
	if (tmp->data)
		free(tmp->data);
	if (tmp->heredoc_fd > 2)
		close(tmp->heredoc_fd);
	free(tmp);
	tmp = NULL;
	return ;
}
