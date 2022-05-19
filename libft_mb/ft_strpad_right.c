/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpad_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:43:19 by mbeeler           #+#    #+#             */
/*   Updated: 2022/02/19 00:00:56 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpad_right(const char *str, char c, int num)
{
	char	*ret;
	int		i;

	if (!str)
		return (NULL);
	i = ft_strlen(str);
	ret = ft_strnew(i + num);
	ft_strcpy(ret, str);
	while (--num >= 0)
	{
		ret[i] = c;
		i++;
	}
	return (ret);
}
