/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BFS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:29:26 by wdonnell          #+#    #+#             */
/*   Updated: 2022/09/29 19:18:42 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

/*
** Breadth-first-search algorithm to identify the shortest valid path from
** start to end.
*/


static void add_room_to_queue(t_queue *queue, int index)
{
	t_queue_node *tmp;

	tmp = malloc(sizeof(t_queue_node));
	if (!tmp)
		exit (0);
	tmp->index = index;
	tmp->next = NULL;
	if (!queue->tail)
	{
		queue->head = tmp;
		queue->tail = tmp;
		return ;
	}
	queue->tail->next = tmp;
	queue->tail = tmp;
}


//get idx
static int dequeue(t_queue *queue)
{
	t_queue_node *tmp;
	int idx;

	if (!queue->head)
		return (-1);
	tmp = queue->head;
	queue->head = queue->head->next;
	if (!queue->head)
		queue->tail = NULL;
	idx = tmp->index;
	free(tmp);
	return (idx);
}

void init_visited(t_data *data, t_room *graph)
{
	int i;

	i = 0;
	while (i < data->num_rooms)
		graph[i++].visited = 0;
}

//search directly in graph using index values
//set augmented path as true or false and sets previous
void	flow_bfs(t_data *data, t_room *graph)
{
	t_edge *temp;
	t_queue queue;
	int cur_idx;
	
	queue.head = NULL;
	queue.tail = NULL;
	init_visited(data, graph);
	data->flow_path = 0;
	cur_idx = data->start_index;

	add_room_to_queue(&queue, cur_idx);
	graph[cur_idx].visited = 1;
	graph[cur_idx].previous_idx = -1;
	graph[cur_idx].previous_edge = NULL;

	while (queue.head)
	{
		cur_idx = dequeue(&queue);
		if (cur_idx == data->end_index)
		{
			data->flow_path = 1;
			//data->shortest_path = 1;
			//would getting rid of this free the Q?
			break ;
		}
		temp = graph[cur_idx].neighbors;
		while (temp)
		{
			if (!graph[temp->next_room_index].visited && temp->res_capacity > 0)
			{
					graph[temp->next_room_index].visited = 1;
					add_room_to_queue(&queue, temp->next_room_index);
					graph[temp->next_room_index].previous_idx = cur_idx;
					graph[temp->next_room_index].previous_edge = temp;
			}
			temp = temp->next;
		}
	}
}

void	path_bfs(t_data *data, t_room *graph)
{
	t_edge *temp;
	t_queue queue;
	int cur_idx;
	
	queue.head = NULL;
	queue.tail = NULL;
	init_visited(data, graph);
	data->shortest_path = 0;
	cur_idx = data->start_index;

	add_room_to_queue(&queue, cur_idx);
	graph[cur_idx].visited = 1;
	graph[cur_idx].previous_idx = -1;
	graph[cur_idx].previous_edge = NULL;

	while (queue.head)
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
				add_room_to_queue(&queue, temp->next_room_index);
				graph[temp->next_room_index].previous_idx = cur_idx;
				graph[temp->next_room_index].previous_edge = temp;
			}
			temp = temp->next;
		}
	}
}