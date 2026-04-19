/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_maintest.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 13:09:45 by jleray            #+#    #+#             */
/*   Updated: 2026/04/03 16:27:31 by jleray           ###   ########.fr       */
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
	// char	*type;

	str = "(echo oui || echo non) && echo true && < Makefile cat -e | ls -s > out";
	lex = lexer(str);
	asthead = NULL;
	asthead = make_tree(&lex);
	head = lex;
	if (!lex)
		return (0);
	printf("\n");
	printf("TEST LEAK");
	printf("\n");
	lexer_free(&head);
	ast_free(&asthead);
	return (0);
}

// while (lex)
	// {
		// if (lex->type == WORD)
			// type = ft_strdup("WORD");
		// if (lex->type == SUBPROCESS)
			// type = ft_strdup("SUBPROCESS");
		// if (lex->type == REDIR_IN)
			// type = ft_strdup("REDIR_IN");
		// if (lex->type == REDIR_OUT)
			// type = ft_strdup("REDIR_OUT");
		// if (lex->type == PONCT)
			// type = ft_strdup("HEREDOC");
		// if (lex->type == APPEND)
			// type = ft_strdup("APPEND");
		// if (lex->type == PIPE)
			// type = ft_strdup("PIPE");
		// if (lex->type == OPERATOR)
			// type = ft_strdup("OPERATOR");
		// printf("Node : %d\n", lex->index);
		// printf("Data : [%s] \n Type : ~~%s~~\n", lex->data, type);
		// write(1, "\n", 1);
		// lex = lex->next;
		// free(type);
	// }
	// print_tree(asthead);
