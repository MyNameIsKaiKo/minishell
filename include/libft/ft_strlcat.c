/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:43:23 by jleray            #+#    #+#             */
/*   Updated: 2025/10/13 17:43:23 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dst[i] && i < size)
		i++;
	while (src[j] && ((i + j) < (size - 1)))
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i + j <= (size - 1))
		dst[i + j] = '\0';
	while (src[j])
		j++;
	return (i + j);
}
