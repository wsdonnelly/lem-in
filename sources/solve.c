/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:27:44 by wdonnell          #+#    #+#             */
/*   Updated: 2022/10/07 14:15:22 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	print_path_test(t_data *data, t_room *graph)
{
	t_queue_node	*tmp;
	t_path_set		*tmp_path;
	t_path_group	*cur_group;

	cur_group = data->path_group;
	while (cur_group)
	{
		tmp_path = cur_group->paths;
		printf("path_group-->>>\n");
		while (tmp_path)
		{
			tmp = tmp_path->path;
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
static void	init_in_path(t_data *data, t_room *graph)
{
	int	i;

	i = 0;
	while (i < data->size)
		graph[i++].in_path = 0;
}

static void	filter_all_rooms(t_data *data, t_room *graph)
{
	int	len;
	int	i;

	i = 0;
	while (i < data->size)
	{
		if (graph[i].name)
		{
			len = ft_strlen(graph[i].name);
			if (graph[i].name[len - 1] == 'I' || graph[i].name[len - 1] == 'O')
				graph[i].name[len - 1] = '\0';
		}
		i++;
	}
}
*/
/*
* change_capacity(data, graph, SAVE?, FLOW?)
* bfs(data, graph, PATH?)
*/

void	solve(t_data *data, t_room *graph)
{
	int	steps;

	data->path_group = NULL;
	//data->path_set = NULL;
	//filter_all_rooms(data, graph);
	while (data->flow_path)
	{
		bfs(data, graph, FALSE);
		if (data->flow_path)
		{
			printf("found a flow\n");
			//change_capacity(data, graph, FALSE, TRUE);
			
			create_path_group(data);
			steps = change_capacity(data, graph, TRUE, TRUE);
			print_graph_test(graph, data);
			create_path_set(data, data->cur_path, steps);
			//init_in_path(data, graph);
			/*
			while (data->shortest_path)
			{
				bfs(data, graph, TRUE);
				if (data->shortest_path)
				{
					steps = change_capacity(data, graph, TRUE, FALSE);
					create_path_set(data, data->cur_path, steps);
				}
			}
			*/
		}
	}
	print_path_test(data, graph);
}
