/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 14:54:04 by jleray            #+#    #+#             */
/*   Updated: 2026/02/19 20:05:53 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../include/libft/libft.h"

typedef struct s_node
{
	char				*type;
	char				*data;
	struct s_node		*right;
	struct s_node		*left;
	struct s_node		*head;
}						t_node;

// -- parser Function --
t_node					*make_tree(char *str, t_node **head);
int						exec_tree(t_node *tree);

// -- node Function --
t_node					*nodenew(char *data, char *type, t_node *head);
void					node_add(t_node **node, t_node *new_node, char *side);
void					node_free(t_node *node);

// -- operator_utils Function --
char					*or_and(char *op);
char					*get_last_op(char *str, char *type);

// -- parser_utils Function --
t_node					*create_treenodes(char *str, char *is_op,
							t_node **head);
int						pipe_exec(t_node *tree);

// -- string_utils Function --
char					*ft_strrnstr(const char *big, const char *little,
							size_t loc);
char					*ft_getleft(char *s, char *del);
char					*ft_getright(char *s, char *del);

// minish_pipex Function --
int						pipe_exec(t_node *tree);

// minish_cmd Function --
int						cmd_exec(t_node *tree);

#endif
