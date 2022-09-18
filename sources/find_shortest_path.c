/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_shortest_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:49:06 by jjuntune          #+#    #+#             */
/*   Updated: 2022/09/18 12:09:26 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

/*
** Breadth-first-search algorithm to identify the shortest valid path from
** start to end.
*/


static void add_room_to_queue(char *name, t_queue *queue, int index)
{
	t_queue_node *tmp;

	tmp = malloc(sizeof(t_queue_node));
	if (!tmp)
		exit (0);
	tmp->index = index;
	//get rid of this!
	tmp->name = ft_strdup(name);
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
	char *parent;

	init_visited(data, graph);
	data->augmented_path = 0;
	data->shortest_path = NULL;
	//rename add_room_to_queue
	cur_idx = data->start_index;
	add_room_to_queue(graph[data->start_index].name, &queue, cur_idx);
	graph[cur_idx].visited = 1;
	graph[cur_idx].previous = NULL;
	//remove
	while (queue.head)
	{
		cur_idx = dequeue(&queue);
		parent = ft_strdup(graph[cur_idx].name);
		//printf("PARENT: %s\n", parent);
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
				add_room_to_queue(graph[temp->next_room_index].name, &queue, temp->next_room_index);
				//update previos to be index!
				graph[temp->next_room_index].previous = ft_strdup(parent);
			}
			temp = temp->next;
		}
	}
	//free_path(&data->queue);
	//free_path(&data->visited);
}

/*
void	find_shortest_path(t_data *data, t_room *graph)
{
	int i;
	int temp;
	init_visited(data, graph);
	data->queue = NULL;
	//data->visited = NULL;
	data->shortest_path = NULL;
	data->augmented_path = 0;
	//rename add_room_to_queue
	i = data->start_index;
	add_room_to_path(&graph[i], &data->queue);
	//add_room_to_path(&graph[data->start_index], &data->visited);
	while (data->queue && !data->augmented_path)
	{
		
		//graph[i] = graph[i].neighbors->next_room_index;
		//data->neighbor = data->queue->room->neighbors;
		//while (data->neighbor && !data->augmented_path)
		while (graph[i].neighbors && !data->augmented_path)
		{
			printf("HERE\n");
			//if (data->neighbor->capacity
				if(graph[i].neighbors->capacity
				&& graph[i].neighbors->next_room_index == data->end_index)
				finish_breadth_search(data, graph);
			else if (graph[i].neighbors->capacity
				//&& !has_been_visited(data->neighbor, data->visited, graph))
				//&& !has_been_visited(data->neighbor, graph))
				&& !graph[graph[i].neighbors->next_room_index].visited)
				add_room_to_queue_and_visited_list(data, graph, i);

			//data->neighbor = data->neighbor->next;
			//i = graph[i].neighbors->next_room_index;
			temp = i;
			graph[i].neighbors = graph[i].neighbors->next;
			i = graph[temp].neighbors->next_room_index;
		}
		remove_first_room_from_queue(&data->queue);
	}
	free_path(&data->queue);
	free_path(&data->visited);
}
*/
/*
	//testing
		t_queue_node *test;
		test = queue.tail;
		while(test)
		{
			printf("%s ", test->name);
			test = test->next;
		}
		printf("\n");
	*/