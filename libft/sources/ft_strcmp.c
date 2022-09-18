/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:21:28 by wdonnell          #+#    #+#             */
/*   Updated: 2022/09/16 11:46:47 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned char	*p1;
	unsigned char	*p2;

	if (*s1 == '\0' && *s2 == '\0')
		return (0);
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	i = 0;
	while (p1[i] && p2[i])
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (p1[i] - p2[i]);
}
*/


int	ft_strcmp(const char *s1, const char *s2)
{
	if(!*s1)
		return (0);
	while (*s1 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return (int)(unsigned char)(*s1) - (int)(unsigned char)(*s2);
}

