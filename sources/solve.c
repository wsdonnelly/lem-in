/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:27:44 by wdonnell          #+#    #+#             */
/*   Updated: 2022/09/23 10:41:31 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
/*
void print_path_test(t_data *data, t_room *graph)
{
	t_queue_node *tmp;

	tmp = data->cur_path;
	printf("current path:\n");
	while (tmp)
	{
		printf("%s ", graph[tmp->index].name);
		tmp = tmp->next;
	}
	printf("\n");
}
*/
//updated
static void print_path_test(t_data *data, t_room *graph)
{
	t_queue_node *tmp;
	t_path_set *tmp_path;
	
	tmp_path = data->path_set;
	
	while (tmp_path)
	{
		printf("current path:\n");
		tmp = tmp_path->path;
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
void	solve(t_data *data, t_room *graph)
{
	//first time through
	int try = 2;

	data->path_set = NULL;
	bfs(data, graph, 1);
	if (data->augmented_path)
	{
		//data.cur_path = NULL;
		change_capacity(data, graph, TRUE);
		//printf("\nFIRST BFS\n");
		create_path_set(data, data->cur_path);
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
			change_capacity(data, graph, TRUE);
			create_path_set(data, data->cur_path);
			//printf("PATH SET %d\n", try);
			//print_path_test(&data, graph);
		}
		try++;
	}
	printf("\nPATHS, first one is original BFS\n");
	
	print_path_test(data, graph);
}


/*
void	solve(t_data data, t_room *graph)
{
	int try = 2;
	int i;


	//first time through
	//forward
	bfs(&data, graph);
	if (data.augmented_path)
	{
		change_capacity(&data, graph, TRUE);
		print_path_test(&data, graph);
	}
	else
	{
		ft_printf("ERROR no valid path found\n");
		exit (0);
	}
	print_graph_test(graph, &data);
	while(data.augmented_path)
	{
		//checks if an additional path is possible
		bfs(&data, graph);
		printf("AUG PATH FOUND\n");
		if (data.augmented_path)
		{

			change_capacity(&data, graph, TRUE);
			print_path_test(&data, graph);
			//print_graph_test(graph, &data);
			
			i = 0;
			while (i < try)
			{
				anti_bfs(&data, graph);
				printf("AUG PATH? ->%d\n", data.augmented_path);
				if (data.augmented_path)
				{
					
				change_capacity(&data, graph, TRUE);
				print_path_test(&data, graph);
				}
				i++;
			}
		}
		try++;
	}
}
*/