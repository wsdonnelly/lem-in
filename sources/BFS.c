/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BFS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:29:26 by wdonnell          #+#    #+#             */
/*   Updated: 2022/10/07 12:43:43 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	init_bfs(t_data *data, t_room *graph, t_queue *queue, int path)
{
	queue->queue = create_queue(data, queue);
	init_visited(data, graph);
	if (path)
		data->shortest_path = 0;
	else
		data->flow_path = 0;
	enqueue(queue, data->start_index);
	graph[data->start_index].visited = 1;
	graph[data->start_index].previous_idx = -1;
	graph[data->start_index].previous_edge = NULL;
}
/*
static void	check_neighbors(t_room *graph, t_queue *queue, int idx, int path)
{
	t_edge	*temp;

	temp = graph[idx].neighbors;
	while (temp)
	{
		if (!graph[temp->next_room_index].visited \
		&& ((path && (temp->flow && !graph[temp->next_room_index].in_path)) \
		|| (!path && !temp->flow)))
		{
			graph[temp->next_room_index].visited = 1;
			enqueue(queue, temp->next_room_index);
			graph[temp->next_room_index].previous_idx = idx;
			graph[temp->next_room_index].previous_edge = temp;
		}
		temp = temp->next;
	}
}
*/
static void	check_neighbors(t_room *graph, t_queue *queue, int idx, int path, t_data *data)
{
	t_edge	*temp;

	temp = graph[idx].neighbors;
	while (temp)
	{
		if (!graph[temp->next_room_index].visited)
		{
			if (!path && !temp->flow)
			{
				graph[temp->next_room_index].visited = 1;
				enqueue(queue, temp->next_room_index);
				graph[temp->next_room_index].previous_idx = idx;
				graph[temp->next_room_index].previous_edge = temp;
			}
			else if (path && !graph[temp->next_room_index].in_path)
			{
				if (temp->next_room_index == data->end_index && temp->is_forward)
				{
					graph[temp->next_room_index].visited = 1;
					enqueue(queue, temp->next_room_index);
					graph[temp->next_room_index].previous_idx = idx;
					graph[temp->next_room_index].previous_edge = temp;
				}
				else if(temp->flow && temp->is_forward)
				{
					graph[temp->next_room_index].visited = 1;
					enqueue(queue, temp->next_room_index);
					graph[temp->next_room_index].previous_idx = idx;
					graph[temp->next_room_index].previous_edge = temp;
				}
			}
		}
		temp = temp->next;
	}
}

void	bfs(t_data *data, t_room *graph, int path)
{
	t_queue	queue;
	int		cur_idx;

	init_bfs(data, graph, &queue, path);
	while (queue.head <= queue.tail)
	{
		cur_idx = dequeue(&queue);
		if (cur_idx == data->end_index)
		{
			if (!path)
				data->flow_path = 1;
			data->shortest_path = 1;
			break ;
		}
		check_neighbors(graph, &queue, cur_idx, path, data);
	}
	free(queue.queue);
}
