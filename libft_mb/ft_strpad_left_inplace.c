/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpad_left_inplace.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:43:19 by mbeeler           #+#    #+#             */
/*   Updated: 2022/02/19 00:19:13 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strpad_left_inplace(char **str, char c, int num)
{
	char	*ret;
	int		i;

	if (*str)
	{
		ret = ft_strnew(ft_strlen(*str) + num);
		ft_strcpy(ret + num, *str);
		i = -1;
		while (++i < num)
			ret[i] = c;
		ft_strdel(str);
		*str = ret;
	}
}
