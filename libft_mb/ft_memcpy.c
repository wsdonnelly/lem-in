/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:25:04 by manuelbeele       #+#    #+#             */
/*   Updated: 2021/11/18 20:24:50 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*str1;
	char	*str2;

	if ((n == 0) || (dst == src) || !dst || !src)
		return (dst);
	i = 0;
	str1 = (char *) src;
	str2 = (char *) dst;
	while (i < n)
	{
		str2[i] = str1[i];
		i++;
	}
	return (dst);
}
