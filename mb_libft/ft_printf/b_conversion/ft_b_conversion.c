/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:43:19 by mbeeler           #+#    #+#             */
/*   Updated: 2022/05/19 14:43:16 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_b_conversion(const char **format, t_printer *args)
{
	char	*result;

	args->hash = 0;
	args->plus = 0;
	args->space = 0;
	if (args->mod_hh == 1)
		result = ft_lutobin_size((t_u64)va_arg(args->ap, t_u32), 8);
	else if (args->mod_h == 1)
		result = ft_lutobin_size((t_u64)va_arg(args->ap, t_u32), 16);
	else if (args->mod_l == 1 || args->mod_ll == 1)
		result = ft_lutobin_size(va_arg(args->ap, t_u64), 64);
	else
		result = ft_lutobin_size((t_u64)va_arg(args->ap, t_u32), 32);
	args->digits = ft_strlen(result);
	ft_print_width_precision(format, args, 1);
	args->arg_len += write(1, result, ft_strlen(result));
	ft_strdel(&result);
	ft_print_dash(args, 1);
}
