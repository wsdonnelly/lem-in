/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lutoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:30:37 by manuelbeele       #+#    #+#             */
/*   Updated: 2022/02/19 00:06:37 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_measure_length(unsigned long n, int base)
{
	int	len;

	len = 0;
	while (n > (unsigned long) base - 1)
	{
		n /= base;
		len++;
	}
	return (len);
}

char	*ft_lutoa_base(unsigned long n, int base)
{
	int		len;
	char	*ret;

	len = ft_measure_length(n, base) + 1;
	ret = ft_strnew((char) len);
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	while (--len >= 0)
	{
		ret[len] = '0' + (n % base);
		n /= base;
	}
	return (ret);
}
