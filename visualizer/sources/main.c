/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 12:22:41 by wdonnell          #+#    #+#             */
/*   Updated: 2022/04/15 21:16:55 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	init_info(t_info *info)
{
	info->num_ants = -1;
	info->num_rooms = 0;
	info->start = NULL;
	info->end = NULL;
}



int	main()
{
	//t_data data;
	t_info	info;
	//t_room	*room_arr = NULL;

	//data.mlx = mlx_init();
	//data.win = mlx_new_window(data.mlx, 1920, 1080, "visualizer");
	init_info(&info);
	
	read_in_info(&info);


	
	//draw_graph();
	//mlx_hook(data.win, 3, 0, controls, &data);
	/*
	printf("num ants: %d\n", info.num_ants);
	printf("num rooms: %d\n", info.num_rooms);
	printf("start room: %s\n", info.start);
	printf("end room: %s\n", info.end);
	*/
	

	
	
	
	//mlx_loop(data.mlx);

	

	//free_graph();


	return (0);
}

