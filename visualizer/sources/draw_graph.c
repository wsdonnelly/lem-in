/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 10:36:41 by wdonnell          #+#    #+#             */
/*   Updated: 2022/05/03 21:49:08 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"


void	draw_graph(t_data *data)
{
	int i;
	t_link *temp;
	
	i = 0;
	while (i < data->info->num_rooms)
	{
		//transform
		data->room_arr[i].point.x = data->room_arr[i].x * data->x_zoom;
		data->room_arr[i].point.y = data->room_arr[i].y * data->y_zoom;
		data->room_arr[i].point.x = data->zoom * data->room_arr[i].x * data->x_zoom;
		data->room_arr[i].point.y = data->zoom * data->room_arr[i].y * data->y_zoom;
		data->room_arr[i].point.z = data->zoom * data->room_arr[i].z;
		data->room_arr[i].point.x += data->x_offset;
		data->room_arr[i].point.y += data->y_offset;
		rotate(&data->room_arr[i].point, data);
		if (!ft_strcmp(data->room_arr[i].name, data->info->start))
			mlx_string_put(data->mlx, data->win, data->room_arr[i].point.x, data->room_arr[i].point.y, \
			0x000000FF, "start");
		else if (!ft_strcmp(data->room_arr[i].name, data->info->end))
			mlx_string_put(data->mlx, data->win, data->room_arr[i].point.x, data->room_arr[i].point.y, \
			0x0000FF00, "end");
		else
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
			if (data->room_arr[i].in_path && data->room_arr[temp->link].in_path)
				data->color = 0x00FF00FF;
			else
				data->color = 0x00FFFFFF;
			make_line(data, data->room_arr[i].point, data->room_arr[temp->link].point);
			
			temp = temp->next;
		}
		i++;
	}
}