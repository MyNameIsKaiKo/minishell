/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:17:04 by jleray            #+#    #+#             */
/*   Updated: 2025/10/23 17:17:04 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;
	void	*ftemp;

	if (!lst || !f || !del)
		return (NULL);
	new = NULL;
	while (lst)
	{
		ftemp = f(lst->content);
		temp = ft_lstnew(ftemp);
		if (!temp)
		{
			del(ftemp);
			ft_lstclear(&new, del);
			free(temp);
			return (NULL);
		}
		ft_lstadd_back(&new, temp);
		lst = lst->next;
	}
	return (new);
}
