/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:00:44 by manuelbeele       #+#    #+#             */
/*   Updated: 2021/11/19 13:07:11 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;
	char			*ret;

	if (s)
	{
		i = 0;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		j = ft_strlen(s);
		if (i == j)
			len = 0;
		else
		{
			j--;
			while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
				j--;
			len = j - i + 1;
		}
		ret = ft_strsub(s, i, len);
		if (ret)
			return (ret);
	}
	return (NULL);
}
