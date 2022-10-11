/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:49:06 by jjuntune          #+#    #+#             */
/*   Updated: 2022/10/10 20:56:02 by wdonnell         ###   ########.fr       */
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
	data->store_input_head = NULL;
	data->store_input_tail = NULL;
	data->start_index = -2;
	data->end_index = -2;
	data->name_list = NULL;
	data->flow_path = 1;
}

//remove in master branch
void print_graph_test(t_room *graph, t_data *data)
{
	int i = 0;
	t_edge *tmp;

	while (i < data->size)
	{
		printf("%s === forward neighbors: ", graph[i].name);
		tmp = graph[i].neighbors;
		while (tmp)
		{
			if (tmp->is_forward)
				printf("%s -> flow: %d | ", graph[tmp->next_room_index].name, tmp->flow);
			tmp = tmp->next;
		}
		printf("\n");
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_room	*graph;
	t_path_group	*result;

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
	//needed?
	graph[data.start_index].previous_idx = -1;
	solve(&data, graph);
	if (!data.path_group || !data.path_group->paths)
		exit_error(&data, "no valid path found");
	result = NULL;
	result = compare_paths(&data);
	result->paths->paths_total = init_ant_nums(result);
	print_data(&data);
	ft_printf("\n");
	print_result(result, graph, &data);
	// print_verbose(&data, result, graph); --> ready in print.result.c
	//print_comments(&data);


	free_graph(&graph, &data);
	free_paths(data.path_group);
	free_data(&data);
	return (0);
}
