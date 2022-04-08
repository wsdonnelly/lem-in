/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:54:29 by wdonnell          #+#    #+#             */
/*   Updated: 2022/02/11 13:42:05 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* put str to designated length, return that length
*/

int	ft_putstr_len(char const *s, int len)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	if (!s)
		return (0);
	while (i < len && s[i])
	{
		ft_putchar(s[i++]);
		n++;
	}
	return (n);
}
