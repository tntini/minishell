/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identification_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tntini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 09:18:19 by tntini            #+#    #+#             */
/*   Updated: 2018/10/10 09:18:24 by tntini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_pe(va_list *ap, t_flags *f, t_length *l)
{
	union u_data	type;
	char			*s;

	if (l->lll == 1)
		return (ft_pe_long(ap, f));
	type.d = va_arg(*ap, double);
	if (type.d == 0.0 && f->precision == 0)
		return (ft_strnew(0));
	if (f->precision == -1)
		f->precision = 6;
	s = ft_itoa_exp(type.d, f->precision);
	if (f->conv == 'E')
		ft_toupper_s(s);
	return (s);
}

char	*ft_pu(va_list *ap, t_flags *f, t_length *l)
{
	union u_data	type;
	intmax_t		i;
	char			*s;

	if (f->conv == 'U')
		l->l = 1;
	type.u = ft_conv_unsigned(ap, l);
	if (type.u == 0 && f->precision == 0)
		return (ft_strnew(0));
	if (type.u == 0)
	{
		s = ft_strnew(1);
		s[0] = '0';
	}
	else
		s = ft_itoa_unsigned(type.u, 10);
	i = ft_strlen(s);
	if (i < f->precision)
		return (ft_precision(s, f->precision - i));
	return (s);
}

char	*ft_pper(void)
{
	char *s;

	s = ft_strnew(1);
	s[0] = '%';
	return (s);
}

char	*ft_pf(va_list *ap, t_flags *f, t_length *l)
{
	union u_data	type;
	char			*s;

	if (l->lll == 1)
		return (ft_pf_long(ap, f));
	type.d = va_arg(*ap, double);
	if (type.d == 0.0 && f->precision == 0)
		return (ft_strnew(0));
	if (f->precision == -1)
		f->precision = 6;
	s = ft_itoa_double(type.d, f->precision);
	return (s);
}

char	*ft_pg(va_list *ap, t_flags *f, t_length *l)
{
	union u_data	type;
	char			*s;

	if (l->lll == 1)
		return (ft_pg_long(ap, f));
	type.d = va_arg(*ap, double);
	if (type.d == 0.0 && f->precision == 0)
		return (ft_strnew(0));
	if (f->precision == -1)
		f->precision = 6;
	s = ft_itoa_double_g(type.d, f->precision);
	if (f->conv == 'G')
		ft_toupper_s(s);
	return (s);
}
