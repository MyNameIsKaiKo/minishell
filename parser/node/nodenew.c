/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodenew                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 20:19:58 by jleray            #+#    #+#             */
/*   Updated: 2026/03/26 20:19:58 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ast.c"

static	int	handle_cmd(t_lexer	*checkpoint, t_ast *node)
{
	t_lexer	*tmp;
	int	count;
	int	i;

	tmp = checkpoint;
	count = 0;
	while (tmp && tmp->type == WORD)
	{
		count++;
		tmp = tmp->next;
	}
	node->args = malloc(sizeof(char *) * (count + 1));
	if (!node->args)
		return (0);
	i = 0;
	tmp = checkpoint;
	while (i < count)
	{
		node->args[i] = ft_strdup(tmp->data);
		i++;
		tmp = tmp->next;
	}
	node->args[i] = NULL;
	return (checkpoint->index + count - 1);
}

static int	handle_redit(t_lexer *checkpoint, t_ast *node)
{
	if (!checkpoint->next || checkpoint->next->type != WORD)
		return (0);
	node->args = malloc(sizeof(char *) * 3);
	if (!node->args)
		return (0);
	node->args[0] = ft_strdup(checkpoint->data);
	node->args[1] = ft_strdup(checkpoint->next->data);
	node->args[2] = NULL;
	return (checkpoint->index + 1);
}

t_ast *nodenew(t_lexer **lexhead, t_lexer *checkpoint, t_ast **ast)
{
	t_ast *new_node;

	new_node = malloc(sizeof(t_ast));
	if (!new_node)
		return (NULL);
	new_node->args = NULL;
	new_node->data = NULL;
	new_node->left = NULL;
	new_node->right = NULL;
	get_ast_type(checkpoint, &new_node);
	if (new_node->type == CMD_AST)
		new_node->old_lexindex = handle_cmds(checkpoint, new_node);
	else if (new_node->type == >= HEREDOC_AST && new_node->type <= REDIR_OUT_AST)
		new_node->old_lexindex = handle_redir(checkpoint, new_node);
	else
	{
		new_node->data = ft_strdup(checkpoint->data);
		new_node->old_lexindex = checkpoint->index;
	}
	if (new_node->old_lexindex == 0)
	{
		ast_free(&new_node);
		return(NULL);
	}
	return (new_node);
}
