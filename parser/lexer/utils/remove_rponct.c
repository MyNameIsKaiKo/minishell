/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_rponct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 15:36:39 by jleray            #+#    #+#             */
/*   Updated: 2026/04/15 22:13:51 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

void	remove_remaining_type(t_lexer **lex, t_token_type type)
{
	t_lexer	*search;
	t_lexer	*tmp;

	indexing_lex(lex);
	search = *lex;
	while (search)
	{
		if (search->type == type)
		{
			tmp = search;
			search = search->next;
			lexer_delone(&tmp, lex);
		}
		else
			search = search->next;
	}
}
