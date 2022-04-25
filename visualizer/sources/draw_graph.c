/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 10:36:41 by wdonnell          #+#    #+#             */
/*   Updated: 2022/04/23 15:42:21 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void draw_line()
{
	
}

void	draw_graph(t_data *data)
{
	int i;
	t_link *temp;
	
	i = 0;
	while (i < data->info->num_rooms)
	{
	

		//transform
		data->room_arr[i].point.x = data->zoom * data->room_arr[i].x;
		data->room_arr[i].point.y = data->zoom * data->room_arr[i].y;
		data->room_arr[i].point.z = data->zoom * data->room_arr[i].z;

		data->room_arr[i].point.x += data->x_offset;
		data->room_arr[i].point.y += data->y_offset;
	
		rotate(&data->room_arr[i].point, data);
		//put name
		mlx_string_put(data->mlx, data->win, data->room_arr[i].point.x, data->room_arr[i].point.y, \
		0x00FFFFFF, data->room_arr[i].name);
		i++;
	}

	i = 0;
	while (i < data->info->num_rooms)
	{
		temp = data->room_arr[i].link;
		while (temp)
		{
			make_line(data, data->room_arr[i].point, data->room_arr[temp->link].point);
			printf("i: %d\n", i);
			printf("point a: %s\n", data->room_arr[i].name);
			printf("point b: %s\n\n", data->room_arr[temp->link].name);
			temp = temp->next;
		}
		i++;
	}
}