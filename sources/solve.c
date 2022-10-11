/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:27:44 by wdonnell          #+#    #+#             */
/*   Updated: 2022/10/11 16:23:56 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	init_in_path(t_data *data, t_room *graph)
{
	int	i;

	i = 0;
	while (i < data->size)
		graph[i++].in_path = 0;
}

static void	filter_all_rooms(t_data *data, t_room *graph)
{
	int	len;
	int	i;

	i = 0;
	while (i < data->size)
	{
		if (graph[i].name)
		{
			len = ft_strlen(graph[i].name);
			if (graph[i].name[len - 1] == 'I' || graph[i].name[len - 1] == 'O')
				graph[i].name[len - 1] = '\0';
		}
		i++;
	}
}

/*
* change_capacity(data, graph, SAVE?, FLOW?)
* bfs(data, graph, PATH?)
*/

void	solve(t_data *data, t_room *graph)
{
	int	steps;

	data->path_group = NULL;
	filter_all_rooms(data, graph);
	while (data->flow_path)
	{
		bfs(data, graph, FALSE);
		if (data->flow_path)
		{
			change_capacity(data, graph, FALSE, TRUE);
			create_path_group(data);
			init_in_path(data, graph);
			while (data->shortest_path)
			{
				printf("herdfdfger\n");
				bfs(data, graph, TRUE);
				if (data->shortest_path)
				{
					steps = change_capacity(data, graph, TRUE, FALSE);
					create_path_set(data, data->cur_path, steps);
				}
			}
		}
	}
}
