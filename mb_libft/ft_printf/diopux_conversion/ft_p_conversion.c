/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:43:19 by mbeeler           #+#    #+#             */
/*   Updated: 2022/05/19 14:47:11 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_p_conversion(const char **format, t_printer *args)
{
	t_u64	n;

	args->plus = 0;
	args->space = 0;
	args->zero = 0;
	args->hash = 1;
	n = (t_u64)va_arg(args->ap, void *);
	args->digits = ft_get_sig_bytes(format, args, n, 16);
	if (n == 0 && args->dot == 1 && args->width != 0)
		args->width++;
	else if (n == 0 && args->dot == 1)
		args->precision++;
	ft_print_width_precision(format, args, n);
	if (n != 0 || args->dot == 0)
		ft_print_number(format, args, n, 16);
	ft_print_dash(args, n);
}
