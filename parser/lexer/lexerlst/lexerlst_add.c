/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 23:26:47 by jleray            #+#    #+#             */
/*   Updated: 2026/02/20 23:26:47 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	lexer_add(t_lexer *head, t_lexer *to_add)
{
	if (!head)
	{
		head = to_add;
		return ;
	}
	if (!head->next)
	{
		head->next = to_add;
		return ;
	}
	head = lexer_last(head);
	head->next = to_add;
	return ;
}
