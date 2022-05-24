/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_extras.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:17:30 by wdonnell          #+#    #+#             */
/*   Updated: 2022/05/24 12:24:34 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
* activate a flag siginfying the "start" or "end" has been found
* if the next line is valid set as "end" or "start" and deactivte flag
*/

void	get_start_end(t_data *data, char *line)
{
	if (data->start_index == -1 || data->end_index == -1)
		exit_error(data, "ERROR");
	if (!ft_strcmp("##start", line))
	{
		data->start_index = -1;
		store_data(data, line);
	}
	else if (!ft_strcmp("##end", line))
	{
		data->end_index = -1;
		store_data(data, line);
	}
}

/*
* check links for errors
*/

void	check_links(t_parse *parse, t_data *data, t_room **graph)
{
	parse->room_check = TRUE;
	if (data->start_index == -1 || data->end_index == -1 \
	|| !data->end || !data->start)
		exit_error(data, "ERROR");
	if (!parse->flag)
		make_graph(&parse->flag, data, graph);
	add_to_graph(data, parse->line);
}
