/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tntini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 09:10:24 by tntini            #+#    #+#             */
/*   Updated: 2018/10/10 09:10:29 by tntini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	ft_power(intmax_t n, long pow)
{
	if (pow == 0)
		return (1);
	return (n * ft_power(n, pow - 1));
}
