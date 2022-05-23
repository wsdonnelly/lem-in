/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:49:06 by jjuntune          #+#    #+#             */
/*   Updated: 2022/05/23 10:27:11 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	build_shortest_path(t_path **path, t_room *graph)
{
	t_path	*tmp1;
	t_path	*tmp2;
	t_edge	*neighbor;

	tmp1 = *path;
	neighbor = tmp1->room->neighbors;
	while (ft_strcmp(tmp1->room->previous, graph[neighbor->next_room_index].name)
		&& neighbor)
		neighbor = neighbor->next;
	tmp2 = create_room_on_path(&graph[neighbor->next_room_index]);
	tmp2->next_room = tmp1;
	*path = tmp2;
}

static t_paths	*create_path_for_paths(t_path *path, int solution)
{
	t_paths	*paths;

	paths = (t_paths *)malloc(sizeof(t_paths));
	if (!paths)
		return (NULL);
	paths->path = NULL;
	paths->next_path = NULL;
	if (solution)
	{
		while (path)
		{
			add_room_to_path(path->room, &paths->path);
			path = path->next_room;
		}
	}
	else
		paths->path = path;
	paths->next_path = NULL;
	return (paths);
}

void	add_shortest_path_to_all_paths(t_paths **all_paths, \
		t_path *shortest_path)
{
	t_paths	*tmp;

	if (!*all_paths)
		*all_paths = create_path_for_paths(shortest_path, 0);
	else
	{
		tmp = *all_paths;
		while (tmp->next_path)
			tmp = tmp->next_path;
		tmp->next_path = create_path_for_paths(shortest_path, 0);
	}
}

void	copy_all_paths_to_solution(t_paths **solution_paths, t_paths *all_paths)
{
	t_paths	*tmp1;
	t_paths	*tmp2;

	if (*solution_paths)
		free_paths(solution_paths);
	tmp2 = all_paths;
	*solution_paths = create_path_for_paths(tmp2->path, 1);
	tmp2 = tmp2->next_path;
	tmp1 = *solution_paths;
	while (tmp2)
	{
		tmp1->next_path = create_path_for_paths(tmp2->path, 1);
		tmp1 = tmp1->next_path;
		tmp2 = tmp2->next_path;
	}
}
