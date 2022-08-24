/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:38:43 by manuelbeele       #+#    #+#             */
/*   Updated: 2021/11/11 16:47:13 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	len;

	if (s1 && s2)
	{
		len = ft_strlen(s1);
		ret = ft_strnew(len + ft_strlen(s2));
		if (ret)
		{
			ft_strcpy(ret, s1);
			ft_strcpy((ret + len), s2);
			return (ret);
		}
	}
	return (NULL);
}
