/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:39:33 by manuelbeele       #+#    #+#             */
/*   Updated: 2021/12/05 17:21:41 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*copy;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1) + 1;
	copy = (char *) malloc(len);
	if (!copy)
		return (NULL);
	return (ft_strmove(copy, s1, len));
}
