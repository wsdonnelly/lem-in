/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_fewest_moves.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:49:06 by jjuntune          #+#    #+#             */
/*   Updated: 2022/08/22 18:19:13 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	change_capacity(t_path *path, t_room *graph, t_data *data)
{
	char	*current;
	t_edge	*neighbor;
	t_edge	*neighbor2;
	int		in_or_out;

	neighbor = path->room->neighbors;
	while (ft_strcmp(path->room->previous, \
	graph[neighbor->next_room_index].name)
		&& neighbor)
		neighbor = neighbor->next;
	if (neighbor->capacity)
		neighbor->capacity = 0;
	else
		neighbor->capacity = 1;
	neighbor = graph[neighbor->next_room_index].neighbors;
	current = path->room->name;
	while (ft_strcmp(current, graph[neighbor->next_room_index].name)
		&& neighbor)
		neighbor = neighbor->next;
	if (neighbor->capacity)
		neighbor->capacity = 0;
	else
		neighbor->capacity = 1;
	
	
	neighbor = path->room->neighbors;
	while (ft_strcmp(path->room->previous, \
	graph[neighbor->next_room_index].name)
		&& neighbor)
		neighbor = neighbor->next;
	if (ft_strcmp(current, data->start) && ft_strcmp(current, data->end) && ft_strcmp(graph[neighbor->next_room_index].name, data->start) && ft_strcmp(graph[neighbor->next_room_index].name, data->end))
	{
		if (ft_strcmp("t", current + ft_strlen(current) - 1))
			in_or_out = 2;
		else
			in_or_out = 3;
		if (ft_strncmp(current, graph[neighbor->next_room_index].name, ft_strlen(current) - in_or_out))
		{
			if (in_or_out == 3)
			{
				neighbor2 = graph[neighbor->next_room_index].neighbors;
				while (ft_strncmp(graph[neighbor->next_room_index].name, \
				graph[neighbor2->next_room_index].name, ft_strlen(graph[neighbor->next_room_index].name) - 2)
					&& neighbor2)
					neighbor2 = neighbor2->next;
				neighbor = graph[neighbor2->next_room_index].neighbors;
				while (ft_strncmp(current, \
				graph[neighbor->next_room_index].name, ft_strlen(current) - 3)
					&& neighbor)
					neighbor = neighbor->next;
				neighbor->capacity = 1;
			}
			else
			{
				neighbor2 = path->room->neighbors;
				while (ft_strncmp(current, \
				graph[neighbor2->next_room_index].name, ft_strlen(current) - 2)
					&& neighbor2)
					neighbor2 = neighbor2->next;
				neighbor2 = graph[neighbor2->next_room_index].neighbors;
				while (ft_strncmp(graph[neighbor->next_room_index].name, \
				graph[neighbor2->next_room_index].name, ft_strlen(graph[neighbor->next_room_index].name) - 3)
					&& neighbor2)
					neighbor2 = neighbor2->next;
				neighbor2->capacity = 0;
			}
		}
	}
}

static int	get_path_len(t_paths *paths)
{
	int		num_paths;
	int		total_len;
	t_path	*path;

	num_paths = 0;
	total_len = 0;
	while (paths)
	{
		path = paths->path;
		while (path)
		{
			total_len++;
			path = path->next_room;
		}
		num_paths++;
		paths = paths->next_path;
	}
	total_len /= 2;
	return (total_len - num_paths);
}

static int	get_required_moves(int num_ants, t_paths *paths)
{
	int			required_moves;
	static int	num_paths;
	int			path_len;

	num_paths++;
	path_len = get_path_len(paths);
	required_moves = 0;
	while (num_ants > num_paths * required_moves - path_len)
		required_moves++;
	return (required_moves);
}

/*
** The latest shortest path is added to a list of all identified paths and
** the capacities along this path are set to 0. The moves to get all ants
** from start to end are calculated (assuming all paths are used). If the
** number of moves is lower than the current best solution, the caluclated
** number of moves is set as the new solution.
*/

void	find_fewest_moves(t_data *data, t_room *graph)
{
	data->shortest_path = create_room_on_path(&graph[data->end_index]);
	while (data->shortest_path->room->previous)
	{
		change_capacity(data->shortest_path, graph, data);
		build_shortest_path(&data->shortest_path, graph);
	}
	if (data->all_paths)
		map_paths(data->all_paths, data->shortest_path);
	add_shortest_path_to_all_paths(&data->all_paths, data->shortest_path);
	data->required_moves = get_required_moves(data->num_ants, data->all_paths);
	if (!data->best_solution || data->required_moves < data->best_solution)
	{
		data->best_solution = data->required_moves;
		copy_all_paths_to_solution(&data->solution_paths, data->all_paths);
	}
}
