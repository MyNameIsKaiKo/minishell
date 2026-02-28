/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_last.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 23:55:52 by jleray            #+#    #+#             */
/*   Updated: 2026/02/20 23:55:52 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_lexer	*lexer_last(t_lexer *lex)
{
	if (!lex)
		return (NULL);
	if (!lex->next)
		return (lex);
	while (lex->next)
		lex = lex->next;
	return (lex);
}
