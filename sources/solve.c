/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:27:44 by wdonnell          #+#    #+#             */
/*   Updated: 2022/09/22 12:56:19 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>
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
void	solve(t_data data, t_room *graph)
{
	//first time through

	data.path_set = NULL;
	bfs(&data, graph);
	if (data.augmented_path)
	{
		change_capacity(&data, graph, TRUE);
		//print_path_test(&data, graph);
		create_path_set(&data, data.cur_path);
	}
	else
	{
		ft_printf("ERROR no valid path found\n");
		exit (0);
	}

	//set all flows
	while(data.augmented_path)
	{
		bfs(&data, graph);
		if (data.augmented_path)
			change_capacity(&data, graph, FALSE);
	}
	//get shortests paths upto max flow
	data.augmented_path = 1;
	while (data.augmented_path)
	{
		anti_bfs(&data, graph);
		if (data.augmented_path)
		{
		change_capacity(&data, graph, TRUE);
		printf("in here\n");
		//print_path_test(&data, graph);
		create_path_set(&data, data.cur_path);
		}
	}
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