/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_egde.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 21:51:13 by jleray            #+#    #+#             */
/*   Updated: 2026/04/21 21:57:42 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	syntax_edge_case(t_lexer **lex)
{
	t_lexer	*tmp;

	tmp = *lex;
	while (tmp->next)
	{
		if (ft_strcmp(tmp->data, "$>"))
		{
			lexer_abs_free(lex);
			return (-1);
		}
	}
	return (0);
}
