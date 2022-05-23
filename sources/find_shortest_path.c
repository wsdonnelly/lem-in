/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_shortest_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:49:06 by jjuntune          #+#    #+#             */
/*   Updated: 2022/05/23 12:41:16 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	finish_breadth_search(t_data *data, t_room *graph)
{
	data->augmented_path = 1;
	graph[data->neighbor->next_room_index].previous = data->queue->room->name;
}

static int	has_been_visited(t_edge *neighbor, t_path *visited, t_room *graph)
{
	t_path	*tmp;

	tmp = visited;
	while (tmp)
	{
		if (!ft_strcmp(tmp->room->name, graph[neighbor->next_room_index].name))
			return (1);
		tmp = tmp->next_room;
	}
	return (0);
}

static void	add_room_to_queue_and_visited_list(t_data *data, t_room *graph)
{
	add_room_to_path(&graph[data->neighbor->next_room_index], &data->queue);
	add_room_to_path(&graph[data->neighbor->next_room_index], &data->visited);
	graph[data->neighbor->next_room_index].previous = data->queue->room->name;
}

static void	remove_first_room_from_queue(t_path **path)
{
	t_path	*tmp;

	tmp = *path;
	*path = tmp->next_room;
	free(tmp);
}

/*
** Breadth-first-search algorithm to identify the shortest valid path from
** start to end.
*/
void	find_shortest_path(t_data *data, t_room *graph)
{
	data->queue = NULL;
	data->visited = NULL;
	data->shortest_path = NULL;
	data->augmented_path = 0;
	add_room_to_path(&graph[data->start_index], &data->queue);
	add_room_to_path(&graph[data->start_index], &data->visited);
	while (data->queue && !data->augmented_path)
	{
		data->neighbor = data->queue->room->neighbors;
		while (data->neighbor && !data->augmented_path)
		{
			if (data->neighbor->capacity
				&& data->neighbor->next_room_index == data->end_index)
				finish_breadth_search(data, graph);
			else if (data->neighbor->capacity
				&& !has_been_visited(data->neighbor, data->visited, graph))
				add_room_to_queue_and_visited_list(data, graph);
			data->neighbor = data->neighbor->next;
		}
		remove_first_room_from_queue(&data->queue);
	}
	free_path(&data->queue);
	free_path(&data->visited);
}
