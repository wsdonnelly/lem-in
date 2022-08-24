/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:42:47 by manuelbeele       #+#    #+#             */
/*   Updated: 2021/11/19 14:19:59 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ret;

	if (!s || !f)
		return (NULL);
	i = 0;
	ret = ft_strnew(ft_strlen(s));
	if (ret)
	{
		while (s[i] != '\0')
		{
			ret[i] = (*f)(i, s[i]);
			i++;
		}
	}
	return (ret);
}
