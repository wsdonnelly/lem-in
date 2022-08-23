/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:49:06 by jjuntune          #+#    #+#             */
/*   Updated: 2022/08/22 14:48:32 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	relink_paths(t_path *shortest_path, t_path *path, int *switched)
{
	t_path	*tmp1;
	t_path	*tmp2;

	tmp1 = shortest_path->next_room;
	tmp2 = path->next_room;
	shortest_path->next_room = tmp2->next_room;
	path->next_room = tmp1->next_room;
	free(tmp1);
	free(tmp2);
	*switched = 1;
}

static void	iterate_paths(t_paths *paths, int *switched, char **rooms, \
			t_path *shortest_path)
{
	t_path	*path;

	path = paths->path;
	while (path->next_room && !*switched)
	{
		if (!ft_strcmp(path->room->name, rooms[1])
			&& !ft_strcmp(path->next_room->room->name, rooms[0]))
			relink_paths(shortest_path, path, switched);
		if (!*switched)
			path = path->next_room;
	}
}

static void	delete_rooms(t_path *shortest_path)
{
	t_path	*tmp;

	tmp = shortest_path->next_room;
	shortest_path->next_room = tmp->next_room;
	free(tmp);
}

static void	check_new_path(t_path *shortest_path)
{
	t_path	*tmp;
	int		switched;

	while (shortest_path)
	{
		switched = 0;
		tmp = shortest_path->next_room;
		while (tmp && !switched)
		{
			if (!ft_strcmp(tmp->room->name, shortest_path->room->name))
			{
				while (ft_strcmp(shortest_path->room->name, \
						shortest_path->next_room->room->name))
					delete_rooms(shortest_path);
				delete_rooms(shortest_path);
				switched = 1;
			}
			if (!switched)
				tmp = tmp->next_room;
		}
		shortest_path = shortest_path->next_room;
	}
}

void	map_paths(t_paths *all_paths, t_path *shortest_path)
{
	char	*rooms[2];
	t_paths	*paths;
	int		switched;

	while (shortest_path->next_room)
	{
		switched = 0;
		rooms[0] = shortest_path->room->name;
		rooms[1] = shortest_path->next_room->room->name;
		paths = all_paths;
		while (paths && !switched)
		{
			iterate_paths(paths, &switched, rooms, shortest_path);
			if (!switched)
				paths = paths->next_path;
		}
		if (!switched)
			shortest_path = shortest_path->next_room;
		else
		{
			shortest_path = paths->path;
			check_new_path(shortest_path);
		}
	}
}
