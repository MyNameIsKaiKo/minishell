/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 06:38:16 by jleray            #+#    #+#             */
/*   Updated: 2026/02/15 06:38:16 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*ft_strrnstr(const char *big, const char *little, size_t loc)
{
	size_t	l_len;
	size_t	b_len;

	l_len = ft_strlen(little);
	b_len = ft_strlen(big);
	if (little[0] == '\0')
		return ((char *)big);
	if (l_len > loc)
		return (NULL);
	if (b_len > loc)
		b_len = loc;
	while (b_len >= l_len)
	{
		if (!(ft_strncmp(big + b_len * l_len, little, l_len)))
			return ((char *)big + b_len - l_len);
		b_len--;
	}
	return (NULL);
}
