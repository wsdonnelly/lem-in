/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OLDsolve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:49:06 by jjuntune          #+#    #+#             */
/*   Updated: 2022/09/22 13:07:49 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

/*
** The functions searches for the shortest path from start to end until no more
** valid paths are found. After each iteration, it is checked whether the
** current combination of paths requires less moves to move the ants from start
** to end than the current best solution.
** If a valid solution was found, the solution is printed to the standard
** output.
*/

void	solve(t_data data, t_room *graph, int argc)
{
	
	while (data.augmented_path)
	{
		//printf("HERE\n");
		find_shortest_path(&data, graph);
		if (data.augmented_path)
		{
			change_capacity(graph, &data);
			find_fewest_moves(&data, graph);

		}
	}
	if (data.num_paths)
	{
		ft_printf("%d\n", data.num_ants);
		print_comments(&data);
		print_data(&data);
		ft_putchar('\n');
		//work till here
		print_solution(&data);
		if (argc == 2)
			print_paths(&data);
		//free_paths(&data.solution_paths);
		//free_paths(&data.all_paths);
	}
	else
		ft_printf("no valid path found\n");
}
