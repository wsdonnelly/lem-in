/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ppc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 22:04:51 by wdonnell          #+#    #+#             */
/*   Updated: 2022/02/14 11:58:36 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(t_pformat *cur, va_list ap)
{
	unsigned char	c;

	c = (unsigned char)va_arg(ap, int);
	if (cur->field_width)
	{
		if (cur->flags & MINUS)
		{
			cur->length += write (1, &c, 1);
			cur->length += write_char(' ', cur->field_width - 1);
			return ;
		}
		cur->length += write_char(' ', cur->field_width - 1);
	}
	cur->length += write (1, &c, 1);
}

void	print_percent(t_pformat *cur, va_list ap)
{
	ap = NULL;
	if (cur->field_width)
	{
		if (cur->flags & MINUS)
		{
			cur->length += write (1, "%", 1);
			cur->length += write_char(' ', cur->field_width - 1);
			return ;
		}
		if (cur->flags & ZERO)
			cur->length += write_char('0', cur->field_width - 1);
		else
			cur->length += write_char(' ', cur->field_width - 1);
	}
	cur->length += write (1, "%", 1);
}

void	print_pointer(t_pformat *cur, va_list ap)
{
	unsigned long	n;

	n = (unsigned long)va_arg(ap, void *);
	cur->length = num_digits_base(n, 16, 0) + 2;
	if (cur->field_width > cur->length)
	{
		if (cur->flags & MINUS)
		{
			write (1, "0x", 2);
			ft_putnbr_base(n, 16, 0);
			cur->length += write_char(' ', cur->field_width - cur->length);
			return ;
		}
		cur->length += write_char(' ', cur->field_width - cur->length);
		write (1, "0x", 2);
		ft_putnbr_base(n, 16, 0);
		return ;
	}
	write (1, "0x", 2);
	ft_putnbr_base(n, 16, 0);
}
