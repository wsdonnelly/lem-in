/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 12:22:41 by wdonnell          #+#    #+#             */
/*   Updated: 2022/05/04 16:20:55 by wdonnell         ###   ########.fr       */
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

void	init_data(t_data *data)
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
	//*room_arr = NULL;
	//data.room_arr = NULL;
	data.info = &info;
	read_in_info(&data, &info, &room_arr);
	data.room_arr = room_arr;
	idx = lookup(info.start, info.num_rooms, &room_arr);
	room_arr[idx].in_path = TRUE;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1920, 1080, "visualizer");
	draw_graph(&data);
	mlx_hook(data.win, 2, 0, controls, &data);
	mlx_loop(data.mlx);

	return (0);
}
