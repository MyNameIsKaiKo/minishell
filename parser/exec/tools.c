/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 21:12:30 by jleray            #+#    #+#             */
/*   Updated: 2026/04/19 21:42:07 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

int	arr_len(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

char	**ft_arr_dup(char **ar)
{
	char	**output;
	int		i;

	i = 0;
	output = malloc(sizeof(char *) * (arr_len(ar) + 1));
	if (!output)
		return (NULL);
	while (ar[i])
	{
		output[i] = ar[i];
		i++;
	}
	output[i] = NULL;
	return (output);
}

char	**ft_arr_join(char **arr1, char **arr2)
{
	int		i;
	int		j;
	char	**result;

	i = 0;
	j = 0;
	if (!arr2)
		return (NULL);
	if (!arr1)
	{
		result = ft_arr_dup(arr2);
		free(arr2);
		return (result);
	}
	result = malloc(sizeof(char *) * (arr_len(arr1) + arr_len(arr2) + 1));
	if (!result)
		return (NULL);
	while (arr1[i++])
		result[i - 1] = arr1[i - 1];
	while (arr2[j++])
		result[i + j - 1] = arr2[j - 1];
	result[i + j] = NULL;
	free(arr1);
	free(arr2);
	return (result);
}
