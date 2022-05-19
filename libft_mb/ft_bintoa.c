/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bintoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:43:19 by mbeeler           #+#    #+#             */
/*   Updated: 2022/03/04 15:39:08 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_bin_minus_10(char *number_bin, char *div_ten, int *load, int i)
{
	int	j;

	j = 4;
	while (--j >= 0)
	{
		if (number_bin[i + j] < div_ten[j] && *load == 0)
		{
			number_bin[i + j] = '1';
			*load = 1;
		}
		else if (number_bin[i + j] == '1' && div_ten[j] == '1'
			&& *load == 0)
			number_bin[i + j] = '0';
		else if (number_bin[i + j] > div_ten[j] && *load == 1)
		{
			number_bin[i + j] = '0';
			*load = 0;
		}
		else if (number_bin[i + j] == '0' && div_ten[j] == '0'
			&& *load == 1)
			number_bin[i + j] = '1';
	}
}

static void	ft_divide_bin_by_10(char *number_bin, char *reminder, int len)
{
	char	div_ten_str[5];
	int		i;
	int		load;

	div_ten_str[0] = '0';
	div_ten_str[1] = '1';
	div_ten_str[2] = '0';
	div_ten_str[3] = '1';
	div_ten_str[4] = '\0';
	i = -1;
	while (++i < len)
	{
		load = 0;
		if (ft_strcmp(number_bin + i, div_ten_str) >= 0)
		{
			reminder[i] = '1';
			ft_bin_minus_10(number_bin, div_ten_str, &load, i);
		}
	}
}

static void	ft_add_digit_to_num(char **number, char **number_bin, char **rem)
{
	char	*number_tmp;
	char	digit[2];

	if (!*number)
	{
		*number = ft_strnew(1);
		**number = ft_bintolu(*number_bin) + '0';
	}
	else
	{
		number_tmp = *number;
		digit[0] = ft_bintolu(*number_bin) + '0';
		digit[1] = '\0';
		*number = ft_strjoin(digit, number_tmp);
		ft_strdel(&number_tmp);
	}
	ft_strdel(number_bin);
	*number_bin = ft_strtrim_char_left(*rem, '0');
	ft_strdel(rem);
	ft_strpad_left_inplace(number_bin, '0', 1);
}

static void	ft_add_final_numbers(char **number, char **number_bin)
{
	char	*number_tmp;
	char	*converted_number;

	number_tmp = *number;
	converted_number = ft_lutoa(ft_bintolu(*number_bin + 1));
	*number = ft_strjoin(converted_number, number_tmp);
	ft_strdel(&number_tmp);
	ft_strdel(number_bin);
	ft_strdel(&converted_number);
}

char	*ft_bintoa(const char *binary)
{
	char	*number_bin;
	char	*reminder;
	char	*number;
	int		len;

	number = NULL;
	number_bin = ft_strjoin("0", binary);
	while (ft_strlen(number_bin) > 65)
	{
		len = ft_strlen(number_bin) - 4;
		reminder = ft_strnew(len);
		ft_memset(reminder, '0', len);
		ft_divide_bin_by_10(number_bin, reminder, len);
		ft_add_digit_to_num(&number, &number_bin, &reminder);
	}
	ft_add_final_numbers(&number, &number_bin);
	return (number);
}
