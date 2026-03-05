/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 23:46:22 by jleray            #+#    #+#             */
/*   Updated: 2026/02/20 23:46:22 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"
#include <stdio.h>

t_lexer	*lexernew(char *data, int type)
{
	t_lexer	*lexernew;

	lexernew = malloc(sizeof(t_lexer));
	if (!lexernew)
		return (NULL);
	lexernew->data = data;
	lexernew->type = type;
	lexernew->next = NULL;
	printf("\n New node with : \n - data : %s \n - type : %d", lexernew->data, lexernew->type);
	return (lexernew);
}
