/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 01:25:09 by jleray            #+#    #+#             */
/*   Updated: 2026/02/21 01:25:09 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

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
