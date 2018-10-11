/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identification_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tntini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 09:18:38 by tntini            #+#    #+#             */
/*   Updated: 2018/10/10 09:18:45 by tntini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_null_s(t_flags *f)
{
	if (f->precision > 0 && f->precision < 6)
		return (ft_strsub("(null)", 0, f->precision));
	else if (f->precision == 0)
	{
		f->precision = -5;
		return ("");
	}
	f->precision = -5;
	return ("(null)");
}

char	*ft_pws(va_list *ap, t_flags *f)
{
	union u_data	type;
	char			*tmp;
	char			*tmp2;
	char			*s;

	s = ft_strnew(1);
	if (!(type.ws = va_arg(*ap, wchar_t*)))
		return (ft_null_s(f));
	if (!ft_strlen((char*)(type.ws)) || f->precision == 0)
	{
		f->precision = -5;
		return ("");
	}
	while (*type.ws)
	{
		if ((ft_count_wsize(*type.ws) + ft_strlen(s)) > f->precision
			&& f->precision > 0)
			break ;
		tmp = ft_wprint(*type.ws);
		tmp2 = s;
		s = ft_strjoin(tmp2, tmp);
		++type.ws;
	}
	free(tmp);
	return (s);
}

char	*ft_ps(va_list *ap, t_flags *f, t_length *l)
{
	union u_data	type;
	intmax_t		i;

	if ((l->l == 1 && f->conv == 's') || f->conv == 'S')
		return (ft_pws(ap, f));
	if (!(type.s = va_arg(*ap, char*)))
		return (ft_null_s(f));
	if (!(i = ft_strlen(type.s)) && f->minus == 1 && f->min_width > 0)
		f->total_size--;
	if (f->precision == -1)
		f->precision = i;
	if (f->precision < i)
		return (ft_strsub(type.s, 0, f->precision));
	return (ft_strdup(type.s));
}

char	*ft_pp(va_list *ap, t_flags *f)
{
	uintmax_t	addr;
	char		*tmp;
	char		*s;

	addr = va_arg(*ap, uintmax_t);
	if (f->precision == 0)
		return (ft_strdup("0x"));
	if (addr == 0)
	{
		tmp = ft_strnew(1);
		tmp[0] = '0';
	}
	else
		tmp = ft_itoa_unsigned(addr, 16);
	if (ft_strlen(tmp) < f->precision)
		tmp = ft_precision(tmp, f->precision - ft_strlen(tmp));
	s = ft_strjoin("0x", tmp);
	if (f->zero == 1 && (f->min_width > ft_strlen(s)))
	{
		addr = f->min_width - ft_strlen(s);
		while (addr-- > 0 && (tmp = s))
			s = ft_strjoin(tmp, "0");
	}
	free(tmp);
	return (s);
}
