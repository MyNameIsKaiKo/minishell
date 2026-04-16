/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexerlst_delone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 15:11:25 by jleray            #+#    #+#             */
/*   Updated: 2026/04/15 22:23:04 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

void	lexer_delone(t_lexer **to_del, t_lexer **head)
{
	t_lexer	*previous;

	if ((*to_del)->index == 1)
	{
		*head = (*to_del)->next;
	}
	else
	{
		previous = find_by_index(*head, (*to_del)->index - 1);
		if (previous)
			lexer_set_next(&previous, (*to_del)->next);
	}
	if ((*to_del)->data)
		free((*to_del)->data);
	free(*to_del);
	(*to_del) = NULL;
	to_del = NULL;
	indexing_lex(head);
}
