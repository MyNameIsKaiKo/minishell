/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_expend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 16:16:05 by jleray            #+#    #+#             */
/*   Updated: 2026/04/16 23:03:16 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	apply_expend(t_lexer **lex, t_data data)
{
	t_lexer	*tmp;
	t_lexer	*trash;

	tmp = *lex;
	while (tmp)
	{
		tmp->data = expander(tmp->data, *data.env);
		trash = tmp->next;
		if (!tmp->data[0])
			lexer_delone(&tmp, lex);
		else
			tmp->data = supp_quote(tmp->data);
		tmp = trash;
	}
}
