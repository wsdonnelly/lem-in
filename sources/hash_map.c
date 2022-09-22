/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 10:17:15 by wdonnell          #+#    #+#             */
/*   Updated: 2022/09/22 13:57:30 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
* Hash map functions
* The "lookup" feature is used extensivly in the visualizer and here
* is built in the check if a room has been added already
*/

static int	hasher(char *name, int num_rooms)
{
	int	i;
	int	index;

	index = 0;
	i = 0;
	while (name[i])
	{
		index += (int)name[i];
		index *= 13;
		i++;
	}
	return (index %= num_rooms);
}

int	hash_map(char *name, int num_rooms, t_room **graph)
{
	int	index;

	index = hasher(name, num_rooms);
	while ((*graph)[index].name != NULL)
	{
		if (!ft_strcmp((*graph)[index].name, name))
			return (index);
		index++;
		index %= num_rooms;
	}
	(*graph)[index].name = ft_strdup(name);
	return (index);
}
