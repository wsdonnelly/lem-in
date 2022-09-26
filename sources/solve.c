/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:27:44 by wdonnell          #+#    #+#             */
/*   Updated: 2022/09/26 20:31:10 by wdonnell         ###   ########.fr       */
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
void	solve(t_data *data, t_room *graph)
{
	//int i;
	//int try = 1;
	int steps;

	data->path_group = NULL;
	data->path_set = NULL;
	
	/*
	bfs(data, graph, 1);
	if (data->augmented_path)
	{
		steps = change_capacity(data, graph, TRUE);
		create_path_group(data);
		create_path_set(data, data->cur_path, steps);
	}
	else
	{
		ft_printf("ERROR no valid path found\n");
		exit (0);
	}
 */

	while (data->augmented_path)
	{
		bfs(data, graph, 1);
		if (data->augmented_path)
		{
			//reset_capacities(data, graph);
			steps = change_capacity(data, graph, TRUE);
			create_path_group(data);
			create_path_set(data, data->cur_path, steps);
		}
	}
/*
data->augmented_path = 1;
	while (data->augmented_path)
	{
		//print_graph_test(graph, data);
		printf("\n");
		bfs(data, graph, 0);
		if (data->augmented_path)
		{
			steps = change_capacity(data, graph, TRUE);
			create_path_group(data);
			create_path_set(data, data->cur_path, steps);
		}

	}
*/
	print_path_test(data, graph);
	
}

/*
	while (data->augmented_path)
	{
		//run a forward search to check if another path exists
		bfs(data, graph, 1);
			if (data->augmented_path)
			{
				change_capacity(data, graph, FALSE);
				create_path_group(data);
				i = 0;
				while(i < try)
				{
					bfs(data, graph, 0);
					steps = change_capacity(data, graph, TRUE);
					create_path_set(data, data->cur_path, steps);
					i++;
				}
			}
			try++;
	}

	print_path_test(data, graph);
}
*/

/*
void	solve(t_data *data, t_room *graph)
{
	//first time through
	int try = 2;
	int steps;

	data->path_set = NULL;
	bfs(data, graph, 1);
	if (data->augmented_path)
	{
		//data.cur_path = NULL;
		steps = change_capacity(data, graph, TRUE);
		//printf("\nFIRST BFS\n");
		create_path_set(data, data->cur_path, steps);
		//print_path_test(data, graph);
	}
	else
	{
		ft_printf("ERROR no valid path found\n");
		exit (0);
	}

	//set all flows
	while(data->augmented_path)
	{
		bfs(data, graph, 1);
		if (data->augmented_path)
			change_capacity(data, graph, FALSE);
	}
	//get shortests paths upto max flow
	data->augmented_path = 1;
	while (data->augmented_path)
	{
		bfs(data, graph, 0);
		if (data->augmented_path)
		{
			//data.cur_path = NULL;
			steps = change_capacity(data, graph, TRUE);
			create_path_set(data, data->cur_path, steps);
			//printf("PATH SET %d\n", try);
			//print_path_test(&data, graph);
		}
		try++;
	}
	printf("\nPATHS, first one is original BFS\n");
	
	print_path_test(data, graph);
}
*/