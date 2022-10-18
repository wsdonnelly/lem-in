/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:06:35 by wdonnell          #+#    #+#             */
/*   Updated: 2022/10/18 14:03:35 by wdonnell         ###   ########.fr       */
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
	data->verbose = 0;
	data->print_lines = 0;
}

static void	check_args(int ac, char **av, t_data *data)
{
	if (ac >= 2)
	{
		if (ac == 2 && !ft_strcmp(av[1], "-v"))
			data->verbose = 1;
		else if (ac == 2 && !ft_strcmp(av[1], "-l"))
			data->print_lines = 1;
		else
		{
			ft_putstr_fd("Usage: ./lem-in [-v] [-l]\n", 2);
			exit(1);
		}
	}
}

static void	free_all(t_data *data, t_room *graph, t_path_group	*result)
{
	free_result(result);
	free_graph(&graph, data);
	free_paths(data->path_group);
	free_data(data);
}

static void	print_flags(t_data *data, t_path_group *result, t_room *graph)
{
	if (data->verbose)
		print_verbose(data, result, graph);
	if (data->print_lines)
		ft_printf("\x1b[32mLines used: %d\n\x1b[0m", result->paths->lines);
}

int	main(int ac, char **av)
{
	t_data			data;
	t_room			*graph;
	t_path_group	*result;

	init_data(&data);
	check_args(ac, av, &data);
	graph = NULL;
	data.graph = &graph;
	read_map(&data, &graph);
	if (!graph || data.start_index == -2 || data.end_index == -2)
		exit_error(&data, "ERROR");
	solve(&data, graph);
	if (!data.path_group || !data.path_group->paths)
		exit_error(&data, "no valid path found");
	result = NULL;
	result = compare_paths(&data);
	init_ant_nums(result);
	print_data(&data);
	print_result(result, graph, &data);
	print_flags(&data, result, graph);
	free_all(&data, graph, result);
	return (0);
}
