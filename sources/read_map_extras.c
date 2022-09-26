/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_extras.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:17:30 by wdonnell          #+#    #+#             */
/*   Updated: 2022/09/26 21:15:55 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
* create and init graph array
*/

static t_room	*malloc_graph(t_data *data)
{
	//int		size;
	int		i;
	t_room	*temp;

	temp = (t_room *)malloc(sizeof(t_room) * data->num_rooms);
	if (!temp)
		exit_error(data, "ERROR");
	i = 0;
	while (i < data->num_rooms)
	{
		temp[i].name = NULL;
		temp[i].neighbors = NULL;
		i++;
	}
	return (temp);
}

/*
* check that graph is only malloc'd once
*/

static void	make_graph(int *flag, t_data *data, t_room **graph)
{
	*graph = malloc_graph(data);
	*flag = TRUE;
}

/*
* check links for errors
*/

void	check_links(t_parse *parse, t_data *data, t_room **graph)
{
	parse->room_check = TRUE;
	if (data->start_index == -1 || data->end_index == -1 \
	|| !data->end || !data->start)
	{
		free(parse->line);
		exit_error(data, "ERROR");
	}
	if (!parse->flag)
		make_graph(&parse->flag, data, graph);
	add_to_graph(data, parse->line);
}
