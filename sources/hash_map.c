/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 10:17:15 by wdonnell          #+#    #+#             */
/*   Updated: 2022/04/20 14:44:01 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	hasher(char *name, int num_rooms)
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
	return (index %= num_rooms);

}

int	hash_map(char *name, int num_rooms, t_room **graph)
{
	int	index;
	int	index_cpy;
	int	i;

	i = 0;
	index = hasher(name, num_rooms);
	index_cpy = index;
	while ((*graph)[index].name != NULL)
	{
		if (!ft_strcmp((*graph)[index].name, name))
			return (index);
		index++;
		index %= num_rooms;
		if (index == index_cpy)
			return (-1);
	}
	(*graph)[index].name = ft_strdup(name);
	return (index);
}