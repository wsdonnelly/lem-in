/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:16:57 by wdonnell          #+#    #+#             */
/*   Updated: 2022/02/14 11:57:44 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_precision_di(t_pformat *cur, int len, long long n)
{
	if (n == 0 && (cur->flags & DOT) && !cur->precision)
		return ;
	if (cur->precision > len)
		cur->length += write_char('0', cur->precision - len);
	ft_putnbr_s(n);
}

static void	di_align_left(t_pformat *cur, int total_len, int len, long long n)
{
	int	positive;

	positive = 1;
	if (n < 0)
		positive = 0;
	if (cur->field_width > total_len)
	{
		print_prefix_signed(cur, positive);
		print_precision_di (cur, len, n);
		cur->length += write_char(' ', cur->field_width - total_len);
		return ;
	}
	print_prefix_signed(cur, positive);
	print_precision_di(cur, len, n);
}

static void	di_align_right(t_pformat *cur, int total_len, int len, long long n)
{
	int	positive;

	positive = 1;
	if (n < 0)
		positive = 0;
	if (cur->field_width > total_len)
	{
		if ((cur->flags & ZERO) && !(cur->flags & DOT))
		{
			print_prefix_signed(cur, positive);
			cur->length += write_char('0', cur->field_width - total_len);
			print_precision_di(cur, len, n);
			return ;
		}
		cur->length += write_char(' ', cur->field_width - total_len);
		print_prefix_signed(cur, positive);
		print_precision_di(cur, len, n);
		return ;
	}
	print_prefix_signed(cur, positive);
	print_precision_di(cur, len, n);
}

static void	print_field_di(t_pformat *cur, int len, long long n)
{
	int	total_len;

	if (cur->precision > len)
		total_len = cur->precision;
	else
		total_len = len;
	if (cur->field_width >= cur->precision)
		if (cur->flags & (SPACE | PLUS) || n < 0)
			total_len++;
	if (cur->flags & MINUS)
		di_align_left(cur, total_len, len, n);
	else
		di_align_right(cur, total_len, len, n);
}

void	print_di(t_pformat *cur, va_list ap)
{
	int			len;
	long long	n;

	get_modifier_s(cur, ap, &n);
	len = ft_num_digits_s(n);
	if (n == 0 && cur->flags & DOT && !cur->precision)
		len--;
	cur->length += len;
	print_field_di(cur, len, n);
}
