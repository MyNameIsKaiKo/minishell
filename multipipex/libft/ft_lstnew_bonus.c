/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:40:22 by jleray            #+#    #+#             */
/*   Updated: 2025/10/23 14:40:22 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	int		i;
	t_list	*output;

	i = 0;
	output = malloc(sizeof(t_list));
	if (!output)
		return (0);
	output->content = content;
	output->next = NULL;
	return (output);
}
