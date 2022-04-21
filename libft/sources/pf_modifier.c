/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifier.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:55:06 by wdonnell          #+#    #+#             */
/*   Updated: 2022/02/08 18:05:40 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_modifier_s(t_pformat *cur, va_list ap, long long *nb)
{
	if (cur->length_modifier[0] == 'l')
	{
		if (cur->length_modifier[1] == 'l')
			*nb = va_arg(ap, long long);
		else
			*nb = (long long)va_arg(ap, long);
	}
	else if (cur->length_modifier[0] == 'h')
	{
		if (cur->length_modifier[1] == 'h')
			*nb = (char)va_arg(ap, int);
		else
			*nb = (short)va_arg(ap, int);
	}
	else
		*nb = (long long)va_arg(ap, int);
}

void	get_modifier_u(t_pformat *cur, va_list ap, unsigned long long *nb)
{
	if (cur->length_modifier[0] == 'l')
	{
		if (cur->length_modifier[1] == 'l')
			*nb = va_arg(ap, unsigned long long);
		else
			*nb = (unsigned long long)va_arg(ap, unsigned long);
	}
	else if (cur->length_modifier[0] == 'h')
	{
		if (cur->length_modifier[1] == 'h')
			*nb = (unsigned char)va_arg(ap, unsigned int);
		else
			*nb = (unsigned short)va_arg(ap, unsigned int);
	}
	else
		*nb = (unsigned long long)va_arg(ap, unsigned int);
}
