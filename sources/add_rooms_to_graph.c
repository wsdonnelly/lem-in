/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_rooms_to_graph.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:10:33 by wdonnell          #+#    #+#             */
/*   Updated: 2022/09/29 14:18:32 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

/*
//REDO REDO REDO
static t_edge	*add_edge(t_data *data, int index1, int index2)
{
	t_edge	**head;
	t_edge	*temp;

	head = &(*data->graph)[index1].neighbors;
	temp = *head;
	while (temp)
	{
		if (temp->next_room_index == index2 && temp->capacity == 1)
			return (NULL);
		temp = temp->next;
	}
	temp = malloc(sizeof(t_edge));
	if (!temp)
		exit_error(data, "ERROR");
	temp->next_room_index = index2;
	temp->capacity = 1;
	temp->flow = 0;
	temp->reverse_edge = NULL;
	temp->twin_edge = NULL;
	temp->next = *head;
	*head = temp;
	return (temp);
}
*/
static t_edge	*add_edge(t_data *data, t_room *graph,int index1, int index2)
{
	t_edge	*temp;

	temp = graph[index1].neighbors;
	temp = malloc(sizeof(t_edge));
	if (!temp)
		exit_error(data, "ERROR");
	temp->next_room_index = index2;
	temp->res_capacity = 1;
	temp->flow = 0;
	temp->reverse_edge = NULL;
	temp->next = graph[index1].neighbors;
	graph[index1].neighbors = temp;
	return (temp);
}

static void	add_edges(t_data *data, t_room *graph, int idx_a, int idx_b)
{
	t_edge *edge1;
	t_edge *edge2;
	

	//edge forward a -> b
	edge1 = add_edge(data, graph, idx_a, idx_b);
	//its rev edge residual b -> a 
	edge2 = add_edge(data, graph, idx_b, idx_a);
	//point between the two
	edge1->reverse_edge = edge2;
	edge2->reverse_edge = edge1;
}

void	set_rooms(char **room, t_data *data, t_room *graph)
{
	int index1;
	int index2;

	index1 = hash_map(room[0], data->num_rooms, data->graph);
	index2 = hash_map(room[1], data->num_rooms, data->graph);
	if (!ft_strcmp(room[0], data->start))
		data->start_index = index1;
	else if (!ft_strcmp(room[1], data->start))
		data->start_index = index2;
	else if (!ft_strcmp(room[0], data->end))
		data->end_index = index1;
	else if (!ft_strcmp(room[1], data->end))
		data->end_index = index2;
	add_edges(data, graph, index1, index2);
}
