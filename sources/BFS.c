/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BFS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:29:26 by wdonnell          #+#    #+#             */
/*   Updated: 2022/10/05 16:09:33 by wdonnell         ###   ########.fr       */
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

static int	*create_queue(t_data *data)
{
	int *arr;

	arr = (int *)malloc(sizeof(int) * data->size);
	if (!arr)
		exit (0);
	return (arr);
}

void	flow_bfs(t_data *data, t_room *graph)
{
	t_edge	*temp;
	t_queue	queue;
	int			cur_idx;

	queue.head = 0;
	queue.tail = -1;
	
	queue.queue = create_queue(data);
	
	init_visited(data, graph);
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
			data->flow_path = 1;
			data->shortest_path = 1;
			//would getting rid of this free the Q?
			break ;
		}
		temp = graph[cur_idx].neighbors;
		while (temp)
		{
			if (!graph[temp->next_room_index].visited && !temp->flow)
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


void	path_bfs(t_data *data, t_room *graph)
{
	t_edge	*temp;
	t_queue	queue;
	int			cur_idx;

	queue.head = 0;
	queue.tail = -1;

	queue.queue = create_queue(data);

	init_visited(data, graph);
	data->shortest_path = 0;
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
			data->shortest_path = 1;
			//would getting rid of this free the Q?
			break ;
		}
		temp = graph[cur_idx].neighbors;
		while (temp)
		{
			if (!graph[temp->next_room_index].visited && temp->flow && !graph[temp->next_room_index].in_path)
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
