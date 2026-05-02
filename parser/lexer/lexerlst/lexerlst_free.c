/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexerlst_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 00:47:32 by jleray            #+#    #+#             */
/*   Updated: 2026/04/09 11:54:54 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

void	lexer_set_next(t_lexer **lex, t_lexer *next)
{
	(*lex)->next = next;
	(*lex)->to_freen = next;
}

void	lexer_abs_free(t_lexer **lex)
{
	t_lexer	*tmp;

	while (*lex)
	{
		tmp = *lex;
		if (tmp->data)
			free(tmp->data);
		(*lex) = (*lex)->to_freen;
		free(tmp);
	}
	*lex = NULL;
	return ;
}

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
