/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 17:35:19 by jleray            #+#    #+#             */
/*   Updated: 2026/03/12 13:57:47 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ast.h"

void	ast_free(t_ast **ast)
{
	t_ast	*node;

	if (!ast)
		return ;
	node = *ast;
	if (!node)
		return ;
	ast_free(&node->left);
	ast_free(&node->right);
	if (node->data)
		free(node->data);
	free(node);
}
