/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:26:30 by manuelbeele       #+#    #+#             */
/*   Updated: 2021/11/02 18:53:38 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int		prime;
	int		i;

	i = 2;
	prime = 1;
	if (nb <= 1)
	{
		prime = 0;
		return (prime);
	}
	else if (nb > 1)
	{
		while (i < nb)
		{
			if (nb % i == 0)
				prime = 0;
			i++;
		}
	}
	return (prime);
}
