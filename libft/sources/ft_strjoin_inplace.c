/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_inplace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:08:38 by wdonnell          #+#    #+#             */
/*   Updated: 2022/04/28 10:10:42 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**Created by Manuel Beeler
*/

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
			//ft_strdel(s2);
			*s1 = ret;
		}
	}
}
