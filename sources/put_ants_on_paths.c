/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ants_on_paths.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 11:45:56 by wdonnell          #+#    #+#             */
/*   Updated: 2022/09/26 10:53:30 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void put_ants_on_path(t_data *data)
{
	t_path_set *cur_path;
	int ants_at_start;
	int diff;
	int path_num;


	ants_at_start = data->num_ants;
	while (ants_at_start)
	{
		diff = 0;
		cur_path = data->path_set->next_path;
		path_num = 0;
		while (cur_path && ants_at_start)
		{
			//iterate through paths in order
			if (!path_num && ants_at_start)
			{
				//add ant to current path
				cur_path->lines = cur_path->steps + cur_path->ants_on_path;
				cur_path->ants_on_path++;
				
				ants_at_start--;
			}
			else if (ants_at_start > (path_num * (cur_path->steps - (diff / path_num))))
			{
				
				//add ant to current path
				cur_path->lines = cur_path->steps + cur_path->ants_on_path;
				cur_path->ants_on_path++;
				ants_at_start--;

			}
			diff += cur_path->steps;
			path_num++;
			cur_path = cur_path->next_path;
		}
	}
	
	data->path_set->ants_on_path = data->num_ants;
	data->path_set->lines = data->path_set->steps + data->num_ants - 1;
	//get total lines
	if (data->path_set->steps + data->num_ants - 1 <= data->path_set->next_path->lines)
		printf("first path is best\n");
	else
		printf("multi paths are best\n");

	//tester
	cur_path = data->path_set;
	while (cur_path)
	{
		printf("ants on path %d | lines: %d\n", cur_path->ants_on_path, cur_path->lines);
		cur_path = cur_path->next_path;
	}
	
}



