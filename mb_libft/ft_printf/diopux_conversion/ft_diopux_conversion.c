/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diopux_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:43:19 by mbeeler           #+#    #+#             */
/*   Updated: 2022/05/19 14:47:16 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_diopux_conversion(const char **format, t_printer *args)
{
	if (**format == 'd' || **format == 'i')
		ft_di_conversion(format, args);
	else if (**format == 'o' || **format == 'u' || **format == 'x'
		|| **format == 'X')
		ft_oux_conversion(format, args);
	else
		ft_p_conversion(format, args);
}
