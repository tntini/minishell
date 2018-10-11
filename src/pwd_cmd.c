/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tntini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 10:36:44 by tntini            #+#    #+#             */
/*   Updated: 2018/10/11 10:22:48 by tntini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**pwd_cmd(char **args, char **env)
{
	char	buf[PATH_MAX + 1];
	int		k;

	k = 0;
	while (args[k])
		k++;
	(k > 1) ? ft_printf("pwd: too many arguments\n") : 0;
	(k == 1) ? ft_printf("%s\n", getcwd(buf, PATH_MAX)) : 0;
	return (env);
}
