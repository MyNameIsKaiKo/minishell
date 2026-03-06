/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexerlst_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 00:47:32 by jleray            #+#    #+#             */
/*   Updated: 2026/03/06 17:56:27 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

void	lexer_free(t_lexer **lex)
{
	t_lexer	*tmp;

	while (*lex)
	{
		tmp = *lex;
		if (tmp->data)
			free(tmp->data);
		(*lex) = (*lex)->next;
		free(tmp);
	}
	*lex = NULL;
	return ;
}
