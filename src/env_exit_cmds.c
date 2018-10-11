/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_exit_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tntini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 10:35:22 by tntini            #+#    #+#             */
/*   Updated: 2018/10/11 09:57:54 by tntini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**exit_cmd(char **env)
{
	free_env(env);
	return (NULL);
}

char	**env_cmd(char **env)
{
	int i;

	i = 0;
	while (env[i])
		ft_printf("%s\n", env[i++]);
	return (env);
}
