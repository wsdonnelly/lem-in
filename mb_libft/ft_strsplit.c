/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 09:53:10 by manuelbeele       #+#    #+#             */
/*   Updated: 2021/11/23 12:30:14 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_fillarray(char const *s, char c, char **array, \
	unsigned int count)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	start;

	j = 0;
	i = 0;
	while (j < count)
	{
		if (i == 0 && s[i] != c)
			start = 0;
		else
		{
			while (s[i] == c)
				i++;
			start = i;
		}
		while (s[i] != c && s[i] != '\0')
			i++;
		array[j] = ft_strsub(s, start, (size_t)(i - start));
		j++;
	}
	return (array);
}

char	**ft_strsplit(char const *s, char c)
{
	char			**array;
	unsigned int	i;
	unsigned int	count;

	if (!s)
		return (NULL);
	i = 0;
	count = 1;
	if (s[i] != c && s[i] != '\0')
		count++;
	while (s[i] != '\0' && s[i + 1] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	array = (char **)malloc(sizeof(char *) * count);
	if (!array)
		return (NULL);
	if (count > 1)
		array = ft_fillarray(s, c, array, count);
	array[count - 1] = NULL;
	return (array);
}
