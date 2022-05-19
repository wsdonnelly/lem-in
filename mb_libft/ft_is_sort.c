/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:26:54 by manuelbeele       #+#    #+#             */
/*   Updated: 2021/11/02 19:56:38 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f) (int, int))
{
	int		i;
	int		direction;

	direction = 0;
	i = -1;
	while (++i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0 && direction >= 0)
			direction = 1;
		else if (f(tab[i], tab[i + 1]) < 0 && direction <= 0)
			direction = -1;
		else if (direction != 0)
			return (0);
	}
	return (1);
}
