/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lutoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:43:19 by mbeeler           #+#    #+#             */
/*   Updated: 2022/03/04 11:52:18 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_measure_length(unsigned long n)
{
	int	len;

	len = 0;
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_lutoa(unsigned long n)
{
	int		len;
	char	*ret;

	len = ft_measure_length(n) + 1;
	ret = ft_strnew(len);
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	while (--len >= 0)
	{
		ret[len] = '0' + (n % 10);
		n /= 10;
	}
	return (ret);
}
