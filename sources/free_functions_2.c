/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:01:23 by wdonnell          #+#    #+#             */
/*   Updated: 2022/10/12 11:55:12 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_result(t_path_group *result)
{
	t_path_set	*tmp;

	tmp = result->paths;
	while (tmp)
	{
		free(tmp->ant_nums);
		tmp = tmp->next_path;
	}
}

void	free_paths(t_path_group *path_group)
{
	t_paths	path;

	while (path_group)
	{
		path.tmp_group = path_group;
		path.path_set = path.tmp_group->paths;
		while (path.path_set)
		{
			path.tmp_path = path.path_set;
			path.room = path.tmp_path->path;
			while (path.room)
			{
				path.tmp_room = path.room;
				path.room = path.room->next;
				free(path.tmp_room);
			}
			path.path_set = path.path_set->next_path;
			free(path.tmp_path);
		}
		path_group = path_group->next_path_group;
		free(path.tmp_group);
	}
}

void	free_str_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free (arr[i++]);
	free (arr);
}
