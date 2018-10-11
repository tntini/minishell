/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tntini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 09:02:27 by tntini            #+#    #+#             */
/*   Updated: 2018/10/10 09:02:32 by tntini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_countnumber(intmax_t v, int b)
{
	long	i;

	i = 0;
	if (v < 0)
	{
		i = i + 1;
		v = v * -1;
	}
	while (v > 0)
	{
		i = i + 1;
		v = v / b;
	}
	return (i);
}