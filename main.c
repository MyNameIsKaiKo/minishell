/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:48:12 by nredouan          #+#    #+#             */
/*   Updated: 2026/03/04 18:23:39 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char    **find_directpath(char *env)
{
    char    **paths;
    char    *path;
    int        i;

    if (!ft_strncmp(env, "PATH=", 5))
    {
        paths = ft_split(env + 5, ':');
        if (!paths)
            return (NULL);
        i = 0;
        while (paths[i++])
        {
            path = paths[i - 1];
            paths[i - 1] = ft_strjoin(path, "/");
            if (!paths[i - 1])
            {
                write (1, "ERROR\n", 6);
                return (NULL);
            }
            free(path);
        }
    }
    else
        return (NULL);
    return (paths);
}

static char    **find_path(char **env)
{
    int        i;
    char    **paths;

    i = 0;
    while (env[i] && ft_strncmp(env[i], "PATH=", 5))
        i++;
    if (!env[i])
        return (NULL);
    paths = find_directpath(env[i]);
    if (!paths)
        return (NULL);
    return (paths);
}

static char    *find_cmdpath(char **paths, char *cmd)
{
    int        i;
    char    *path;

    i = 0;
    if ((cmd[0] == '/' || ft_strncmp(cmd, "./", 2) == 0) && access(cmd,
            X_OK) == 0)
    {
        path = ft_strdup(cmd);
        if (!path)
            return (NULL);
        return (path);
    }
    while (paths[i])
    {
        path = ft_strjoin(paths[i], cmd);
        if (!path)
            return (NULL);
        if (access(path, X_OK) == 0)
            return (path);
        free(path);
        i++;
    }
    return (NULL);
}

int    exec(char *cmd, char **env)
{
    char    **paths;
    char    **args;
    char    *path;

    paths = find_path(env);
    if (!paths)
        write (1, "ERROR\n", 6);
    args = ft_split(cmd, ' ');
    if (!args)
    {
        write(2, "Command not found\n", 18);
        write (1, "ERROR\n", 6);
        exit(1);//TODO changer exit pour fonction d'exit
    }
    path = find_cmdpath(paths, args[0]);
    if (!path)
        write (1, "ERROR\n", 6);
    if (execve(path, args, env) == -1)
        write (1, "ERROR\n", 6);
    return (0);
}

static void	handler(int signal)
{
	(void)signal;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
}

void	clear(char **envp)
{
	char *arg[] =  {"clear", (char *)0};
	execve("/usr/bin/clear", arg, envp);//TODO protect
	//TODO contruire le path pour clear
}

int	main(int argc, char **argv, char **envp)
{
	char	*prompt;
	char	*tmp;
	t_env	*env_var;
	t_env	*finder;
	pid_t	child;

	(void)argc;
	(void)argv;
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
	env_var = init_env(envp);
	prompt = build_prompt();
	while (1)
	{
		finder = env_var;
		tmp = readline(prompt);
		add_history(tmp);
		//fais des trucs
		if (tmp == NULL || !ft_strncmp("exit", tmp, 4))
		{
			free(tmp);
			break ;
		}
		if (!ft_strncmp("cd", tmp, 2))
		{
			free(prompt);
			if (ft_strlen(tmp) == 2)
				prompt = cd(NULL, env_var);
			else
				prompt = cd(tmp + 2, env_var);
		}
		else if (!ft_strncmp("pwd", tmp, 3))
			pwd();
		else if (!ft_strncmp("clear", tmp, 5))
		{
			child = fork();//TODO protect
			if (child == 0)
				clear(envp);
			waitpid(child, NULL, 0);//TODO protect
		}
		else if (!ft_strncmp("echo -n", tmp, 7))
			ft_putstr_fd(tmp + 7, 1);
		else if (!ft_strncmp("echo", tmp, 4))
			ft_putendl_fd(tmp + 4, 1);
		else if (!ft_strncmp("unset", tmp, 5))
			env_var = unset(tmp + 6, env_var);
		free(tmp);
	}
	rl_clear_history();
	free_env(env_var);
	free(prompt);
}
