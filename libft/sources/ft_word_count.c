/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:30:52 by wdonnell          #+#    #+#             */
/*   Updated: 2022/02/22 12:00:21 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_word_count(const char *str, char d)
{
	int		flag;
	int		i;
	int		wc;

	i = 0;
	wc = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == d)
		{
			flag = 0;
			i++;
		}
		while (str[i] != '\0' && str[i] != d)
		{
			flag = 1;
			i++;
		}
		if (flag == 1)
			wc++;
	}
	return (wc);
}
