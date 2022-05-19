/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpad_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:43:19 by mbeeler           #+#    #+#             */
/*   Updated: 2022/02/18 23:59:00 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpad_left(const char *str, char c, int num)
{
	char	*ret;
	int		i;

	if (!str)
		return (NULL);
	ret = ft_strnew(ft_strlen(str) + num);
	ft_strcpy(ret + num, str);
	i = -1;
	while (++i < num)
		ret[i] = c;
	return (ret);
}
