/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_string_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:34:51 by nredouan          #+#    #+#             */
/*   Updated: 2026/03/10 17:49:03 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static void	ft_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	partition(char **name_copy, int start, int end)
{
	char	*pivot;
	int		i;
	int		j;

	pivot = name_copy[start];
	i = start - 1;
	j = end + 1;
	while (1)
	{
		i++;
		while (ft_strcmp(name_copy[i], pivot) < 0)
			i++;
		j--;
		while (j > 0 && ft_strcmp(name_copy[j], pivot) > 0)
			j--;
		if (i >= j)
			return (j);
		ft_swap(&name_copy[i], &name_copy[j]);
	}
}

void	quick_sort(char **name_copy, int start, int end)
{
	int	p_index;

	if (start < end)
	{
		p_index = partition(name_copy, start, end);
		quick_sort(name_copy, start, p_index);
		quick_sort(name_copy, p_index + 1, end);
	}
}
