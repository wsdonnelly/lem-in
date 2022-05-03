/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 12:22:41 by wdonnell          #+#    #+#             */
/*   Updated: 2022/05/01 10:09:58 by wdonnell         ###   ########.fr       */
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

void init_data(t_data *data)
{
	data->zoom = 5;
	data->x_zoom = 1;
	data->y_zoom = 1;
	data->x_offset = 0;
	data->y_offset = 0;
	data->color = 0x00FFFFFF;
	data->alpha = 0;
	data->beta = 0;
	data->gamma = 0;
}

int	main()
{
	t_data data;
	t_info	info;
	t_room	*room_arr = NULL;
	int idx;

	srand(time(0));
	init_info(&info);
	init_data(&data);
	
	data.room_arr = NULL;
	data.info = &info;
	read_in_info(&data, &info, &room_arr);
	data.room_arr = room_arr;
	idx = lookup(info.start, info.num_rooms, &room_arr);
	room_arr[idx].in_path = TRUE;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1920, 1080, "visualizer");
	/*
	int i = 0;
	while (i < info.num_rooms)
	{
		printf("arr[%d].name: %s\n", i, room_arr[i].name);
		printf("arr[%d].x: %d\n", i, room_arr[i].x);
		printf("arr[%d].y: %d\n", i, room_arr[i].y);
		i++;
	}
	*/
	draw_graph(&data);
	mlx_hook(data.win, 2, 0, controls, &data);
	/*
	printf("num ants: %d\n", info.num_ants);
	printf("num rooms: %d\n", info.num_rooms);
	printf("start room: %s\n", info.start);
	printf("end room: %s\n", info.end);
	*/
	/*
	int i = 0;
	t_link *temp;
	while (i < info.num_rooms)
	{
		printf("arr[%d].name: %s\n", i, room_arr[i].name);
		//printf("arr[%d].x: %d\n", i, room_arr[i].x);
		//printf("arr[%d].y: %d\n", i, room_arr[i].y);
		temp = room_arr[i].link;
		while (temp)
		{
			printf("link name: %s link index: %d\n", room_arr[temp->link].name, temp->link);
			//printf("x: %d\n", room_arr[i].point.x);
			//printf("y: %d\n", room_arr[i].point.y);
			//printf("z: %d\n", room_arr[i].point.z);
			temp = temp->next;
		}
		printf("\n");
		i++;
	}
	*/
	
	
	
	mlx_loop(data.mlx);

	

	//free_data(&data);
	return (0);
}

