/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tntini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 09:28:07 by tntini            #+#    #+#             */
/*   Updated: 2018/10/11 09:58:21 by tntini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**execution(char **args, char **env)
{
	if (!args || !*args || !**args)
		return (env);
	else if (!ft_strncmp(args[0], "cd", PATH_MAX))
		return (cd_cmd(args, env));
	else if (!ft_strncmp(args[0], "echo", PATH_MAX))
		return (echo_cmd(args, env));
	else if (!ft_strncmp(args[0], "env", PATH_MAX))
		return (env_cmd(env));
	else if (!ft_strncmp(args[0], "setenv", PATH_MAX))
		return (setenv_cmd(args, env));
	else if (!ft_strncmp(args[0], "unsetenv", PATH_MAX))
		return (unsetenv_cmd(args, env));
	else if (!ft_strncmp(args[0], "pwd", PATH_MAX))
		return (pwd_cmd(args, env));
	else if (!ft_strncmp(args[0], "exit", PATH_MAX))
		return (exit_cmd(env));
	else
		return (launch(args, env));
	return (env);
}
