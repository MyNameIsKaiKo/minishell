/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexerlst_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 23:26:47 by jleray            #+#    #+#             */
/*   Updated: 2026/04/05 18:55:32 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

void	lexer_add(t_lexer **head, t_lexer *to_add)
{
	t_lexer	*tmp;

	if (!head || !to_add)
		return ;
	tmp = lexer_last(*head);
	if (!tmp)
		(*head) = to_add;
	else
	{
		tmp->next = to_add;
		tmp->to_freen = tmp->next;
	}
	return ;
}
