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

	if (!ast)
		return ;
	tmp = *ast;
	if (!tmp)
		return ;
	ast_free(&tmp->right);
	ast_free(&tmp->left);
	free(tmp->data);
	free(tmp);
	tmp = NULL;
	return ;
}
