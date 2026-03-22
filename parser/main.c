/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 13:09:45 by jleray            #+#    #+#             */
/*   Updated: 2026/03/22 14:03:16 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include <stdio.h>

int	main(void)
{
	t_lexer	*lex;
	t_lexer	*head;
	t_ast	*asthead;
	char	*str;
	char	*type;

	str = "(echo oui || echo non) && echo true && Makefile < cat -e | ls -s > out";
	lex = lexer(str);
	asthead = NULL;
	make_tree(&lex, &asthead);
	head = lex;
	if (!lex)
		return (0);
	printf("\n");
	printf("--------------------");
	printf("\n");
	while (lex)
	{
		if (lex->type == WORD)
			type = ft_strdup("WORD");
		if (lex->type == SUBPROCESS)
			type = ft_strdup("SUBPROCESS");
		if (lex->type == REDIR_IN)
			type = ft_strdup("REDIR_IN");
		if (lex->type == REDIR_OUT)
			type = ft_strdup("REDIR_OUT");
		if (lex->type == PONCT)
			type = ft_strdup("HEREDOC");
		if (lex->type == APPEND)
			type = ft_strdup("APPEND");
		if (lex->type == PIPE)
			type = ft_strdup("PIPE");
		if (lex->type == OPERATOR)
			type = ft_strdup("OPERATOR");
		printf("Node : %d\n", lex->index);
		printf("Data : [%s] \n Type : ~~%s~~\n", lex->data, type);
		write(1, "\n", 1);
		lex = lex->next;
		free(type);
	}
	lexer_free(&head);
	return (0);
}
