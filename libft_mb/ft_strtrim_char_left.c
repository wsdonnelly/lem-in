/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_char_left.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:43:19 by mbeeler           #+#    #+#             */
/*   Updated: 2022/02/19 00:02:39 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim_char_left(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;
	char			*ret;

	if (s)
	{
		i = 0;
		while (s[i] == c)
			i++;
		j = ft_strlen(s);
		len = j - i;
		if (len > 0)
		{
			ret = ft_strdup(s + i);
			if (ret)
				return (ret);
		}
	}
	return (NULL);
}
