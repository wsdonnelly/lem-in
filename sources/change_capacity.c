/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_capacity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:21:17 by wdonnell          #+#    #+#             */
/*   Updated: 2022/09/29 17:21:00 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void create_path_group(t_data *data)
{
	t_path_group *tmp;
	t_path_group *last;

	tmp = malloc(sizeof(t_path_group));
	if (!tmp)
		exit(0);
	tmp->min_lines = 0;
	tmp->paths = NULL;
	tmp->next_path_group = NULL;
	last = data->path_group;
	if (!data->path_group)
		data->path_group = tmp;
	else
	{
		while (last->next_path_group)
			last = last->next_path_group;
		last->next_path_group = tmp;
	}
}

void create_path_set(t_data *data, t_queue_node *path_to_add, int steps)
{
		t_path_set *tmp_path;
		t_path_set *last;
		t_path_group *cur;

	//create path * on path_set. ADD the end of list
	tmp_path = malloc(sizeof(t_path_set));
	if (!tmp_path)
			exit(0);
	tmp_path->path = path_to_add;
	tmp_path->steps = steps;
	tmp_path->ants_on_path = 0;
	tmp_path->lines = 0;
	tmp_path->next_path = NULL;

	//find current end of path group
	cur = data->path_group;
	while (cur->next_path_group)
		cur = cur->next_path_group;

	last = cur->paths;
	if (!cur->paths)
		cur->paths = tmp_path;
	else
	{
		while (last->next_path)
			last = last->next_path;
		last->next_path = tmp_path;
	}

/*
	last = data->path_set;
	if (!data->path_set)
		data->path_set = tmp_path;
	else
	{
		while (last->next_path)
			last = last->next_path;
		last->next_path = tmp_path;
	}
*/
}

static void add_room_to_stack(int index, t_data *data, int *count)
{
	t_queue_node *tmp;

	tmp = malloc(sizeof(t_queue_node));
	if(!tmp)
		exit(0);
	(*count)++;
	tmp->index = index;
	tmp->next = data->cur_path;
	data->cur_path = tmp;
}

/*
static void filter_rooms(t_data *data, t_room *graph, int idx, char *prev, int *count)
{
	int len;

	//it doesnt matter changing the name in the graph because program only referenceces index 
	len = ft_strlen(graph[idx].name);
	if (graph[idx].name[len - 1] == 'I' || graph[idx].name[len - 1] == 'O')
		graph[idx].name[len - 1] = '\0';
	if (ft_strcmp(prev, graph[idx].name))
		add_room_to_stack(idx, data, count);
}
*/
int change_capacity(t_data *data, t_room *graph, int save, int flow)
{
	int count;

	count = 0;
	//avoid setting capacity of edge connecting end to 0;
	int idx = graph[data->end_index].previous_idx;
	//char *prev = graph[data->end_index].name;
	data->cur_path = NULL;
	if (save)
		add_room_to_stack(data->end_index, data, &count);
	while (graph[idx].previous_idx >= 0)
	{
		if (save)
			//filter_rooms(data, graph, idx, prev, &count);
			add_room_to_stack(idx, data, &count);
		if (flow)
		{
			graph[idx].previous_edge->flow = 1;
			graph[idx].previous_edge->reverse_edge->flow = 0;
			//graph[idx].previous_edge->reverse_edge->flow = 1;

		}
		else
		{
			if(idx != data->end_index)
				graph[idx].in_path = 1;
		}
		
		idx = graph[idx].previous_idx;
	}
	return (count);
}
