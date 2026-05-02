/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 11:21:09 by nredouan          #+#    #+#             */
/*   Updated: 2026/04/18 15:05:41 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built_in.h"

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

int	print_export_error(char *arg, int err)
{
	if (err == 0)
	{
		ft_putstr_fd("T&J Shell: export: \'", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd("\': not a valid identifier\n", 2);
	}
	else
		ft_putendl_fd("export: allocation error", 2);
	return (1);
}

/*Get the number of variables in env_var.*/
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

static void	print_export_var(t_env *env_var)
{
	if (!env_var->value)
	{
		if (env_var->name)
			printf("declare -x %s\n", env_var->name);
	}
	else
		printf("declare -x %s=\"%s\"\n", env_var->name, env_var->value);
}

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
	if (!name_copy)
	{
		print_export_error(NULL, 1);
		return ;
	}
	name_dup(name_copy, env_var);
	quick_sort(name_copy, 0, size - 1);
	while (name_copy[i])
	{
		while (ft_strcmp(name_copy[i], env_var->name))
			env_var = env_var->next;
		print_export_var(env_var);
		env_var = head;
		i++;
	}
	free(name_copy);
}
