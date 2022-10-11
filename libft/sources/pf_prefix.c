/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:38:43 by wdonnell          #+#    #+#             */
/*   Updated: 2022/02/11 13:29:31 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_prefix_signed(t_pformat *cur, int positive)
{
	if (positive)
	{
		if (cur->flags & PLUS)
		{
			cur->length += write(1, "+", 1);
			return ;
		}
		else if (cur->flags & SPACE)
			cur->length += write(1, " ", 1);
	}
	else
		cur->length += write(1, "-", 1);
}
