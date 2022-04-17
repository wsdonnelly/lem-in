/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 10:17:15 by wdonnell          #+#    #+#             */
/*   Updated: 2022/04/17 11:21:48 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	hasher(char *name, int *index, int num_rooms)
{
	int	i;

	i = 0;
	while (name[i])
	{
		*index += (int)name[i] / 13;
		i++;
	}
	*index %= num_rooms;
}

int	hash_map(char *name, int num_rooms, t_room **graph)
{
	int	index;
	int	i;

	i = 0;
	index = 0;
	
	printf("cur name: %s\n", name);
	hasher(name, &index, num_rooms);
	//printf("INDEX1 %d \n", index);
	while ((*graph)[index].name != NULL)
	{
		if (!ft_strcmp((*graph)[index].name, name))
			return (index);
		index++;
		index %= num_rooms;
	}
	(*graph)[index].name = ft_strdup(name);
printf("INDEX2 %d \n", index);
	return (index);
}