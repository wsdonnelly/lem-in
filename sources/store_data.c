/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 09:14:32 by wdonnell          #+#    #+#             */
/*   Updated: 2022/04/28 10:57:17 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_comments(t_data *data)
{
	ft_printf("# num_rooms %d\n", data->num_rooms);
	ft_printf("# start %s\n", data->start);
	ft_printf("# end %s\n", data->end);
}

void	print_data(t_data *data)
{
	ft_putstr(data->store_input);
	free(data->store_input);
}

void	store_data(t_data *data, char *line)
{
	char	*c;

	c = strdup("\n");
	if (data->store_input)
	{
		ft_strjoin_inplace(&data->store_input, &line);
		ft_strjoin_inplace(&data->store_input, &c);
	}
	else
	{
		data->store_input = ft_strdup(line);
		free (line);
		ft_strjoin_inplace(&data->store_input, &c);
	}
}
