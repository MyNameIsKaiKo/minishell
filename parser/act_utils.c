/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 15:30:36 by jleray            #+#    #+#             */
/*   Updated: 2026/03/21 19:40:55 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

static int	is_a_checkpoint(t_token_type lex_type)
{
	if (lex_type >= WORD && lex_type <= SUBPROCESS)
		return (1);
	return (0);
}

t_lexer	*get_last_cpoint(t_lexer *lex)
{
	t_lexer	*output;

	output = NULL;
	while (lex)
	{
		if (is_a_checkpoint(lex->type))
			output = lex;
		lex = lex->next;
	}
	return (output);
}

t_lexer	*getleft(t_lexer *lex, int index)
{
	t_lexer	*tmp;

	tmp = lex;
	if (index - 1 == 1)
	{
		tmp->next = NULL;
		return (tmp);
	}
	else
	{
		while (tmp->index == index - 1)
			tmp = tmp->next;
		tmp->next = NULL;
	}
	return (lex);
}

t_lexer	*getright(t_lexer *lex, int index)
{
	t_lexer	*tmp;

	tmp = find_by_index(lex, index + 1);
	if (tmp)
		return (tmp);
	return (NULL);
}
