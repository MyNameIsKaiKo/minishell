/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_expend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 16:16:05 by jleray            #+#    #+#             */
/*   Updated: 2026/04/19 14:33:33 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	apply_expend(t_lexer **lex, t_data data)
{
	t_lexer	*tmp;
	t_lexer	*trash;
	size_t	len;

	tmp = *lex;
	while (tmp)
	{
		tmp->data = expander(tmp->data, *data.env);
		trash = tmp->next;
		if (!tmp->data[0])
			lexer_delone(&tmp, lex);
		else
		{
			len = ft_strlen(tmp->data);
			tmp->data = supp_quote(tmp->data);
			if (len > ft_strlen(tmp->data))
				tmp->is_squoted = 1;
		}
		tmp = trash;
	}
}
