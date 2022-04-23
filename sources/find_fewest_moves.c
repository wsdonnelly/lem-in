/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_fewest_moves.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:49:06 by jjuntune          #+#    #+#             */
/*   Updated: 2022/04/20 08:40:18 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	change_capacity(t_path *path, t_room *graph)
{
	char	*current;
	t_edge	*neighbor;

	neighbor = path->room.neighbors;
	while (ft_strcmp(path->room.previous, graph[neighbor->next_room_index].name)
		&& neighbor)
		neighbor = neighbor->next;
	if (neighbor->capacity)
		neighbor->capacity = 0;
	else
		neighbor->capacity = 1;
	neighbor = graph[neighbor->next_room_index].neighbors;
	current = path->room.name;
	while (ft_strcmp(current, graph[neighbor->next_room_index].name)
		&& neighbor)
		neighbor = neighbor->next;
	if (neighbor->capacity)
		neighbor->capacity = 0;
	else
		neighbor->capacity = 1;
}

static int	avg_path_len(t_paths *paths, int *mod)
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
	*mod = total_len % num_paths;
	return (total_len / num_paths);
}

static int	get_required_moves(t_data data, t_paths *paths)
{
	int			required_moves;
	static int	num_paths;
	int			avg_path;
	int			mod1;
	int			mod2;

	num_paths++;
	avg_path = avg_path_len(paths, &mod1);
	required_moves = data.num_ants / num_paths + avg_path + mod1;
	mod2 = data.num_ants % num_paths;
	if ((mod1 + mod2) % num_paths == 0)
		required_moves--;
	return (required_moves);
}

void	find_fewest_moves(t_data *data, t_room *graph)
{
	data->shortest_path = create_room_on_path(graph[data->end_index]);
	while (data->shortest_path->room.previous)
	{
		change_capacity(data->shortest_path, graph);
		build_shortest_path(&data->shortest_path, graph);
	}
	if (data->all_paths)
		map_paths(data->all_paths, data->shortest_path);
	add_shortest_path_to_all_paths(&data->all_paths, data->shortest_path);
	data->required_moves = get_required_moves(*data, data->all_paths);
	if (!data->best_solution || data->required_moves < data->best_solution)
	{
		data->best_solution = data->required_moves;
		copy_all_paths_to_solution(&data->solution_paths, data->all_paths);
	}
}
