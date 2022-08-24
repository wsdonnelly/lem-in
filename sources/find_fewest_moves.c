/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_fewest_moves.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:49:06 by jjuntune          #+#    #+#             */
/*   Updated: 2022/08/24 16:17:45 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
