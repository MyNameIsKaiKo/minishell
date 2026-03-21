/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 19:26:04 by jleray            #+#    #+#             */
/*   Updated: 2026/03/21 19:29:08 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ast.h"

void	node_add(t_ast **ast, t_ast *new_node, t_side side)
{
	if (side == LEFT)
		(*ast)->left = new_node;
	if (side == RIGHT)
		(*ast)->right = new_node;
}
