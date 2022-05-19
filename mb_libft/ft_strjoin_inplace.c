/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_inplace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:38:43 by manuelbeele       #+#    #+#             */
/*   Updated: 2022/02/19 13:00:47 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strjoin_inplace(char **s1, char **s2)
{
	char	*ret;
	size_t	len;

	if (*s1 && *s2)
	{
		len = ft_strlen(*s1);
		ret = ft_strnew(len + ft_strlen(*s2));
		if (ret)
		{
			ft_strcpy(ret, *s1);
			ft_strcpy((ret + len), *s2);
			ft_strdel(s1);
			ft_strdel(s2);
			*s1 = ret;
		}
	}
}
