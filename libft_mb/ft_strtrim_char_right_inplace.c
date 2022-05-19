/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_char_right_inplace.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:43:19 by mbeeler           #+#    #+#             */
/*   Updated: 2022/02/19 13:24:34 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strtrim_char_right_inplace(char **s, char c)
{
	unsigned int	i;
	char			*ret;

	if (*s)
	{
		i = ft_strlen(*s) - 1;
		while (*(*s + i) == c && i >= 0)
			i--;
		if (i >= 0)
		{
			ret = ft_strndup(*s, i + 1);
			if (ret)
			{
				ft_strdel(s);
				*s = ret;
			}
		}
	}
}
