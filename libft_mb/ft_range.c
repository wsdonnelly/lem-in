/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:36:42 by manuelbeele       #+#    #+#             */
/*   Updated: 2021/11/02 20:05:00 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_range(int min, int max)
{
	int	*array;
	int	len;
	int	i;

	if (min >= max)
		return (NULL);
	len = max - min;
	array = (int *) malloc(sizeof(*array) * len);
	if (!array)
		return (NULL);
	i = -1;
	while (++i < len)
	{
		array[i] = min;
		min++;
	}
	return (array);
}
