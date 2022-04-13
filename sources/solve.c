/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:49:06 by jjuntune          #+#    #+#             */
/*   Updated: 2022/04/13 22:18:53 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	solve(t_room *start)
{
	int	augmented_path;
	int	current_best_solution;
	int	current_length;
	
	current_length = 0;
	current_best_solution = 0;
	augmented_path = 1;
	while (augmented_path)
	{
		/*
			augmented_path = 0
			Q(start)
			V(start)
			while Q not NULL
				for i in Q[0].neighbours
					if Q[0].neighbours[i] == end
						augmented_path = 1
						go to room end
						set end.previous = Q[0]
						exit while loop
					else if Q[0].neighbours[i] not in V (list of visited rooms)
						add Q[0].neighbours[i] to Q
						add Q[0].neighbours[i] to V
						go to room Q[0].neighbours[i]
						set room.previous = Q[0]
			if augmented_path
				trace back shortest path and remove j as neighbour from i and add i as neighbour of j (eg path: S-i-j-T)
				for P1-Ri-Rj-A1 in shortest path
					if P2-Rj-Ri-A2 in one of the previous identified paths
						change shortest path to: P1-Ri-A2
						change previous path to: P2-Rj-A1 
				add shortest path to all_identified_path_list
				minimum required moves = sum length of all identified paths
				if minimum required moves < current best solution || !current best solution
					current best solution = minimum required moves
					solution_path_list = all_identified path_list
				set room.queue, room.visited and room.previous to NULL for all rooms
		*/
	}
}
