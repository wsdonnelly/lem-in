/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_sig_bytes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:43:19 by mbeeler           #+#    #+#             */
/*   Updated: 2022/05/19 14:47:14 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_get_sig_bytes(const char **format, t_printer *args, t_u64 n, int div)
{
	int	digits;

	digits = 1;
	if (args->neg == 1 || args->space == 1 || args->plus == 1
		|| args->hash == 1)
		args->sign = 1;
	if (args->hash == 1
		&& (**format == 'x' || **format == 'X' || **format == 'p'))
	{
		args->sign = 2;
		args->precision += 1;
		args->precision2 += 1;
	}
	while (n / div > 0)
	{
		n /= div;
		digits++;
	}
	return (digits);
}
