/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:27:44 by wdonnell          #+#    #+#             */
/*   Updated: 2022/09/29 18:41:14 by wdonnell         ###   ########.fr       */
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
			//printf("count in path set: %d\n", tmp_path->steps);
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

static void reset_in_path(t_data *data, t_room *graph)
{
	int i;

	i = 0;
	while (i < data->num_rooms)
		graph[i++].in_path = 0;
}

//change cap (data, graph, SAVE, FLOW)
void	solve(t_data *data, t_room *graph)
{
	int steps;

	data->path_group = NULL;
	data->path_set = NULL;
	data->flow_path = 1;

	while(data->flow_path)
	{
		
		flow_bfs(data, graph);
		if (data->flow_path)
		{
			change_capacity(data, graph, FALSE, TRUE);
			data->shortest_path = 1;
			create_path_group(data);
			while (data->shortest_path)
			{
				printf("here\n");
				path_bfs(data, graph);
				if (data->shortest_path)
				{
					steps = change_capacity(data, graph, TRUE, FALSE);
					create_path_set(data, data->cur_path, steps);
				}
			}
			reset_in_path(data, graph);
		}
	}
	print_path_test(data, graph);
}

/*
void	solve(t_data *data, t_room *graph)
{
	int steps;

	data->path_group = NULL;
	data->path_set = NULL;
	data->flow_path = 1;

	while(data->flow_path)
	{
		flow_bfs(data, graph);
		if (data->flow_path)
		{
			printf("found a flow path...\n");
			steps = change_capacity(data, graph, FALSE, TRUE);
			//create_path_group(data);
			//create_path_set(data, data->cur_path, steps);
		//	print_path_test(data, graph);
			//print_graph_test(graph, data);
			data->shortest_path = 1;
			create_path_group(data);
			while (data->shortest_path)
			{
				path_bfs(data, graph);
				if (data->shortest_path)
				{
					printf("found a shortest path...\n");
					steps = change_capacity(data, graph, TRUE, FALSE);
					create_path_set(data, data->cur_path, steps);
				}
			}
			reset_in_path(data, graph);
		}
	}
	print_path_test(data, graph);
}
*/