/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexerlst_trim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 13:44:44 by jleray            #+#    #+#             */
/*   Updated: 2026/03/22 14:14:16 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

void	lexerlst_trim(t_lexer **lex)
{
	t_lexer	*tmp;
	char	*str;

	tmp = *lex;
	while (tmp)
	{
		str = ft_strtrim(tmp->data, " ");
		free(tmp->data);
		tmp->data = str;
		tmp = tmp->next;
	}
	indexing_lex(lex);
}
