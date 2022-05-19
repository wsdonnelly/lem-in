/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:25:05 by manuelbeele       #+#    #+#             */
/*   Updated: 2021/11/02 19:56:09 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	int		i;

	i = 2;
	if (nb <= 1)
		return (2);
	else
	{
		while (i < nb)
		{
			if (nb % i == 0)
				nb = ft_find_next_prime(nb + 1);
			i++;
		}
	}
	return (nb);
}
