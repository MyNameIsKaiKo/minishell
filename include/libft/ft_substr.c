/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:39:33 by jleray            #+#    #+#             */
/*   Updated: 2025/10/15 16:39:33 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*output;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
	{
		output = ft_strdup("");
		return (output);
	}
	while (*(((char *)s) + start + i) != 0 && i < len)
		i++;
	output = malloc(sizeof(char) * (i + 1));
	if (!output)
		return (0);
	ft_strlcpy(output, s + start, i + 1);
	return (output);
}
