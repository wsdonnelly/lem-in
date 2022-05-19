/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:43:19 by mbeeler           #+#    #+#             */
/*   Updated: 2022/03/04 15:19:27 by manuelbeele      ###   ########.fr       */
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

char	*ft_round_string(const char *num)
{
	int		len;
	char	*number_tmp;
	char	*number;

	number = ft_strdup(num);
	len = ft_strlen(number) - 1;
	if (number[len] >= '5')
		ft_round_up(&number, len);
	number_tmp = number;
	len = ft_strlen(number_tmp) - 1;
	if (number_tmp[len - 1] == '.')
		number = ft_strndup(number_tmp, len - 1);
	else
		number = ft_strndup(number_tmp, len);
	ft_strdel(&number_tmp);
	return (number);
}
