/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 13:09:45 by jleray            #+#    #+#             */
/*   Updated: 2026/03/28 13:30:15 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include <stdio.h>

void	print_tree(t_ast *tree)
{
	if (!tree)
		return ;
	print_tree(tree->left);
	if (tree->data)
		printf("Data : %s \n", tree->data);
	if (tree->args)
	{
		int i = 0;

		printf("Data :");
		while (tree->args[i++])
			printf(" %s ", tree->args[i-1]);
		printf("\n");
	}
	print_tree(tree->right);
}

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
	printf("--------------------");
	printf("\n");
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
	print_tree(asthead);
	lexer_free(&head);
	return (0);
}
