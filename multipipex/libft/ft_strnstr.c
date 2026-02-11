/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:34:33 by jleray            #+#    #+#             */
/*   Updated: 2025/10/14 13:34:33 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t loc)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_strlen(little);
	if (little[0] == '\0')
		return ((char *)big);
	if (loc == (size_t)-1)
		loc--;
	while (big[i] && i < loc)
	{
		if (i + size < loc + 1 && !(ft_strncmp(big + i, little, size)))
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
