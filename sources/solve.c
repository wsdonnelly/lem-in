/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:49:06 by jjuntune          #+#    #+#             */
/*   Updated: 2022/04/18 23:38:10 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	has_been_visited(t_edge *neighbor, t_path *visited, t_room *graph)
{
	t_path	*tmp;

	tmp = visited;
	while (tmp)
	{
		if (!ft_strcmp(tmp->room.name, graph[neighbor->next_room_index].name))
			return (1);
		tmp = tmp->next_room;
	}
	return (0);
}

static t_path	*create_room_on_path(t_room room)
{
	t_path	*path;
	
	path = (t_path*)malloc(sizeof(t_path));
	if (!path)
		return (NULL);
	path->room = room;
	path->next_room = NULL;
	return (path);
}

static void	add_room_to_path(t_room room, t_path **path)
{
	t_path	*tmp;

	if (!*path)
		*path = create_room_on_path(room);
	else
	{
		tmp = *path;
		while (tmp->next_room)
			tmp = tmp->next_room;
		tmp->next_room = create_room_on_path(room);
	}
}

static void	change_capacity(t_path *path, t_room *graph)
{
	char	*current;
	t_edge	*neighbor;

	neighbor = path->room.neighbors;
	while (ft_strcmp(path->room.previous, graph[neighbor->next_room_index].name) && neighbor)
		neighbor = neighbor->next;
	if (neighbor->capacity)
		neighbor->capacity = 0;
	else
		neighbor->capacity = 1;
	neighbor = graph[neighbor->next_room_index].neighbors;
	current = path->room.name;
	while (ft_strcmp(current, graph[neighbor->next_room_index].name) && neighbor)
		neighbor = neighbor->next;
	if (neighbor->capacity)
		neighbor->capacity = 0;
	else
		neighbor->capacity = 1;
}

static void	build_shortest_path(t_path **path, t_room *graph)
{
	t_path	*tmp1;
	t_path	*tmp2;
	t_edge	*neighbor;

	tmp1 = *path;
	neighbor = tmp1->room.neighbors;
	while (ft_strcmp(tmp1->room.previous, graph[neighbor->next_room_index].name) && neighbor)
		neighbor = neighbor->next;
	tmp2 = create_room_on_path(graph[neighbor->next_room_index]);
	tmp2->next_room = tmp1;
	*path = tmp2;
}

static t_paths	*create_path_for_paths(t_path *path)
{
	t_paths	*paths;
	
	paths = (t_paths*)malloc(sizeof(t_paths));
	if (!paths)
		return (NULL);
	paths->path = path;
	paths->next_path = NULL;
	return (paths);
}

static void	add_shortest_path_to_all_paths(t_paths **all_paths, t_path *shortest_path)
{
	t_paths	*tmp;

	if (!*all_paths)
		*all_paths = create_path_for_paths(shortest_path);
	else
	{
		tmp = *all_paths;
		while (tmp->next_path)
			tmp = tmp->next_path;
		tmp->next_path = create_path_for_paths(shortest_path);
	}
}

static void	map_paths(t_paths *all_paths, t_path *shortest_path)
{
	char	*room1;
	char	*room2;
	t_path	*path;
	t_path	*tmp1;
	t_path	*tmp2;
	t_paths	*paths;
	int		switched;

	while (shortest_path->next_room)
	{
		switched = 0;
		room1 = shortest_path->room.name;
		room2 = shortest_path->next_room->room.name;
		paths = all_paths;
		while (paths && !switched)
		{
			path = paths->path;
			while (path->next_room && !switched)
			{
				if (!ft_strcmp(path->room.name, room2) && !ft_strcmp(path->next_room->room.name, room1))
				{
					tmp1 = shortest_path->next_room;
					tmp2 = path->next_room;
					shortest_path->next_room = tmp2->next_room;
					path->next_room = tmp1->next_room;
					free(tmp1);
					free(tmp2);
					tmp1 = path;
					path = shortest_path;
					shortest_path = tmp1;
					switched = 1;
				}
				path = path->next_room;
			}
			paths = paths->next_path;
		}
		if (!switched)
			shortest_path = shortest_path->next_room;
	}
}

void	solve(t_data data, t_room *graph)
{
	int	augmented_path;
//	int	current_best_solution;
//	int	current_length;
	t_path	*queue;
	t_path	*visited;
	t_path	*shortest_path;
	t_path	*tmp;
	t_edge	*neighbor;
	t_paths	*all_paths;
	t_paths	*tmp2;

	data.num_ants = 100;
	graph[4].previous = NULL; //include in initialization of data
//	current_length = 0;
//	current_best_solution = 0;
	augmented_path = 1;
	all_paths = NULL;
	while (augmented_path)
	{
		queue = NULL;
		visited = NULL;
		shortest_path = NULL;
		augmented_path = 0;
		add_room_to_path(graph[11], &queue); //t_data should include index for start and end, not name
		add_room_to_path(graph[11], &visited);
		while (queue && !augmented_path)
		{
			neighbor = queue->room.neighbors;
			while (neighbor && !augmented_path)
			{
				if (neighbor->capacity && neighbor->next_room_index == 13) //replace 13 with data.end
				{
					augmented_path = 1;
					graph[neighbor->next_room_index].previous = queue->room.name;
				}
				else if (neighbor->capacity && !has_been_visited(neighbor, visited, graph))
				{
					add_room_to_path(graph[neighbor->next_room_index], &queue);
					add_room_to_path(graph[neighbor->next_room_index], &visited);
					graph[neighbor->next_room_index].previous = queue->room.name;
				}
				neighbor = neighbor->next;
			}
			tmp = queue;
			queue = queue->next_room;
			free(tmp);
		}
		while (visited)
		{
			tmp = visited;
			visited = visited->next_room;
			free(tmp);
		}
		if (augmented_path)
		{
			shortest_path = create_room_on_path(graph[13]); // replace 13 with data.end
			while (shortest_path->room.previous)
			{
				change_capacity(shortest_path, graph);
				build_shortest_path(&shortest_path, graph);
			}
			if (all_paths)
				map_paths(all_paths, shortest_path);
			add_shortest_path_to_all_paths(&all_paths, shortest_path);
			printf("new round:\n");
			tmp2 = all_paths;
			while (tmp2)
			{
				tmp = tmp2->path;
				while (tmp)
				{
					printf("%s\n", tmp->room.name);
					tmp = tmp->next_room;
				}
				printf("\n");
				tmp2 = tmp2->next_path;
			}
		}
		/*
			if augmented_path
				minimum required moves = sum length of all identified paths
				if minimum required moves < current best solution || !current best solution
					current best solution = minimum required moves
					solution_path_list = all_identified path_list
				set room.queue, room.visited and room.previous to NULL for all rooms
		*/
	}
}
