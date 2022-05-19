/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cs_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:43:19 by mbeeler           #+#    #+#             */
/*   Updated: 2022/05/19 14:43:51 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_c_conversion(const char **format, t_printer *args, char c)
{
	if (args->width > 1 && args->dash == 0 && (args->zero == 0 || \
		**format == 'c'))
	{
		while (args->width-- > 1)
			args->arg_len += write(1, " ", 1);
	}
	if (args->width > 1 && args->dash == 0 && args->zero == 1
		&& **format == '%')
	{
		while (args->width-- > 1)
			args->arg_len += write(1, "0", 1);
	}
	args->arg_len += write(1, &c, 1);
	if (args->width > 1 && args->dash == 1)
	{
		while (args->width-- > 1)
			args->arg_len += write(1, " ", 1);
	}
}

static void	ft_s_conversion(t_printer *args, char *s)
{
	int		len;

	if (s)
		len = ft_strlen(s);
	else
		len = 6;
	if (args->dot == 1 && args->precision < len)
		len = args->precision;
	if (args->width > len && args->dash == 0)
	{
		while (args->width-- > len)
			args->arg_len += write(1, " ", 1);
	}
	if (s)
		args->arg_len += write(1, s, len);
	else
		args->arg_len += write(1, "(null)", len);
	if (args->width > len && args->dash == 1)
	{
		while (args->width-- > len)
			args->arg_len += write(1, " ", 1);
	}
}

void	ft_cs_conversion(const char **format, t_printer *args)
{
	if (**format == 'c')
		ft_c_conversion(format, args, (char)va_arg(args->ap, int));
	else if (**format == '%')
		ft_c_conversion(format, args, '%');
	else
		ft_s_conversion(args, va_arg(args->ap, char *));
}
