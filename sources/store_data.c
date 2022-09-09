/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 09:14:32 by wdonnell          #+#    #+#             */
/*   Updated: 2022/09/09 14:58:13 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Group of functions to store successfully read input lines in a queue
** And print (and free) them at program completion.
*/

void	print_comments(t_data *data)
{
	ft_printf("#num_rooms %d\n", data->num_rooms);
	ft_printf("#start %s\n", data->start);
	ft_printf("#end %s\n", data->end);
}

void	print_data(t_data *data)
{
	t_line	*temp;
	t_line	*cpy;

	temp = data->store_input_head;
	while (temp)
	{
		ft_putendl(temp->line);
		cpy = temp;
		temp = temp->next;
		free(cpy->line);
		free(cpy);
	}
}

void	store_data(t_data *data, char *line)
{
	t_line	*temp;

	temp = (t_line *)malloc(sizeof(t_line));
	if (!temp)
		exit_error(data, "ERROR");
	temp->line = ft_strdup(line);
	temp->next = NULL;
	if (data->store_input_tail)
	{
		*(&data->store_input_tail->next) = temp;
		*(&data->store_input_tail) = temp;
	}
	else
	{
		*(&data->store_input_head) = temp;
		*(&data->store_input_tail) = temp;
	}
	free(line);
}
