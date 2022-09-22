/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_best_paths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:23:56 by wdonnell          #+#    #+#             */
/*   Updated: 2022/09/22 17:12:04 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int get_moves_first(t_data *data)
{
	int num_moves;
	int steps;
	t_queue_node *tmp;

	tmp = data->path_set->path;
	steps = 0;
	
	while (tmp)
	{
		steps++;
		tmp = tmp->next;
	}
	printf("steps: %d\n", steps);
	num_moves = data->num_ants + steps - 1;
	return (num_moves);
}

void get_best_paths(t_data *data)
{
	//int best;
	int moves;

	moves = get_moves_first(data);
	printf("lines req on first path: %d\n", moves);





	
}
