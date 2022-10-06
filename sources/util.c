/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:07:34 by wdonnell          #+#    #+#             */
/*   Updated: 2022/10/06 14:47:11 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	exit_error(t_data *data, char *message)
{
	free_graph(data->graph, data);
	free_data(data);
	ft_printf("%s\n", message);
	exit (EXIT_FAILURE);
}

int	is_valid_int(char *num)
{
	int		i;
	long	val;

	i = 0;
	val = 0;
	if (num[i] == '-')
		return (0);
	if (num[i] == '+')
		i++;
	while (num[i])
	{
		if (ft_isdigit(num[i]))
			val = (val * 10) + num[i] - '0';
		else
			return (0);
		i++;
	}
	if (val > INT_MAX)
		return (0);
	return (1);
}
