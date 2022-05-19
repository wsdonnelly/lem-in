/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round_string_inplace.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:43:19 by mbeeler           #+#    #+#             */
/*   Updated: 2022/03/04 15:23:20 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_round_up(char **number, int len)
{
	char	*number_tmp;
	int		found_result;

	found_result = 0;
	while (found_result == 0 && len-- > 0)
	{
		if (*(*number + len) == '.')
			len--;
		if (*(*number + len) == '9')
			*(*number + len) = '0';
		else
		{
			*(*number + len) += 1;
			found_result = 1;
		}
	}
	if (found_result == 0)
	{
		number_tmp = *number;
		*number = ft_strjoin("1", number_tmp);
		ft_strdel(&number_tmp);
	}
}

void	ft_round_string_inplace(char **num)
{
	int		len;
	char	*number;

	number = ft_strdup(*num);
	ft_strdel(num);
	len = ft_strlen(number) - 1;
	if (number[len] >= '5')
		ft_round_up(&number, len);
	len = ft_strlen(number) - 1;
	if (number[len - 1] == '.')
		*num = ft_strndup(number, len - 1);
	else
		*num = ft_strndup(number, len);
	ft_strdel(&number);
}
