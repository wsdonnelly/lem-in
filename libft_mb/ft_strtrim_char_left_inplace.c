/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_char_left_inplace.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:43:19 by mbeeler           #+#    #+#             */
/*   Updated: 2022/02/19 13:23:57 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strtrim_char_left_inplace(char **s, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;
	char			*ret;

	if (*s)
	{
		i = 0;
		while (*(*s + i) == c)
			i++;
		j = ft_strlen(*s);
		len = j - i;
		if (len > 0)
		{
			ret = ft_strdup(*s + i);
			if (ret)
			{
				ft_strdel(s);
				*s = ret;
			}
		}
	}
}
