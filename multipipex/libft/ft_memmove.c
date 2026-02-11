/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:13:30 by jleray            #+#    #+#             */
/*   Updated: 2025/10/13 17:13:30 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!dest && !src)
		return (0);
	if (dest > src && (size_t)(dest - src) < n)
	{
		while (n-- > 0)
		{
			((t_uchar *)dest)[n] = ((t_uchar *)src)[n];
		}
	}
	else
	{
		return (ft_memcpy(dest, src, n));
	}
	return (dest);
}
