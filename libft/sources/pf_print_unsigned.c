/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:37:59 by wdonnell          #+#    #+#             */
/*   Updated: 2022/02/14 11:58:56 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_precision_unsigned(t_pformat *cur, unsigned long long n)
{
	if (n == 0)
	{
		if (((cur->flags & DOT) && !cur->precision))
		{
			cur->length--;
			return ;
		}
	}
	if (cur->precision > cur->length)
		cur->length += write_char('0', cur->precision - cur->length);
	ft_putnbr_base(n, 10, 0);
}

static void	left_align_unsigned(t_pformat *cur, unsigned long long n, \
int base_len)
{
	if (cur->field_width > base_len)
	{
		print_precision_unsigned(cur, n);
		cur->length += write_char(' ', cur->field_width - base_len);
		return ;
	}
	print_precision_unsigned(cur, n);
}

static void	right_align_unsigned(t_pformat *cur, unsigned long long n, \
int base_len)
{
	if (cur->field_width > base_len)
	{
		if ((cur->flags & ZERO) && !(cur->flags & DOT))
			write_char('0', cur->field_width - base_len);
		else
			write_char(' ', cur->field_width - base_len);
		print_precision_unsigned(cur, n);
		cur->length = cur->field_width;
		return ;
	}
	print_precision_unsigned(cur, n);
}

void	print_unsigned(t_pformat *cur, va_list ap)
{
	unsigned long long	n;
	int					base_len;

	get_modifier_u(cur, ap, &n);
	cur->length = num_digits_base(n, 10, 0);
	base_len = cur->length;
	if (cur->precision > base_len)
		base_len = cur->precision;
	if (n == 0 && (cur->flags & DOT) && !cur->precision)
		base_len = 0;
	if (cur->flags & MINUS)
		left_align_unsigned(cur, n, base_len);
	else
		right_align_unsigned(cur, n, base_len);
}
