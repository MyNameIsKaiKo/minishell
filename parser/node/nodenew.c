/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodenew                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 20:19:58 by jleray            #+#    #+#             */
/*   Updated: 2026/03/26 20:19:58 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ast.c"

t_ast *nodenew(t_lexer **lexhead, t_lexer *checkpoint, t_ast **ast)
{
	t_ast *new_node;

	new_node = malloc(sizeof(t_ast));
	if (!new_node)
		return (NULL);
	new_node->args = NULL;
	new_node->data = NULL;
	new_node->left = NULL;
	new_node->right = NULL;
	get_ast_type(checkpoint, &new_node);
	if (!*ast)
		*ast = new_node;
	new_node->head = *ast;
	return (new_node);
}
