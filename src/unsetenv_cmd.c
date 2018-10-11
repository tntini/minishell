/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tntini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 09:29:31 by tntini            #+#    #+#             */
/*   Updated: 2018/09/26 07:51:08 by tntini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**unsetenv_cmd(char **args, char **env)
{
	int i;
	int len;

	i = -1;
	len = ft_strlen(args[1]);
	(args[1]) ? (args[1] += (args[1][0] == '$')) : 0;
	if (args[1] && find_env(args[1], env)[0] != 0)
	{
		while (env[++i])
		{
			if (!ft_strncmp(env[i], args[1], len) && env[i][len] == '=')
				break ;
		}
		free(env[i]);
		i--;
		while (env[++i])
			env[i] = env[i + 1];
		env[i] = NULL;
	}
	return (env);
}
