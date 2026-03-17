/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 18:13:26 by nredouan          #+#    #+#             */
/*   Updated: 2026/02/11 14:37:00 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*array;
	size_t	i;
	size_t	total;

	i = 0;
	total = nmemb * size;
	if (size != 0 && nmemb != 0 && (nmemb * size) / size != nmemb)
		return (NULL);
	array = malloc((nmemb * size));
	if (!array)
		return (NULL);
	while (i < total)
	{
		array[i] = '\0';
		i++;
	}
	return (array);
}
