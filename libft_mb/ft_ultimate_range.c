/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:43:38 by manuelbeele       #+#    #+#             */
/*   Updated: 2021/11/02 20:05:43 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ultimate_range(int **range, int min, int max)
{
	int		i;
	int		*num;

	i = 0;
	if (min < max)
		num = (int *)malloc(sizeof(num) * (max - min));
	else
		num = 0;
	if (num == 0)
	{
		*range = 0;
		return (0);
	}
	while (i < max - min)
	{
		num[i] = min + i;
		i++;
	}
	*range = num;
	return (i);
}
