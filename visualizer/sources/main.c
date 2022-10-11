/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 12:22:41 by wdonnell          #+#    #+#             */
/*   Updated: 2022/10/10 17:38:47 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"
#include <stdio.h>

void	init_info(t_info *info)
{
	info->num_ants = -1;
	info->num_rooms = 0;
	info->start = NULL;
	info->end = NULL;
}

void	init_data(t_data *data)
{
	data->zoom = 5;
	data->x_zoom = 1;
	data->y_zoom = 1;
	data->x_offset = 10;
	data->y_offset = 10;
	data->color = 0x00FFFFFF;
	data->alpha = 0;
	data->beta = 0;
	data->gamma = 0;
	data->room_arr = NULL;
}

int	main(void)
{
	t_data	data;
	t_info	info;
	t_room	*room_arr;
	int		idx;

	srand(time(0));
	init_info(&info);
	init_data(&data);
	data.info = &info;
	read_in_info(&info, &room_arr);
	data.room_arr = room_arr;
	idx = lookup(info.start, info.num_rooms, &room_arr);
	room_arr[idx].in_path = 0;
	idx = lookup(info.end, info.num_rooms, &room_arr);
	room_arr[idx].in_path = 0;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1920, 1080, " lem-in visualizer");
	draw_graph(&data);
	mlx_hook(data.win, 2, 0, controls, &data);
	mlx_loop(data.mlx);
	return (0);
}
