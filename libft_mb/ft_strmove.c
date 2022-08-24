/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:16:46 by manuelbeele       #+#    #+#             */
/*   Updated: 2021/12/05 17:20:45 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmove(char *dst, const char *src, size_t len)
{
	size_t	i;

	if ((len == 0) || (!dst && !src))
		return (dst);
	if (dst > src)
	{
		i = len;
		while (i-- > 0)
			dst[i] = src[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			dst[i] = src[i];
			i++;
		}
	}
	return (dst);
}
