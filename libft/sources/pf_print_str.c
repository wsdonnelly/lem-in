/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:43:54 by wdonnell          #+#    #+#             */
/*   Updated: 2022/02/14 11:58:45 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	str_align_left(t_pformat *cur, char *str)
{
	if (cur->flags & DOT)
		cur->length += ft_putstr_len(str, cur->precision);
	else
		cur->length += ft_putstr_len(str, cur->precision);
	if (cur->field_width > cur->precision)
		cur->length += write_char(' ', cur->field_width - cur->precision);
	return ;
}

static void	str_align_right(t_pformat *cur, char *str)
{
	if (cur->flags & DOT && cur->field_width)
	{
		cur->length += write_char(' ', cur->field_width - cur->precision);
		cur->length += ft_putstr_len(str, cur->precision);
		return ;
	}
	else if (cur->flags & DOT)
	{
		cur->length += ft_putstr_len(str, cur->precision);
		return ;
	}
	if (cur->field_width > cur->precision)
		cur->length += write_char(' ', cur->field_width - cur->precision);
	cur->length += ft_putstr_len(str, cur->precision);
}

void	print_str(t_pformat *cur, va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	if (cur->precision > (int)ft_strlen(str) || !(cur->flags & DOT))
		cur->precision = (int)ft_strlen(str);
	if (cur->flags & MINUS)
		str_align_left(cur, str);
	else
		str_align_right(cur, str);
}
