/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 14:03:10 by wdonnell          #+#    #+#             */
/*   Updated: 2022/04/09 14:46:29 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

//void	add_room(t_room **room_arr, int num_rooms, char *line)
void	add_room(t_room **room_arr, int num_rooms)
{
	t_room	*temp;
	int		i;
	
	temp = (t_room *)malloc(sizeof(t_room) * num_rooms);
	//if (!temp)
		//error
	//test
	i = 0;
	while (i < num_rooms - 1)
	{
		printf("HERE2\n");
		temp[i] = *room_arr[i];
		i++;
	}
	printf("HERE1\n");
	temp[i].room_num = num_rooms;
	printf("HERE\n");
	//free(*room_arr);
	*room_arr = temp;
	free (temp);
}
