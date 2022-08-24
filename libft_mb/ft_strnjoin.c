/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 20:14:00 by manuelbeele       #+#    #+#             */
/*   Updated: 2021/11/26 20:19:12 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t len1, size_t len2)
{
	char	*ret;

	if (s1 && s2)
	{
		ret = ft_strnew(len1 + len2);
		if (ret)
		{
			ft_strncpy(ret, s1, len1);
			ft_strncpy((ret + len1), s2, len2);
			return (ret);
		}
	}
	return (NULL);
}
