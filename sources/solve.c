/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:49:06 by jjuntune          #+#    #+#             */
/*   Updated: 2022/05/01 15:51:31 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	solve(t_data data, t_room *graph, int argc)
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
		if (argc == 2)
			print_paths(data);
		free_paths(&data.solution_paths);
		free_paths(&data.all_paths);
	}
	else
		ft_printf("no valid path found\n");
}
