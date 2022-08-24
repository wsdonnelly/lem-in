/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_char_right.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:43:19 by mbeeler           #+#    #+#             */
/*   Updated: 2022/02/19 00:04:29 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim_char_right(char const *s, char c)
{
	unsigned int	i;
	char			*ret;

	if (s)
	{
		i = ft_strlen(s) - 1;
		while (s[i] == c && i >= 0)
			i--;
		if (i >= 0)
		{
			ret = ft_strndup(s, i + 1);
			if (ret)
				return (ret);
		}
	}
	return (NULL);
}
