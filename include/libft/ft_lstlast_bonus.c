/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:45:41 by nredouan          #+#    #+#             */
/*   Updated: 2025/10/23 14:22:10 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last_lst;

	if (!lst)
		return (NULL);
	last_lst = lst;
	while (last_lst->next)
		last_lst = last_lst->next;
	return (last_lst);
}
