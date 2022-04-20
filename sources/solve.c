/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:49:06 by jjuntune          #+#    #+#             */
/*   Updated: 2022/04/20 22:26:39 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	solve(t_data data, t_room *graph)
{
	while (data.augmented_path)
	{
		find_shortest_path(&data, graph);
		if (data.augmented_path)
		{
			find_fewest_moves(&data, graph);
			data.num_paths++;
		}
	}
	if (data.num_paths)
	{
		print_solution(data);
		free_paths(&data.solution_paths);
		free_paths(&data.all_paths);
	}
	else
		printf("no valid path found\n"); // change to ft_printf     
}
