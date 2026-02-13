/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:05:32 by jleray            #+#    #+#             */
/*   Updated: 2026/02/13 16:08:45 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

void	node_add(t_node *node, t_node *new, char *side)
{
	if (!node || !new)
		return ;
	if (ft_strncmp(side, "left", 4) == 0)
		node->left = new;
	if (ft_strncmp(side, "right", 5) == 0)
		node->right = new;
	return ;
}
