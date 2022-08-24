/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:43:15 by manuelbeele       #+#    #+#             */
/*   Updated: 2021/11/19 15:44:59 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char *str)
{
	int		words;
	int		i;

	i = 1;
	words = 1;
	if (str[0] == ' ' || str[0] == '\n' || \
		str[0] == '\t' || str[0] == '\v')
		words = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\n' && \
			str[i] != '\t' && str[i] != '\v')
		{
			if (str[i - 1] == ' ' || str[i - 1] == '\n' \
			|| str[i - 1] == '\t' || str[i - 1] == '\v')
				words += 1;
		}
		i++;
	}
	return (words);
}

static int	start_word(char *str, int i)
{
	if (i == 0)
	{
		i++;
		if (str[i - 1] != ' ' && str[i - 1] != '\n' && \
			str[i - 1] != '\t' && str[i - 1] != '\v')
			return (i);
	}
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\n' && \
			str[i] != '\t' && str[i] != '\v')
		{
			if (str[i - 1] == ' ' || str[i - 1] == '\n' || \
				str[i - 1] == '\t' || str[i - 1] == '\v')
				return (i + 1);
		}
		i++;
	}
	return (0);
}

static int	end_word(char *str, int i)
{
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\n' && \
			str[i] != '\t' && str[i] != '\v')
		{
			if (str[i + 1] == ' ' || str[i + 1] == '\n' || \
				str[i + 1] == '\t' || str[i + 1] == '\v')
				return (i + 1);
		}
		i++;
	}
	return (i);
}

static char	*add_words(char *str, int start, int end)
{
	int		length;
	char	*string;
	int		i;

	i = 0;
	length = end - start + 1;
	string = (char *)malloc(sizeof(string) * (length));
	while (start <= end)
	{
		string[i] = str[start - 1];
		i++;
		start++;
	}
	string[i] = '\0';
	return (string);
}

char	**ft_split_whitespaces(char *str)
{
	char	**array;
	int		words;
	int		cur_word;
	int		start;
	int		end;

	cur_word = 0;
	start = 0;
	end = 0;
	words = count_words(str);
	array = (char **)malloc(sizeof(char *) * words);
	if (array == 0)
		return (array);
	while (cur_word < words)
	{
		start = start_word(str, start);
		end = end_word(str, end);
		array[cur_word] = add_words(str, start, end);
		cur_word++;
	}
	array[cur_word] = 0;
	return (array);
}
