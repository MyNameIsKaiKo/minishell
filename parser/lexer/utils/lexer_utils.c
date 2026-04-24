/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 01:25:09 by jleray            #+#    #+#             */
/*   Updated: 2026/04/21 21:50:30 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

char	*strcjoin(char *s, char c)
{
	int		i;
	char	*output;

	output = malloc(sizeof(char) * (ft_strlen(s) + 2));
	if (!output)
		return (NULL);
	i = 0;
	while (s[i])
	{
		output[i] = s[i];
		i++;
	}
	output[i] = c;
	output[i + 1] = '\0';
	free(s);
	return (output);
}

int	is_complete_w(char *str, char *og)
{
	if (*str && (*og == ' ' || *og == '\t' || *og == '\n'))
		return (1);
	if (*og == '(' || *og == ')' || *og == '\'' || *og == '\"' || *og == '\0')
		return (1);
	if (*str == '|' && *og == '|')
		return (0);
	if (*str == '&' && *og == '&')
		return (0);
	if (*og == '&')
		return (1);
	if (og[0] == '|')
		return (1);
	return (0);
}

t_lexer	*find_by_index(t_lexer *lex, int index)
{
	if (index <= 0 || !lex)
		return (NULL);
	while (lex && lex->index != index)
		lex = lex->next;
	if (lex)
		return (lex);
	return (NULL);
}
