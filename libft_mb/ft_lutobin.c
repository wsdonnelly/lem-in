/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lutobin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:43:19 by mbeeler           #+#    #+#             */
/*   Updated: 2022/03/04 14:03:11 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lutobin(unsigned long n)
{
	char	*bin;
	int		i;

	i = -1;
	bin = ft_strnew(64);
	ft_memset(bin, '0', 64);
	if (n)
	{
		while (++i < 64)
		{
			if ((n << (63 - i)) >> 63 > 0)
				bin[63 - i] = '1';
		}
	}
	return (bin);
}
