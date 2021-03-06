/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 14:14:49 by wdonnell          #+#    #+#             */
/*   Updated: 2022/05/10 14:21:59 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	read_rooms(t_info *info, t_room **room_arr, char *line)
{
	char	**room_info;
	int		index;

	room_info = ft_strsplit(line, ' ');
	index = hash_map(room_info[0], info, room_arr);
	(*room_arr)[index].x = ft_atoi(room_info[1]);
	(*room_arr)[index].y = ft_atoi(room_info[2]);
	free_str_arr(room_info);
	free(line);
}

void	add_edge(t_link **head, int index)
{
	t_link	*temp;

	temp = *head;
	temp = malloc(sizeof(t_link));
	if (!temp)
		exit(0);
	temp->link = index;
	temp->next = *head;
	*head = temp;
}

void	add_links(t_room **room_arr, char *line, int num_rooms)
{
	char	**room;
	int		index1;
	int		index2;

	room = ft_strsplit(line, '-');
	index1 = lookup(room[0], num_rooms, room_arr);
	index2 = lookup(room[1], num_rooms, room_arr);
	add_edge(&(*room_arr)[index1].link, index2);
	free_str_arr(room);
	free(line);
}
