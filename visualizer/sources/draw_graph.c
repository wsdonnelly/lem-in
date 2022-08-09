/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 10:36:41 by wdonnell          #+#    #+#             */
/*   Updated: 2022/05/11 11:50:14 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static void	set_zoom_offset(t_data *data, int i)
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
}

static void	draw_room_names(t_data *data, int i)
{
	if (!ft_strcmp(data->room_arr[i].name, data->info->start))
		mlx_string_put(data->mlx, data->win, data->room_arr[i].point.x, \
		data->room_arr[i].point.y, 0x000080FF, "start");
	else if (!ft_strcmp(data->room_arr[i].name, data->info->end))
		mlx_string_put(data->mlx, data->win, data->room_arr[i].point.x, \
		data->room_arr[i].point.y, 0x0000FF00, "end");
	else
		mlx_string_put(data->mlx, data->win, data->room_arr[i].point.x, \
		data->room_arr[i].point.y, \
		0x00FFFFFF, data->room_arr[i].name);
}

static void	set_colors(int colors[])
{
	colors[0] = COLOR1;
	colors[1] = COLOR2;
	colors[2] = COLOR3;
	colors[3] = COLOR4;
	colors[4] = COLOR5;
	colors[5] = COLOR6;
	colors[6] = COLOR7;
	colors[7] = COLOR8;
	colors[8] = COLOR9;
	colors[9] = COLOR10;
}

static void	draw_edges(t_data *data, int i)
{
	t_link	*temp;
	int		colors[10];

	set_colors(colors);
	temp = data->room_arr[i].link;
	while (temp)
	{
		if (data->room_arr[i].in_path == 0 && \
		data->room_arr[temp->link].in_path > -1)
			data->color = colors[data->room_arr[temp->link].in_path % 10];
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
}

void	draw_graph(t_data *data)
{
	int		i;

	display_controls(data);
	i = 0;
	while (i < data->info->num_rooms)
	{
		set_zoom_offset(data, i);
		rotate(&data->room_arr[i].point, data);
		draw_room_names(data, i);
		i++;
	}
	i = 0;
	while (i < data->info->num_rooms)
	{
		draw_edges(data, i);
		i++;
	}
}
