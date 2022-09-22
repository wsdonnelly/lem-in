/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_capacity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:21:17 by wdonnell          #+#    #+#             */
/*   Updated: 2022/09/22 16:03:32 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
static void add_room_to_stack(int index, t_data *data)
{
	t_queue_node *tmp;

	tmp = malloc(sizeof(t_queue_node));
	if(!tmp)
		exit(0);
	tmp->index = index;
	tmp->next = data->cur_path;
	data->cur_path = tmp;
}
*/
void create_path_set(t_data *data, t_queue_node *path_to_add)
{
		t_path_set *tmp_path;
		t_path_set *last;

	//create path * on path_set. ADD the end of list
	tmp_path = malloc(sizeof(t_path_set));
	if (!tmp_path)
			exit(0);
	tmp_path->path = path_to_add;
	tmp_path->next_path = NULL;
	last = data->path_set;
	if (!data->path_set)
		data->path_set = tmp_path;
	else
	{
		
		while (last->next_path)
			last = last->next_path;
		last->next_path = tmp_path;
		
	}
}

static void add_room_to_stack(int index, t_data *data)
{
	t_queue_node *tmp;

	tmp = malloc(sizeof(t_queue_node));
	if(!tmp)
		exit(0);
	tmp->index = index;
	tmp->next = data->cur_path;
	data->cur_path = tmp;
}

static void filter_rooms(t_data *data, t_room *graph, int idx, char *prev)
{
	int len;

	//it doesnt matter changing the name in the graph because program only referenceces index 
	len = ft_strlen(graph[idx].name);
	if (graph[idx].name[len - 1] == 'I' || graph[idx].name[len - 1] == 'O')
		graph[idx].name[len - 1] = '\0';
	if (ft_strcmp(prev, graph[idx].name))
		add_room_to_stack(idx, data);
}

void	change_capacity(t_data *data, t_room *graph, int save)
{
	//avoid setting capacity of edge connecting end to 0;
	int idx = graph[data->end_index].previous_idx;
	char *prev = graph[data->end_index].name;
	data->cur_path = NULL;
	if (save)
		add_room_to_stack(data->end_index, data);
	while (graph[idx].previous_idx >= 0)
	{
		if (save)
			filter_rooms(data, graph, idx, prev);
		graph[idx].previous_edge->capacity ^= 1;
		graph[idx].previous_edge->reverse_edge->capacity ^= 1;
		prev = graph[idx].name;
		idx = graph[idx].previous_idx;
	}
}
