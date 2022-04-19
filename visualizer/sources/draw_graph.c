/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 10:36:41 by wdonnell          #+#    #+#             */
/*   Updated: 2022/04/19 11:41:09 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void draw_line()
{
	
}

void	draw_graph(t_data *data)
{
	int i;

	
	i = 0;
	while (i < data->info->num_rooms)
	{
		//transform
		data->room_arr[i].t_x = data->zoom * data->room_arr[i].x;
		data->room_arr[i].t_y = data->zoom * data->room_arr[i].y;
		//put name
		mlx_string_put(data->mlx, data->win, data->room_arr[i].t_x, data->room_arr[i].t_y, 0x00FFFFFF, data->room_arr[i].name);
		//draw lines
		draw_line();
		i++;
	}
}