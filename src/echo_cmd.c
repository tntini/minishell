/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tntini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 09:27:46 by tntini            #+#    #+#             */
/*   Updated: 2018/10/11 09:57:24 by tntini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_arg(char **s, int j, char **env)
{
	int			t;

	t = 0;
	while (s[j][t])
	{
		if (s[j][t] == '"' || s[j][t] == '\'' || s[j][t] == '\\')
			t++;
		if (!s[j][t])
			break ;
		if ((s[j][t] == '$' || s[j][t] == '~') &&
			(t = check_env(s[j], t, env)) == -1)
			return (-1);
		else
			(s[j][t] ? ft_printf("%c", s[j][t]) : 0);
		t++;
	}
	return (0);
}

int			read_args(char **args, int j, char **env)
{
	while (args[j])
	{
		if (check_arg(args, j, env) == -1)
			return (-1);
		(args[++j]) ? ft_printf(" ") : 0;
	}
	return (0);
}

int			check_str(char **args, int j, char **env)
{
	char *s;

	s = NULL;
	if (args[j][0])
	{
		if (read_args(args, j, env) == -1)
			return (-1);
	}
	return (0);
}

char		**echo_cmd(char **a, char **env)
{
	int		i;
	int		l;
	int		new_line;

	i = 1;
	l = 0;
	if (!a[1] || !a[1][0])
	{
		ft_printf("\n");
		return (env);
	}
	new_line = (!ft_strncmp("-n", a[++l], PATH_MAX)) ? 1 : 0;
	(new_line) ? l++ : 0;
	check_str(a, l, env);
	(new_line) ? 0 : ft_printf("\n");
	return (env);
}
