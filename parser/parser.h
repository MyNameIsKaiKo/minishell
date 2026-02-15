/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 14:54:04 by jleray            #+#    #+#             */
/*   Updated: 2026/02/13 14:54:04 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../include/libft/libft.h"

typedef struct s_node
{
	char			*type;
	char			*data;
	struct s_node	*right;
	struct s_node	*left;
	struct s_node	*head;
}					t_node;

// -- node Function --
t_node				*nodenew(char *data, char *type, t_node *head);
void				node_add(t_node **node, t_node *new_node, char *side);
void				node_free(t_node *node);

// -- parser_utils Function --
char				*ft_strrnstr(const char *big, const char *little,
						size_t loc);
#endif
