/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tntini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 09:28:28 by tntini            #+#    #+#             */
/*   Updated: 2018/10/11 09:59:24 by tntini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	create_env(char ***env, char **envp)
{
	int i;
	int p;

	i = -1;
	while (envp[++i])
		NULL;
	(*env) = (char**)ft_memalloc(sizeof(char*) * i);
	i = -1;
	while (envp[++i])
	{
		(*env)[i] = (char*)ft_memalloc(PATH_MAX + 1);
		p = -1;
		while (envp[i][++p])
			(*env)[i][p] = envp[i][p];
		(*env)[i][p] = 0;
	}
	(*env)[i] = NULL;
	i = -1;
}

static void	prompt(char **env)
{
	int		i;
	int		lethu;
	char	buf[PATH_MAX];

	i = -1;
	while (++i < PATH_MAX)
		buf[i] = 0;
	getcwd(buf, PATH_MAX);
	i = -1;
	while (buf[++i])
	{
		if (buf[i] == '/')
			lethu = i;
	}
	if (!ft_strcmp(buf, find_env("$HOME", env)))
	{
		i = -1;
		while ((buf[++i]))
			buf[i] = 0;
		buf[0] = '~';
	}
	(buf[0] == '~' || (buf[0] && !lethu)) ? ft_printf(BOLD"%s ", buf) : 0;
	(buf[0] != '~' && lethu) ? ft_printf(BOLD"%s ", (buf + lethu + 1)) : 0;
}

static char	**run_commands(char **comands, char **env)
{
	char	**args;
	int		status;
	int		i;
	int		k;

	status = 1;
	i = 0;
	k = 0;
	while (comands[k])
	{
		args = ft_strtok(comands[k], SPACES);
		rl_bind_key('\t', rl_complete);
		env = execution(args, env);
		free(comands[k]);
		k++;
		while (args[i])
			free(args[i++]);
		(args) ? free(args) : 0;
		if (!env)
			return (NULL);
	}
	return (env);
}

int			main(int ac, char **args, char **envp)
{
	char	*line;
	char	**comands;
	char	**env;

	(void)ac;
	(void)args;
	create_env(&env, envp);
	while (env)
	{
		prompt(env);
		set_dir(env, "PWD");
		initialize_readline();
		line = readline(YEL"⇢  "RESET);
		if (!line || !*line)
			continue ;
		add_history(line);
		comands = ft_strtok(line, ";");
		env = run_commands(comands, env);
		free(comands);
		free(line);
	}
	return (0);
}
