/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:27:44 by wdonnell          #+#    #+#             */
/*   Updated: 2022/09/29 15:05:45 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
static void print_path_test(t_data *data, t_room *graph)
{
	t_queue_node *tmp;
	t_path_set *tmp_path;
	
	tmp_path = data->path_set;
	
	while (tmp_path)
	{
		printf("current path:\n");
		tmp = tmp_path->path;
		printf("count in path set: %d\n", tmp_path->steps);
		while (tmp)
		{
			printf("%s ", graph[tmp->index].name);
			tmp = tmp->next;
		}
		tmp_path = tmp_path->next_path;
		printf("\n");
	}
	printf("\n");
}
*/
static void print_path_test(t_data *data, t_room *graph)
{
	t_queue_node *tmp;
	t_path_set *tmp_path;
	t_path_group *cur_group;
	
	cur_group = data->path_group;
	while (cur_group)
	{
		tmp_path = cur_group->paths;
		printf("path_group-->>>\n");
		while (tmp_path)
		{
			//printf("current path:\n");
			tmp = tmp_path->path;
			printf("count in path set: %d\n", tmp_path->steps);
			while (tmp)
			{
				printf("%s ", graph[tmp->index].name);
				tmp = tmp->next;
			}
			tmp_path = tmp_path->next_path;
			printf("\n");
		}
		cur_group = cur_group->next_path_group;
	}
	printf("\n");
}
/*
static int potential_flow(t_data *data, t_room *graph)
{
	int count;
	t_edge *tmp_start;
	t_edge *tmp_end;

	count = 0;
	tmp_start = graph[data->start_index].neighbors;
	tmp_end = graph[data->end_index].neighbors;
	while (tmp_start && tmp_end)
	{
		count++;
		tmp_start = tmp_start->next;
		tmp_end = tmp_end->next;
	}
	return (count / 2);
}
*/

/*
static void reset_capacities(t_data *data, t_room *graph)
{
	int i;
	t_edge *tmp;

	i = 0;
	while (i < data->size)
	{
		tmp = graph[i].neighbors;
		while (tmp)
		{
			tmp->capacity = 1;
			tmp = tmp->next;
		}
		i++;
	}

}
*/
static void init_in_path(t_data *data, t_room *graph)
{
	int i;

	i = 0;
	while (i < data->size)
		graph[i].in_path = 0;
}
//change_capacity(data, graph, SAVE, FLOW)

void	solve(t_data *data, t_room *graph)
{
	int steps;

	data->path_group = NULL;
	data->path_set = NULL;

	while (data->flow_path)
	{
		flow_bfs(data, graph);
		if (data->flow_path)
		{
			printf("found a flow\n");
			change_capacity(data, graph, FALSE, TRUE);
			create_path_group(data);
			while (data->shortest_path)
			{
				path_bfs(data, graph);
				if (data->shortest_path)
				{
					steps = change_capacity(data, graph, TRUE, FALSE);
					create_path_set(data, data->cur_path, steps);
				}
			}
		}
		init_in_path(data, graph);
	}
	print_path_test(data, graph);
}

/*
void	solve(t_data *data, t_room *graph)
{
	//int i;
	//int try = 1;
	int steps;

	data->path_group = NULL;
	data->path_set = NULL;

	while (data->flow_path)
	{
		printf("in flow zone\n");
		flow_bfs(data, graph);
		if (data->flow_path)
		{
			change_capacity(data, graph, TRUE, TRUE);
			//check flows
			steps = change_capacity(data, graph, TRUE);
			create_path_group(data);
			create_path_set(data, data->cur_path, steps);
			
			create_path_group(data);
			while (data->shortest_path)
			{
				path_bfs(data, graph);
				if (data->shortest_path)
				{
					steps = change_capacity(data, graph, TRUE, FALSE);
					create_path_set(data, data->cur_path, steps);
				}
			}
		}
		init_in_path(data, graph);
	}

	print_path_test(data, graph);
	
}
*/