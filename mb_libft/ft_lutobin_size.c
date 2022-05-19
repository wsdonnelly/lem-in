/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utobin_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:43:19 by mbeeler           #+#    #+#             */
/*   Updated: 2022/03/04 15:22:13 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lutobin_size(unsigned long n, char size)
{
	char	*bin;
	int		i;

	i = -1;
	bin = ft_strnew(size);
	ft_memset(bin, '0', size);
	if (n)
	{
		while (++i < size)
		{
			if ((n << (63 - i)) >> 63 > 0)
				bin[size - i - 1] = '1';
		}
	}
	return (bin);
}
