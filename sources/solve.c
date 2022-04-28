/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:49:06 by jjuntune          #+#    #+#             */
/*   Updated: 2022/04/28 10:52:53 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	solve(t_data data, t_room *graph, int argc) //can we pass data as *data?
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
		ft_printf("%d\n", data.num_ants);
		print_comments(&data);
		print_data(&data);
		ft_putchar('\n');
		print_solution(data);
		
		if (argc == 2)
			print_paths(data);
		free_paths(&data.solution_paths);
		free_paths(&data.all_paths);
	}
	else
		ft_printf("no valid path found\n"); // change to ft_printf
}
