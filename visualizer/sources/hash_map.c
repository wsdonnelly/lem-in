/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:35:23 by wdonnell          #+#    #+#             */
/*   Updated: 2022/04/23 15:30:58 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int	hasher(char *name, int num_rooms)
{
	int	i;
	int	index;

	index = 0;
	i = 0;
	while (name[i])
	{
		index += (int)name[i] / 13;
		i++;
	}
	index %= num_rooms;
	return (index);
}

int	hash_map(char *name, t_info *info, t_room **room_arr)
{
	int	index;
	int	i;


	i = 0;
	index = hasher(name, info->num_rooms);
	while ((*room_arr)[index].name != NULL)
	{
		index++;
		index %= info->num_rooms;
	}
	(*room_arr)[index].name = ft_strdup(name);
	return (index);
}

int	lookup(char *name, int num_rooms, t_room **room_arr)
{
	int	index;

	index = hasher (name, num_rooms);
	while (ft_strcmp((*room_arr)[index].name, name))
	{
		index++;
		index %= num_rooms;
	}
	return (index);
}
