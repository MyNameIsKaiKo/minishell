/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 12:52:58 by jleray            #+#    #+#             */
/*   Updated: 2026/04/15 23:14:11 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	main(void)
{
	t_lexer	*lex;
	t_lexer	*head;
	char	*str;
	char	*str2;

	str = "(echo oui || echo non)&&echo true || <Makefile cat -e|ls -s >out";
	str2 = "ls&&echo";
	lex = lexer(str2);
	head = lex;
	if (!lex)
		return (0);
	printf("\n");
	printf("--------------------");
	printf("\n");
	while (lex)
	{
		printf("Node : %d\n", lex->index);
		printf("Data : [%s] \n Type : %d\n", lex->data, lex->type);
		write(1, "\n", 1);
		lex = lex->next;
	}
	lexer_free(&head);
	return (0);
}
