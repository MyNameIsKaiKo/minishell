/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:58:20 by jleray            #+#    #+#             */
/*   Updated: 2026/02/17 18:58:20 by jleray           ###   ########.fr       */
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

char	*ft_getleft(char *s, char *del)
{
	const char	*right = ft_strrnstr(s, del, ft_strlen(s));
	char		*output;

	output = ft_substr(s, 0, ft_strlen(s) - ft_strlen(right));
	return (output);
}

char	*ft_getright(char *s, char *del)
{
	const char	*right = ft_strrnstr(s, del, ft_strlen(s));
	char		*output;

	output = ft_substr(right, ft_strlen(s) - ft_strlen(right) + 2,
			ft_strlen(right) - 2);
	return (output);
}
