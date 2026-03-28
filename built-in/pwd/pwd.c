/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:37:33 by nredouan          #+#    #+#             */
/*   Updated: 2026/03/26 17:46:11 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built_in.h"

void	pwd(t_silent_env *senv)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		printf("%s\n", senv->pwd);
	else
		printf("%s\n", pwd);
	free(pwd);
}
