/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexerlst_delone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 15:11:25 by jleray            #+#    #+#             */
/*   Updated: 2026/03/14 15:19:26 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

void	lexer_delone(t_lexer *to_del, t_lexer **head)
{
	t_lexer	*previous;
	t_lexer	*next;

	if (to_del->next && to_del->index == 1)
	{
		next = to_del->next;
		*head = next;
	}
	else
	{
		previous = find_by_index(*head, to_del->index - 1);
		next = to_del->next;
		previous->next = next;
	}
	free(to_del->data);
	free(to_del);
}
