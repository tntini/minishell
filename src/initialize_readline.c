/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_readline.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tntini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 09:27:30 by tntini            #+#    #+#             */
/*   Updated: 2018/10/11 09:58:41 by tntini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*g_cmd[] = {
	"cd", "echo", "env", "setenv", "unsetenv", "pwd", "exit",
	"emacs", "vim", "mkdir", "ls", "rm", "rmdir", "clear",
	"locate", "touch", "man", "mv", "gcc", "cat", (char*)NULL
};

static char	*command_generator(const char *text, int state)
{
	static int	i;
	static int	len;
	char		*ntini;

	if (!state)
	{
		i = 0;
		len = ft_strlen(text);
	}
	while (g_cmd[i] && (ntini = g_cmd[i]))
	{
		i++;
		if (ft_strncmp(ntini, text, len) == 0)
			return (ft_strdup(ntini));
	}
	return ((char *)NULL);
}

static char	**ash_complition(const char *text, int start, int end)
{
	char **matches;

	matches = NULL;
	(void)end;
	if (start == 0)
		matches = rl_completion_matches(text, command_generator);
	return (matches);
}

void		initialize_readline(void)
{
	rl_readline_name = "minishell";
	rl_attempted_completion_function = ash_complition;
}
