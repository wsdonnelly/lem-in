/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:49:06 by jjuntune          #+#    #+#             */
/*   Updated: 2022/04/20 08:55:36 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_path	*create_room_on_path(t_room room)
{
	t_path	*path;

	path = (t_path *)malloc(sizeof(t_path));
	if (!path)
		return (NULL);
	path->room = room;
	path->next_room = NULL;
	return (path);
}

void	add_room_to_path(t_room room, t_path **path)
{
	t_path	*tmp;

	if (!*path)
		*path = create_room_on_path(room);
	else
	{
		tmp = *path;
		while (tmp->next_room)
			tmp = tmp->next_room;
		tmp->next_room = create_room_on_path(room);
	}
}
