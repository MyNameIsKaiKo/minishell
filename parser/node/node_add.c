/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:05:32 by jleray            #+#    #+#             */
/*   Updated: 2026/03/12 14:48:03 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ast.h"

void	node_add(t_ast **node, t_ast *new_node, t_side side)
{
	if (!node || !new_node)
		return ;
	if (side == LEFT)
		(*node)->left = new_node;
	if (side == RIGHT)
		(*node)->right = new_node;
	return ;
}
