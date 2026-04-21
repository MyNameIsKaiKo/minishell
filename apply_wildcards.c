/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_wildcards.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 18:16:00 by jleray            #+#    #+#             */
/*   Updated: 2026/04/21 19:59:42 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"
// #include "parser/lexer/lexer.h"
// 
// static int	is_wildcard(char *str, int state)
// {
	// if (ft_strchr(str, '*') && !state)
		// return (1);
	// return (0);
// }
// 
// char	*strtosa(char **sa)
// {
	// char	*output;
	// char	*tmp;
	// int		i;
// 
	// i = 1;
	// tmp = ft_strdup(sa[0]);
	// while (sa[i])
	// {
		// output = ft_strjoinjoin(tmp, " ", sa[i]);
		// free(tmp);
		// tmp = output;
		// i++;
	// }
	// return (output);
// }
// 
// t_lexer	*insert_lexer(t_lexer **head, t_lexer *tmp, char *str)
// {
	// t_lexer	*new;
	// t_lexer	*previous;
	// t_lexer	*new_last;
// 
	// new = lexer(str);
	// new_last = lexer_last(new);
	// lexer_set_next(&new_last, tmp->next);
	// previous = find_by_index(*head, tmp->index - 1);
	// if (previous)
		// lexer_set_next(&previous, new);
	// else
		// *head = new;
	// tmp->next = NULL;
	// lexer_free(&tmp);
	// tmp = NULL;
	// return (new);
// }
// 
// void	apply_wildcard(t_lexer **lex)
// {
	// char	**wildcards_sa;
	// char	*wildcards_compil;
	// t_lexer	*tmp;
// 
	// tmp = *lex;
	// while (tmp)
	// {
		// if (is_wildcard(tmp->data, tmp->is_squoted))
		// {
			// wildcards_sa = wildcards(tmp->data);
			// wildcards_compil = strtosa(wildcards_sa);
			// tmp = insert_lexer(lex, tmp, wildcards_compil);
			// free_sarr(wildcards_sa);
			// free(wildcards_compil);
		// }
		// tmp = tmp->next;
	// }
// }
