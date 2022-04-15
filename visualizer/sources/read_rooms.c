/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 14:14:49 by wdonnell          #+#    #+#             */
/*   Updated: 2022/04/15 21:18:26 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int	hasher(char *name, t_info *info, t_room *room_arr)
{
	int	index;
	int	i;

	i = 0;
	index = 1;
	while (name[i])
	{
		index += (int)name[i] / 13;
		i++;
	}
	index %= info->num_rooms;
printf("INIDEX %d \n", index);
	while (room_arr[index].name != NULL)
	{
		
		index++;
		index %= info->num_rooms;
	}
	room_arr[index].name = ft_strdup(name);
	
	return (index);
}

void	read_rooms(t_info *info, t_room *room_arr, char *line, int *max_coordinate)
{
	char	**room_info;
	int		index;

	
	
	room_info = ft_strsplit(line, ' ');
	//add room[0] to rooms arr
	//hasher room[0]
	
	index = hasher(room_info[0], info, room_arr);
	room_arr[index].x = ft_atoi(room_info[1]);
	room_arr[index].y = ft_atoi(room_info[2]);
	if (room_arr[index].x > *max_coordinate)
		*max_coordinate = room_arr[index].x;
	//printf("room_arr[%d]->x %d\n", index, room_arr[index].x);
	//printf("room_arr[%d]->y %d\n", index, room_arr[index].y);
	//add link to room[1]
	//add room[1] to room arr
	//add link to room[0]
	free_str_arr(room_info);
}