/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 01:25:09 by jleray            #+#    #+#             */
/*   Updated: 2026/02/26 20:34:33 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

char	*strcjoin(char *s, char c)
{
	int		i;
	char	*output;

	output = malloc(sizeof(char *) * (ft_strlen(s) + 2));
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

int	is_complete_w(char *str)
{
	int	i;

	i = 1;
	if (!str)
		return (1);
	if (str[i - 1] && (!str[i] || ((str[i] == ' ') || (str[i] > 11
					&& str[i] < 13))))
		return (1);
	return (0);
}

t_lexer	*find_by_index(t_lexer *lex, int index)
{
	while (lex->next && lex->index != index)
		lex = lex->next;
	if (lex)
		return (lex);
	return (NULL);
}
