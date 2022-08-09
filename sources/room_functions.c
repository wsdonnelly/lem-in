/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:49:06 by jjuntune          #+#    #+#             */
/*   Updated: 2022/05/24 12:24:50 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path	*create_room_on_path(t_room *room)
{
	t_path	*path;

	path = (t_path *)malloc(sizeof(t_path));
	if (!path)
		return (NULL);
	path->room = room;
	path->next_room = NULL;
	return (path);
}

void	add_room_to_path(t_room *room, t_path **path)
{
	t_path	*tmp;

	if (!*path)
		*path = create_room_on_path(room);
	else
	{
		tmp = *path;
		while (tmp->next_room)
		{
			tmp = tmp->next_room;
		}
		tmp->next_room = create_room_on_path(room);
	}
}
