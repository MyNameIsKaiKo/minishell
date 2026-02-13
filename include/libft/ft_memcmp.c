/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:08:46 by jleray            #+#    #+#             */
/*   Updated: 2025/10/14 13:08:46 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (((t_uchar *)s1)[i] == ((t_uchar *)s2)[i] && i < n - 1)
		i++;
	return (((t_uchar *)s1)[i] - ((t_uchar *)s2)[i]);
}
