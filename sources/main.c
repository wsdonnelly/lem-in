/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:49:06 by jjuntune          #+#    #+#             */
/*   Updated: 2022/09/28 13:35:30 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

static void	init_data(t_data *data)
{
	data->num_ants = -1;
	data->num_rooms = 0;
	//data->size = -1;
	data->start = NULL;
	data->end = NULL;
	data->store_input_head = NULL;
	data->store_input_tail = NULL;
	data->start_index = -2;
	data->end_index = -2;
	data->name_list = NULL;
	//data->augmented_path = 1;
	data->best_solution = 0;
	data->required_moves = 0;
	data->num_paths = 0;
	data->all_paths = NULL;
	data->solution_paths = NULL;
}

void print_graph_test(t_room *graph, t_data *data)
{
	//graph print test
	int i = 0;
	t_edge *tmp;

	while (i < data->num_rooms)
	{
		printf("%s === neighbors: ", graph[i].name);
		tmp = graph[i].neighbors;
		while (tmp)
		{
			printf("%s, cap: %d -- flow: %d | ", graph[tmp->next_room_index].name, tmp->capacity, tmp->flow);
			tmp = tmp->next;
		}
		printf("\n");
		i++;
	}
	printf("\n");
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
	
	if (!graph || data.start_index == -2 || data.end_index == -2)
		exit_error(&data, "ERROR");
	graph[data.start_index].previous_idx = -1;
	
	//
	//print_graph_test(graph, &data);


	solve(&data, graph);
	
	//put_ants_on_path(&data);
	
	//solve(data, graph, argc);
	free_graph(&graph, &data);
	free_data(&data);
	return (0);
}
