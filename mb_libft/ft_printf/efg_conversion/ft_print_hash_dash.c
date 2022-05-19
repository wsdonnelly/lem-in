/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hash_dash.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:43:19 by mbeeler           #+#    #+#             */
/*   Updated: 2022/05/19 14:46:52 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_hash_dash(t_printer *args, char *result)
{
	int	len;

	len = ft_strlen(result);
	if (args->hash == 1)
	{
		args->arg_len += write(1, ".", 1);
		len++;
	}
	while (args->width > len + args->sign)
	{
		args->arg_len += write(1, " ", 1);
		args->width--;
	}
}
