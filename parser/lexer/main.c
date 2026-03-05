/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 12:52:58 by jleray            #+#    #+#             */
/*   Updated: 2026/03/05 12:52:58 by jleray           ###   ########.fr       */
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
	char	*str;

	str = "Je suis une phrase (simple) \"et j'aime bien la simplicite\"";
	lex = lexer(str);
	if (!lex)
		return (0);
	printf("\n");
	printf("--------------------");
	printf("\n");
	while (lex)
	{
		printf("Node : %d\n", lex->index);
		printf("Data : %s && Type : %d\n", lex->data, lex->type);
		write(1, "\n", 1);
		lex = lex->next;
	}
	return (0);
}
