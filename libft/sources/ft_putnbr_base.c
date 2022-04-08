/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:19:39 by wdonnell          #+#    #+#             */
/*   Updated: 2022/02/11 13:37:35 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** from base 2 to 38 (extend to base 72 w/flag or base 40 w/o flag)
** if flag print upper case else lower case
** 
*/

void	ft_putnbr_base(unsigned long long n, int base, int flag)
{
	if (n == 0)
	{
		ft_putchar('0');
		return ;
	}
	if (n / base)
		ft_putnbr_base(n / base, base, flag);
	if (n % base > 9)
	{
		if (flag)
			ft_putchar((n % base) - 10 + 'A');
		else
			ft_putchar((n % base) - 10 + 'a');
		return ;
	}
	else
	{
		ft_putchar(n % base + '0');
		return ;
	}
	return ;
}
