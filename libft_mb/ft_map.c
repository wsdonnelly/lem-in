/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:32:05 by manuelbeele       #+#    #+#             */
/*   Updated: 2021/11/02 20:04:32 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_map(int *tab, int length, int (*f) (int))
{
	int		i;
	int		*array;

	array = (int *)malloc(sizeof(array) * length);
	if (array == 0)
		return (0);
	i = -1;
	while (++i < length)
		array[i] = f(tab[i]);
	return (array);
}
