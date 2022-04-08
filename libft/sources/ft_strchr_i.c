/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:50:55 by wdonnell          #+#    #+#             */
/*   Updated: 2022/02/11 13:42:08 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** return index of found char -1 if not
*/

int	ft_strchr_i(const char *s, int c)
{
	int		i;
	char	*p;
	char	cc;

	cc = (char)c;
	p = (char *)s;
	i = 0;
	if (*p == '\0' && cc != '\0')
		return (-1);
	while (p[i] != cc && p[i] != '\0')
	{
		i++;
		if (p[i] == '\0')
			return (-1);
	}
	return (i);
}
