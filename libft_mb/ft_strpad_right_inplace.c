/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpad_right_inplace.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:43:19 by mbeeler           #+#    #+#             */
/*   Updated: 2022/02/19 00:19:55 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strpad_right_inplace(char **str, char c, int num)
{
	char	*ret;
	int		i;

	if (*str)
	{
		i = ft_strlen(*str);
		ret = ft_strnew(i + num);
		ft_strcpy(ret, *str);
		while (--num >= 0)
		{
			ret[i] = c;
			i++;
		}
		ft_strdel(str);
		*str = ret;
	}
}
