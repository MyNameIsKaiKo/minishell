/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:49:33 by jleray            #+#    #+#             */
/*   Updated: 2025/10/14 15:49:33 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*destination;

	len = ft_strlen(s);
	destination = malloc(sizeof(char) * (len + 1));
	if (!destination)
		return (0);
	ft_memcpy(destination, s, len);
	destination[len] = '\0';
	return (destination);
}
