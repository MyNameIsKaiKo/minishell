/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:34:43 by jleray            #+#    #+#             */
/*   Updated: 2025/10/15 17:34:43 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	totallen;
	char	*output;

	totallen = ft_strlen(s1) + ft_strlen(s2);
	output = ft_calloc(sizeof(char), (totallen + 1));
	if (output)
	{
		ft_strlcat(output, s1, ft_strlen(s1) + 1);
		ft_strlcat(output, s2, totallen + 1);
	}
	return (output);
}
