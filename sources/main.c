/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:49:06 by jjuntune          #+#    #+#             */
/*   Updated: 2022/05/02 14:57:20 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	init_data(t_data *data)
{
	data->num_ants = -1;
	data->num_rooms = 0;
	data->size = -1;
	data->start = NULL;
	data->end = NULL;
	data->store_input = NULL;
	data->name_list = NULL;
	data->start_index = FALSE;
	data->end_index = FALSE;
	data->best_solution = 0;
	data->augmented_path = 1;
	data->num_paths = 0;
	data->all_paths = NULL;
	data->solution_paths = NULL;
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_room	*graph;

	if (argc > 2 || (argc == 2 && ft_strcmp(argv[1], "-v")))
	{
		ft_putstr_fd("Usage: ./lem-in [-v]\n", 2);
		return (1);
	}
	graph = NULL;
	data.graph = &graph;
	init_data(&data);
	read_map(&data, &graph);
	graph[data.start_index].previous = NULL;
	solve(data, graph, argc);
/*
	t_edge *temp;
	int i = 0;
	while (i < data.size)
	{
		printf("graph[%d].name: %s\n", i, graph[i].name);
		//printf("graph[%d].start: %d\n", i, graph[i].start);
		//printf("graph[%d].end: %d\n", i, graph[i].end);
		
		temp = graph[i].neighbors;
		while(temp)
		{
			printf("neighbor: %s\n", graph[temp->next_room_index].name);
			printf("capacity: %d\n\n", temp->capacity);
			temp = temp->next;
		}
		printf("\n");
		i++;
	}
	printf("index end: %d\n", data.end_index);
	printf("index start: %d\n", data.start_index);
	*/
	free_graph(&graph, &data);
	free_data(&data);
	return (0);
}
