/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tntini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 09:08:41 by tntini            #+#    #+#             */
/*   Updated: 2018/10/10 09:08:52 by tntini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_unsigned(uintmax_t num, int base)
{
	uintmax_t	value;
	long		i;
	char		*s;

	i = 0;
	value = num;
	while (value)
	{
		i++;
		value /= base;
	}
	s = ft_strnew(i);
	s[i] = 0;
	while (num)
	{
		s[--i] = "0123456789abcdef"[num % base];
		num /= base;
	}
	return (s);
}
