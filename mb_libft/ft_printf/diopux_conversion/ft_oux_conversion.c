/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oux_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:43:19 by mbeeler           #+#    #+#             */
/*   Updated: 2022/05/19 14:47:13 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_print_oux(const char **format, t_u64 n, t_printer *args, int div)
{
	if (n == 0)
	{
		if (**format == 'o' && args->hash == 1)
			args->hash2 = 1;
		args->hash = 0;
	}
	args->digits = ft_get_sig_bytes(format, args, n, div);
	ft_print_width_precision(format, args, n);
	if (n != 0 || args->precision2 != 0 || args->dot == 0 || \
		(**format == 'o' && args->hash2 == 1))
		ft_print_number(format, args, n, div);
	ft_print_dash(args, n);
}

void	ft_oux_conversion(const char **format, t_printer *args)
{
	t_u64	n;
	int		div;

	div = 16;
	if (**format == 'o')
		div = 8;
	else if (**format == 'u')
	{
		div = 10;
		args->hash = 0;
	}
	args->plus = 0;
	args->space = 0;
	if (args->mod_l == 1 || args->mod_ll == 1)
		n = va_arg(args->ap, t_u64);
	else if (args->mod_h == 1)
		n = (t_u64)(t_u16)va_arg(args->ap, t_u32);
	else if (args->mod_hh == 1)
		n = (t_u64)(t_u8)va_arg(args->ap, t_u32);
	else
		n = (t_u64)va_arg(args->ap, t_u32);
	ft_print_oux(format, n, args, div);
}
