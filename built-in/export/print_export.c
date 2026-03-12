/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 11:21:09 by nredouan          #+#    #+#             */
/*   Updated: 2026/03/12 16:41:11 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

/*Copy the name of the variables for sorting them before the print.*/
static void	name_dup(char **name_copy, t_env *env_var)
{
	int		i;

	i = 0;
	while (env_var)
	{
		name_copy[i] = env_var->name;
		env_var = env_var->next;
		i++;
	}
}

/*Print an error message in case of non-alphabetical
characters in the name of the variable we want to add.*/
void	print_export_error(char *arg)
{
	ft_putstr_fd("export: \'", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("\': not a valid identifier\n", 2);
}

//Get the number of variables in env_var.
int	ft_lst_env_size(t_env *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		i++;
		lst = (*lst).next;
	}
	return (i);
}

/*Print the list of all variables set in env_var in alphabetical order.*/
void	print_export(t_env *env_var)
{
	char	**name_copy;
	t_env	*head;
	size_t	size;
	int		i;

	i = 0;
	head = env_var;
	size = ft_lst_env_size(env_var);
	name_copy = ft_calloc(size + 1, sizeof(char *));
	name_dup(name_copy, env_var);
	quick_sort(name_copy, 0, size - 1);
	while (name_copy[i])
	{
		while (ft_strcmp(name_copy[i], env_var->name))
			env_var = env_var->next;
		printf("declare -x ");
		if (!env_var->value)
			printf("%s\n", env_var->name);
		else
			printf("%s=\"%s\"\n", env_var->name, env_var->value);
		env_var = head;
		i++;
	}
	free(name_copy);
}
