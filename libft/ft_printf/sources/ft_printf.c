/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 22:01:07 by wdonnell          #+#    #+#             */
/*   Updated: 2022/02/16 12:38:28 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_pformat(t_pformat *cur)
{
	cur->flags = 0;
	cur->field_width = 0;
	cur->precision = 0;
	ft_bzero(&cur->length_modifier, sizeof(char) * 3);
	cur->length = 0;
}

static int	find_format(va_list ap, const char *format, t_pformat *cur)
{
	int	j;
	int	i;

	init_pformat(cur);
	j = 0;
	i = 0;
	get_format_data(format, cur, &j, ap);
	i = ft_strchr_i("%cspdibouxXfB", (int)format[j]);
	if (i >= 0)
	{
		g_dispatch[i](cur, ap);
		return (++j);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	int			total;
	t_pformat	cur;

	va_start(ap, format);
	i = 0;
	total = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i += find_format(ap, &format[i + 1], &cur) + 1;
			total += cur.length;
			if (cur.flags & COLOR)
			{
				total += 9;
				ft_putstr(EOC);
			}
		}
		else
			total += write(1, &format[i++], 1);
	}
	va_end(ap);
	return (total);
}
