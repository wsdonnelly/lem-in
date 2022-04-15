/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 14:14:49 by wdonnell          #+#    #+#             */
/*   Updated: 2022/04/15 15:55:31 by wdonnell         ###   ########.fr       */
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
		index *= (int)name[i];
		i++;
	}
	index %= info->num_rooms;

	do {
		if (room_arr[index].name == NULL)
		{
			room_arr[index].name = ft_strdup(name);
			return (index);
		}
		else
		{
			++index;
			index %= info->num_rooms;
		}
			

	} while (room_arr[index].name != NULL);

	return (index);
}

void	read_rooms(t_info *info, t_room *room_arr)
{
	char	*line;
	char	**rooms;
	int		index;

	while (get_next_line(0, &line) > 0)
	{
		printf("line: %s\n", line);
		if (ft_strchr(line, (int)'-'))
		{
			rooms = ft_strsplit(line, '-');
			//add room[0] to rooms arr
			//hasher room[0]
			index = hasher(rooms[0], info, room_arr);
			index = hasher(rooms[1], info, room_arr);
			//add link to room[1]
			//add room[1] to room arr
			//add link to room[0]
			free_str_arr(rooms);
		}

		free(line);
		
	}
}