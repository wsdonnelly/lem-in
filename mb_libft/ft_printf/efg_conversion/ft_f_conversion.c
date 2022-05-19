/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:43:19 by mbeeler           #+#    #+#             */
/*   Updated: 2022/05/19 14:46:57 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_f_conversion(t_printer *args)
{
	t_f128	n;
	char	*result;

	if (args->dot == 0)
	{
		args->precision = 6;
		args->precision2 = 6;
	}
	if (args->mod_cap_l == 1)
		n = ft_convert_float(args, va_arg(args->ap, t_f128));
	else
		n = ft_convert_float(args, (t_f128)va_arg(args->ap, t_f64));
	result = ft_printf_lftoa(n, args);
	if (*result < '0' || *result > '9')
	{
		args->hash = 0;
		args->zero = 0;
	}
	if (ft_strchr(result, '.'))
		args->hash = 0;
	ft_print_width(result, args);
	args->arg_len += write(1, result, ft_strlen(result));
	ft_print_hash_dash(args, result);
	ft_strdel(&result);
}
