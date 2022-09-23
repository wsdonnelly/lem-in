/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_best_paths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:23:56 by wdonnell          #+#    #+#             */
/*   Updated: 2022/09/23 12:57:26 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


static int get_moves(t_queue_node *path_start, int num_ants)
{
	int num_moves;
	int steps;
	t_queue_node *tmp;

	tmp = path_start;
	steps = 0;
	
	while (tmp)
	{
		steps++;
		tmp = tmp->next;
	}
	printf("steps: %d\n", steps);
	num_moves = num_ants + steps - 1;
	return (num_moves);
}

void get_best_paths(t_data *data)
{
	//int best;
	int moves;
	int try = 2;
	int i;
	int j;
	t_path_set *start;
	int total_moves;
	int ants_on_path;
	int rem;

	moves = get_moves(data->path_set->path, data->num_ants);
	printf("lines req on first path: %d\n", moves);

	i = 0;
	while (i < try)
	{
		j = 0;
		start = data->path_set->next_path;
		while (j < try && start)
		{
			ants_on_path = data->num_ants / try;
			rem = data->num_ants % try
			if (!data->num_ants % try && j == 0)
				ants_on_path = data->num_ants / try + 1;

			
			moves = get_moves(start->path, data->num_ants);
			printf("lines req on path_set %d: %d\n", try, moves);
			//calculate total lines
			start = start->next_path;
			j++;
		}
		if (j == try)
		{
			//found try # of paths
			//compare result
			printf("found %d paths\n", try);
		}
		if (!start)
		{
			printf("no mas paths\n");
			break;
		}
			
			

		try++;
	}
}
