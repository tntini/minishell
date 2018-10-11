/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tntini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 09:20:08 by tntini            #+#    #+#             */
/*   Updated: 2018/10/10 09:20:13 by tntini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_extend_s(t_flags *f, char *s, int k, char left)
{
	char *tmp;

	if (left == '+')
	{
		while (k-- > 0)
		{
			tmp = s;
			s = ft_strjoin(" ", tmp);
		}
		return (s);
	}
	if (!ft_strlen(s))
	{
		write(1, s, 1);
		if (f->conv == 'c' || f->conv == 'C')
			f->s_size--;
		f->total_size++;
	}
	while (k-- > 0)
	{
		tmp = s;
		s = ft_strjoin(tmp, " ");
	}
	return (s);
}

char	*ft_min_width(char *s, t_flags *f)
{
	intmax_t	i;
	char		*tmp;

	i = ft_strlen(s);
	if ((f->conv == 'd' || f->conv == 'i' || f->conv == 'e' ||
		f->conv == 'E' || f->conv == 'f' || f->conv == 'F' ||
		f->conv == 'g' || f->conv == 'G') &&
		i > 0 && s[0] != '-' && f->plus == 1)
	{
		tmp = s;
		s = ft_strjoin("+", tmp);
		f->min_width -= 1;
	}
	if (i > f->min_width)
		return (s);
	if (f->minus == 1)
		return (ft_extend_s(f, s, f->min_width - i, '-'));
	return (ft_extend_s(f, s, f->min_width - i, '+'));
}
