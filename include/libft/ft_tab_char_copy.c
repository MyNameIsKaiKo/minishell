/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_char_copy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 18:09:56 by nredouan          #+#    #+#             */
/*   Updated: 2026/04/10 16:03:35 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**tab_char_cpy(char **args)
{
	char	**result;
	int		size;
	int		i;

	size = ft_tab_size(args);
	result = ft_calloc(size + 1, sizeof(char *));
	i = 0;
	while (i < size)
	{
		result[i] = ft_strdup(args[i]);
		i++;
	}
	result[i] = NULL;
	return (result);
}
