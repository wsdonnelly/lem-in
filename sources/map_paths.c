/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:49:06 by jjuntune          #+#    #+#             */
/*   Updated: 2022/05/23 10:27:08 by wdonnell         ###   ########.fr       */
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
	tmp1 = path;
	path = shortest_path;
	shortest_path = tmp1;
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
		path = path->next_room;
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
			iterate_paths(all_paths, &switched, rooms, shortest_path);
			paths = paths->next_path;
		}
		if (!switched)
			shortest_path = shortest_path->next_room;
	}
}
