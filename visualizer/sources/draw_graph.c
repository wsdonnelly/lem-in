/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 10:36:41 by wdonnell          #+#    #+#             */
/*   Updated: 2022/05/10 11:31:51 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static void	display_controls(t_data *data)
{
	mlx_string_put(data->mlx, data->win, \
	1600, 930, 0xFFFFFF, "------------->Controls");
	mlx_string_put(data->mlx, data->win, \
	1600, 950, 0xFFFFFF, "arrow keys: move graph");
	mlx_string_put(data->mlx, data->win, \
	1600, 970, 0xFFFFFF, "+(=) and - : zoom");
	mlx_string_put(data->mlx, data->win, \
	1600, 990, 0xFFFFFF, "x and y : stretch graph");
	mlx_string_put(data->mlx, data->win, \
	1600, 1010, 0xFFFFFF, "numpad 4-5-6-7-8-9: rotate");
	mlx_string_put(data->mlx, data->win, \
	1600, 1050, 0xFFFFFF, "esc: exit");
}

void	draw_graph(t_data *data)
{
	int		i;
	t_link	*temp;
	int		colors[10] = {COLOR1, COLOR2, COLOR3, COLOR4, COLOR5, \
	COLOR6, COLOR7, COLOR8, COLOR9, COLOR10};

	display_controls(data);
	i = 0;
	while (i < data->info->num_rooms)
	{
		data->room_arr[i].point.x = data->room_arr[i].x * data->x_zoom;
		data->room_arr[i].point.y = data->room_arr[i].y * data->y_zoom;
		data->room_arr[i].point.x = \
		data->zoom * data->room_arr[i].x * data->x_zoom;
		data->room_arr[i].point.y = \
		data->zoom * data->room_arr[i].y * data->y_zoom;
		data->room_arr[i].point.z = data->zoom * data->room_arr[i].z;
		data->room_arr[i].point.x += data->x_offset;
		data->room_arr[i].point.y += data->y_offset;
		rotate(&data->room_arr[i].point, data);
		if (!ft_strcmp(data->room_arr[i].name, data->info->start))
			mlx_string_put(data->mlx, data->win, data->room_arr[i].point.x, \
			data->room_arr[i].point.y, 0x000000FF, "start");
		else if (!ft_strcmp(data->room_arr[i].name, data->info->end))
			mlx_string_put(data->mlx, data->win, data->room_arr[i].point.x, \
			data->room_arr[i].point.y, 0x0000FF00, "end");
		else
			mlx_string_put(data->mlx, data->win, data->room_arr[i].point.x, \
			data->room_arr[i].point.y, \
			0x00FFFFFF, data->room_arr[i].name);
		i++;
	}
	i = 0;
	while (i < data->info->num_rooms)
	{
		temp = data->room_arr[i].link;
		while (temp)
		{
			if (data->room_arr[i].in_path == 0 && \
			data->room_arr[temp->link].in_path > -1)
				data->color = colors[data->room_arr[temp->link].in_path % 3];
			else if ((data->room_arr[i].in_path > -1 && \
			data->room_arr[i].in_path == data->room_arr[temp->link].in_path) || \
			(data->room_arr[i].in_path > -1 && \
			data->room_arr[temp->link].in_path == 0))
				data->color = colors[data->room_arr[i].in_path % 10];
			else
				data->color = 0xb4FFFFFF;
			make_line(data, data->room_arr[i].point, \
			data->room_arr[temp->link].point);
			temp = temp->next;
		}
		i++;
	}
}
