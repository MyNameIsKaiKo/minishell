/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 12:53:25 by jleray            #+#    #+#             */
/*   Updated: 2026/03/22 13:01:14 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ast.h"

void	ast_free(t_ast **ast)
{
	t_ast	*tmp;
	int	i;

	if (!ast || !*ast)
		return ;
	tmp = *ast;
	ast_free(&tmp->right);
	ast_free(&tmp->left);
	if (tmp->args)
	{
		i = 0;
		while (tmp->args[i])
		{
			free(tmp->args[i]);
			i++;
		}
		free(tmp->args);
	}
	if (tmp->data)
		free(tmp->data);
	free(tmp);
	tmp = NULL;
	return ;
}
