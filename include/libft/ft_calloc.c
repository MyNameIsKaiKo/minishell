/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:54:42 by jleray            #+#    #+#             */
/*   Updated: 2025/10/14 14:54:42 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*alloc;

	if (nmemb == 0 || size == 0)
	{
		alloc = malloc(0);
		if (!alloc)
			return (0);
		return (alloc);
	}
	if (nmemb > (size_t)-1 / size)
		return (0);
	alloc = malloc(nmemb * size);
	if (!alloc)
		return (0);
	return (ft_memset(alloc, 0, (nmemb * size)));
}
