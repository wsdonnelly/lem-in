/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ants_on_paths.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 11:45:56 by wdonnell          #+#    #+#             */
/*   Updated: 2022/10/06 12:14:18 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	get_lines(t_path_set *cur_path)
{
	while (cur_path && cur_path->ants_on_path)
	{
		cur_path->lines = cur_path->steps + cur_path->ants_on_path - 1;
		cur_path = cur_path->next_path;
	}
}

void	put_ants_on_path(t_data *data, t_path_group *path_group)
{
	int			ants_at_start;
	int			diff;
	int			path_num;
	t_path_set	*cur_path;

	ants_at_start = data->num_ants;
	while (ants_at_start)
	{
		diff = 0;
		cur_path = path_group->paths;
		path_num = 0;
		while (cur_path && ants_at_start)
		{
			if (!path_num && ants_at_start)
			{
				cur_path->ants_on_path++;
				ants_at_start--;
			}
			else if (ants_at_start > (path_num * (cur_path->steps - (diff / path_num))))
			{
				cur_path->ants_on_path++;
				ants_at_start--;
			}
			diff += cur_path->steps;
			path_num++;
			cur_path = cur_path->next_path;
		}
	}
	get_lines(path_group->paths);
	
	//tester
	cur_path = path_group->paths;
	while (cur_path)
	{
		printf("ants on path %d | steps: %d | lines: %d\n", cur_path->ants_on_path, cur_path->steps ,cur_path->lines);
		cur_path = cur_path->next_path;
	}
	printf("\n");
}
