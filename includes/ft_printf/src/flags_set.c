/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tntini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 09:16:44 by tntini            #+#    #+#             */
/*   Updated: 2018/10/10 09:16:50 by tntini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_check_flag(char **format, t_flags *f)
{
	int i;

	i = ft_count_flags(*format);
	if (i == 0)
		return (0);
	while (i-- > 0)
	{
		if (**format == '+')
			f->plus = 1;
		else if (**format == '-')
			f->minus = 1;
		else if (**format == '0')
			f->zero = 1;
		else if (**format == '#')
			f->hash = 1;
		else if (**format == ' ')
			f->space = 1;
		else if (**format == '*')
			f->star = 1;
		else
			return (0);
		*format += 1;
	}
	return (1);
}

char	*ft_flags(char *s, t_flags *f)
{
	if (f->space == 1)
		s = ft_space(s, f);
	if (f->zero == 1)
		ft_zero_fl(s, '0', f);
	if (!s)
		return (NULL);
	return (s);
}

void	ft_reset(t_flags *f, t_length *l)
{
	f->plus = 0;
	f->minus = 0;
	f->hash = 0;
	f->space = 0;
	f->zero = 0;
	f->star = 0;
	f->s_size = 0;
	f->precision = -1;
	f->min_width = -1;
	f->conv = 0;
	l->none = 0;
	l->hh = 0;
	l->h = 0;
	l->l = 0;
	l->ll = 0;
	l->j = 0;
	l->z = 0;
}
