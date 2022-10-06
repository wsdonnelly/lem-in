/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BFS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:29:26 by wdonnell          #+#    #+#             */
/*   Updated: 2022/10/06 12:07:00 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	enqueue(t_queue *queue, int index)
{
	queue->tail++;
	queue->queue[queue->tail] = index;
}

static int	dequeue(t_queue *queue)
{
	int	idx;

	idx = queue->queue[queue->head];
	queue->head++;
	return (idx);
}

static void	init_visited(t_data *data, t_room *graph)
{
	int	i;

	i = 0;
	while (i < data->size)
		graph[i++].visited = 0;
}

static int	*create_queue(t_data *data, t_queue *queue)
{
	int	*arr;

	arr = (int *)malloc(sizeof(int) * data->size);
	if (!arr)
		exit (0);
	queue->head = 0;
	queue->tail = -1;
	return (arr);
}

void	bfs(t_data *data, t_room *graph, int path)
{
	t_edge	*temp;
	t_queue	queue;
	int		cur_idx;

	queue.queue = create_queue(data, &queue);
	init_visited(data, graph);
	if (path)
		data->shortest_path = 0;
	else
		data->flow_path = 0;
	cur_idx = data->start_index;
	enqueue(&queue, cur_idx);
	graph[cur_idx].visited = 1;
	graph[cur_idx].previous_idx = -1;
	graph[cur_idx].previous_edge = NULL;
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
		temp = graph[cur_idx].neighbors;
		while (temp)
		{
			if (!graph[temp->next_room_index].visited \
			&& ((path && (temp->flow && !graph[temp->next_room_index].in_path)) \
			|| (!path && !temp->flow)))
			{
				graph[temp->next_room_index].visited = 1;
				enqueue(&queue, temp->next_room_index);
				graph[temp->next_room_index].previous_idx = cur_idx;
				graph[temp->next_room_index].previous_edge = temp;
			}
			temp = temp->next;
		}
	}
	free(queue.queue);
}
