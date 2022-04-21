/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:58:44 by wdonnell          #+#    #+#             */
/*   Updated: 2022/02/14 12:03:57 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_prefix_hex_uppper(t_pformat *cur, unsigned long long n)
{
	if (n != 0)
	{
		if (cur->flags & HASH)
			write(1, "0X", 2);
	}
}

static void	print_precision_hex_uppper(t_pformat *cur, unsigned long long n)
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
	ft_putnbr_base(n, 16, 1);
}

static void	left_align_hex_uppper(t_pformat *cur, unsigned long long n, \
int base_len)
{
	if (cur->field_width > base_len)
	{
		print_prefix_hex_uppper(cur, n);
		print_precision_hex_uppper(cur, n);
		cur->length += write_char(' ', cur->field_width - base_len);
		cur->length = cur->field_width;
		return ;
	}
	print_prefix_hex_uppper(cur, n);
	print_precision_hex_uppper(cur, n);
	if (cur->flags & HASH && n != 0)
		cur->length += 2;
}

static void	right_align_hex_uppper(t_pformat *cur, unsigned long long n, \
int base_len)
{
	if (cur->field_width > base_len)
	{
		if ((cur->flags & ZERO) && !(cur->flags & DOT))
		{
			print_prefix_hex_uppper(cur, n);
			write_char('0', cur->field_width - base_len);
			print_precision_hex_uppper(cur, n);
			cur->length = cur->field_width;
			return ;
		}
		else
			write_char(' ', cur->field_width - base_len);
		print_prefix_hex_uppper(cur, n);
		print_precision_hex_uppper(cur, n);
		cur->length = cur->field_width;
		return ;
	}
	print_prefix_hex_uppper(cur, n);
	print_precision_hex_uppper(cur, n);
	if (cur->flags & HASH && n != 0)
		cur->length += 2;
}

void	print_hex_upper(t_pformat *cur, va_list ap)
{
	unsigned long long	n;
	int					base_len;

	get_modifier_u(cur, ap, &n);
	cur->length = num_digits_base(n, 16, 0);
	base_len = cur->length;
	if (cur->precision > base_len)
		base_len = cur->precision;
	if (n != 0 && (cur->flags & HASH))
		base_len += 2;
	if (n == 0 && (cur->flags & DOT) && !cur->precision)
		base_len = 0;
	if (cur->flags & MINUS)
		left_align_hex_uppper(cur, n, base_len);
	else
		right_align_hex_uppper(cur, n, base_len);
}
