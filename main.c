/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:48:12 by nredouan          #+#    #+#             */
/*   Updated: 2026/04/07 15:40:31 by nredouan         ###   ########.fr       */
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
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	clear(char **envp)
{
	char *arg[] =  {"clear", (char *)0};
	execve("/usr/bin/clear", arg, envp);//TODO protect
	//TODO contruire le path pour clear (et toutes les commandes concernées)
}

int	main(int argc, char **argv, char **envp)
{
	char			*prompt;
	char			*tmp;
	char			**tmp2;
	t_env			*env_var;
	pid_t			child;

	(void)argc;
	(void)argv;
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
	env_var = init_env(envp);
	env_var->exec = ft_strdup(argv[0]);
	prompt = build_prompt(env_var->s_pwd);
	// printf("Noeud 1 :\n");
	// printf("Env name :%s\n", env_var->name);
	// printf("Env value :%s\n", env_var->value);
	// printf("Env pwd :%s\n", env_var->s_pwd);
	// printf("Env previous :%p\n", env_var->prev);
	// printf("Env next :%p\n", env_var->next);
	// printf("-------------------------------\n");
	// if (env_var->next)
	// {
	// 	printf("Noeud 2 :\n");
	// 	printf("Env name :%s\n", env_var->next->name);
	// 	printf("Env value :%s\n", env_var->next->value);
	// 	printf("Env pwd :%s\n", env_var->next->s_pwd);
	// 	printf("Env previous :%p\n", env_var->next->prev);
	// 	printf("Env next :%p\n", env_var->next->next);
	// 	printf("-------------------------------\n");
	// }
	if (!prompt || !env_var)
	{
		ft_putendl_fd("minishell: internal fatal error", 2);
		free_env(env_var);
		free(prompt);
		return (1);	
	}
	// int fd = open("Tom_and_jerry.txt", O_RDONLY);
	// char *gnl = get_next_line(fd);
	// int t = 0;
	// while (gnl)
	// {
	// 	printf("%s", gnl);
	// 	if (t < 7)
	// 		usleep(15000);
	// 	else if (t < 15)
	// 	{
	// 		usleep(100000);
	// 		t = 0;
	// 	}
	// 	free(gnl);
	// 	gnl = get_next_line(fd);
	// 	t++;
	// }
	// close(fd);
	while (1)
	{
		tmp = readline(prompt);
		if (!tmp)
			break ;
		if (tmp[0])
			add_history(tmp);
		tmp2 = ft_split(tmp, ' ');
		// if (!ft_strcmp(tmp2[0], "export"))
		// {
		// 	free_str(tmp2);
		// 	tmp2 = malloc(1000);
		// 	tmp2[0] = ft_strdup("export");
		// 	tmp2[1] = ft_strdup("ARG=\"coucou papa                    X\"");
		// 	tmp2[2] = NULL;
		// }
		free(tmp);
		if (!tmp2)
		{
			ft_putendl_fd("minishell: internal fatal error", 2);
			continue ;
		}
		for (int i = 0; tmp2[i]; i++)
			tmp2[i] = expander(tmp2[i], env_var);
		if (tmp2[0] && !ft_strcmp("exit", tmp2[0]))
		{
			free_str(tmp2);
			break ;
		}
		if (!tmp2[0])
		{
			free_str(tmp2);
			continue ;
		}
		if (!ft_strcmp("cd", tmp2[0]))
		{
			free(prompt);
			prompt = cd(&tmp2[1], env_var);
		}
		else if (!ft_strcmp("pwd", tmp2[0]))
			pwd(NULL, env_var);
		else if (!ft_strcmp("clear", tmp2[0]))
		{
			child = fork();//TODO protect
			if (child == 0)
				clear(envp);
			waitpid(child, NULL, 0);//TODO protect
		}
		else if (!ft_strcmp("unset", tmp2[0]))
			env_var = unset(&tmp2[1], env_var);
		else if (!ft_strcmp("export", tmp2[0]))
			env_var = export(&tmp2[1], env_var);
		else if (!ft_strcmp("env", tmp2[0]))
			env(&tmp2[1], env_var);
		else if (!ft_strcmp("echo", tmp2[0]))
			echo(&tmp2[1], env_var);
		free_str(tmp2);
		// t_env *printer = env_var;
		// int i = 0;
		// while (printer->next)
		// {
		// 	printf("Noeud %d :\n", i + 1);
		// 	printf("Env name :%s\n", printer->next->name);
		// 	printf("Env value :%s\n", printer->next->value);
		// 	printf("Env pwd :%s\n", printer->next->s_pwd);
		// 	printf("Env previous :%p\n", printer->next->prev);
		// 	printf("Env next :%p\n", printer->next->next);
		// 	printf("-------------------------------\n");
		// 	printer = printer->next;
		// }
	}
	rl_clear_history();
	free_env(env_var);
	free(prompt);
}
