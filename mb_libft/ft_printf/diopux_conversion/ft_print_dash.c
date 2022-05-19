/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dash.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:43:19 by mbeeler           #+#    #+#             */
/*   Updated: 2022/05/19 14:47:09 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_dash(t_printer *args, t_u64 n)
{
	while (args->width > args->precision2 + args->sign - args->hash
		&& args->width > args->digits + args->sign
		&& args->dash == 1)
	{
		args->arg_len += write(1, " ", 1);
		args->width--;
	}
	if (n == 0 && args->precision2 == 0 && args->dot == 1 && args->width != 0 \
		&& args->dash == 1 && args->hash2 == 0)
		args->arg_len += write(1, " ", 1);
}
