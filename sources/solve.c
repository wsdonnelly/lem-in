/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:27:44 by wdonnell          #+#    #+#             */
/*   Updated: 2022/09/26 10:53:32 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

void	solve(t_data *data, t_room *graph)
{
	//first time through
	int i;
	int try = 2;
	int steps;

	data->path_set = NULL;
	bfs(data, graph, 1);
	if (data->augmented_path)
	{
		steps = change_capacity(data, graph, TRUE);
		create_path_set(data, data->cur_path, steps);
		printf("try: 1\n");
		print_path_test(data, graph);
	}
	else
	{
		ft_printf("ERROR no valid path found\n");
		exit (0);
	}

	while (data->augmented_path)
	{
		//run a forward search to check if another path exists
		bfs(data, graph, 1);
			if (data->augmented_path)
			{
				change_capacity(data, graph, FALSE);
				i = 0;
				while(i < try)
				{
					bfs(data, graph, 0);
					//get rid of if?
					steps = change_capacity(data, graph, TRUE);
					create_path_set(data, data->cur_path, steps);
					printf("try: %d\n", try);
					print_path_test(data, graph);
					i++;
				}
			}
			try++;
	}
	
}

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