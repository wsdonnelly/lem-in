/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_shortest_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:49:06 by jjuntune          #+#    #+#             */
/*   Updated: 2022/09/19 13:26:59 by wdonnell         ###   ########.fr       */
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
	//get rid of this!
	//tmp->name = ft_strdup(name);
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

static void init_visited(t_data *data, t_room *graph)
{
	int i;

	i = 0;
	while (i < data->num_rooms)
		graph[i++].visited = 0;
}

//search directly in graph using index values

void	find_shortest_path(t_data *data, t_room *graph)
{
	t_edge *temp;
	t_queue queue;

	queue.head = NULL;
	queue.tail = NULL;
	int cur_idx;
	//remove


	init_visited(data, graph);
	data->augmented_path = 0;
	data->shortest_path = NULL;
	//rename add_room_to_queue
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
			data->augmented_path = 1;
			break ;
		}
	
		temp = graph[cur_idx].neighbors;
		while (temp)
		{
			if (!graph[temp->next_room_index].visited && temp->capacity)
			{
				graph[temp->next_room_index].visited = 1;
				add_room_to_queue(&queue, temp->next_room_index);
				graph[temp->next_room_index].previous_idx = cur_idx;
				graph[temp->next_room_index].previous_edge = temp;
			}
			temp = temp->next;
		}
	}
	//free_path(&data->queue);
	//free_path(&data->visited);
}
