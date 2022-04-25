/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 10:51:59 by wdonnell          #+#    #+#             */
/*   Updated: 2022/02/16 16:37:39 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_prefix_octal(t_pformat *cur)
{
	if (cur->flags & HASH)
		cur->length += write(1, "0", 1);
}

static void	print_precision_octal(t_pformat *cur, unsigned long long n)
{
	if (n == 0)
	{
		if (((cur->flags & DOT) && !cur->precision) || (cur->flags & HASH))
		{
			cur->length--;
			return ;
		}
	}
	if (cur->precision > cur->length)
		cur->length += write_char('0', cur->precision - cur->length);
	ft_putnbr_base(n, 8, 0);
}

static void	left_align_octal(t_pformat *cur, unsigned long long n, int base_len)
{
	if (cur->field_width > base_len)
	{
		print_prefix_octal(cur);
		print_precision_octal(cur, n);
		cur->length += write_char(' ', cur->field_width - base_len);
		return ;
	}
	print_prefix_octal(cur);
	print_precision_octal(cur, n);
}

static void	right_align_octal(t_pformat *cur, unsigned long long n, \
int base_len)
{
	if (cur->field_width > base_len)
	{
		if ((cur->flags & ZERO) && !(cur->flags & DOT))
			write_char('0', cur->field_width - base_len);
		else
			write_char(' ', cur->field_width - base_len);
		print_prefix_octal(cur);
		print_precision_octal(cur, n);
		cur->length = cur->field_width;
		return ;
	}
	print_prefix_octal(cur);
	print_precision_octal(cur, n);
}

void	print_octal(t_pformat *cur, va_list ap)
{
	unsigned long long	n;
	int					base_len;

	get_modifier_u(cur, ap, &n);
	cur->length = num_digits_base(n, 8, 0);
	base_len = cur->length;
	if ((cur->flags & DOT) && !cur->precision && n == 0)
		base_len--;
	if (cur->flags & HASH)
	{
		if (base_len >= cur->precision)
			base_len++;
		else
			base_len = cur->precision;
	}
	if (cur->precision > base_len)
		base_len = cur->precision;
	if (cur->flags & MINUS)
		left_align_octal(cur, n, base_len);
	else
		right_align_octal(cur, n, base_len);
}
