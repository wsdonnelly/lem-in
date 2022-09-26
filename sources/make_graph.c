/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:46:53 by wdonnell          #+#    #+#             */
/*   Updated: 2022/09/26 21:37:41 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
* check both names are found in room list
*/

static int	names_in_list(t_data *data, char *name1, char *name2)
{
	t_node	*temp;
	int		check1;
	int		check2;

	check1 = 0;
	check2 = 0;
	temp = data->name_list;
	while (temp)
	{
		if (!ft_strcmp(temp->name, name1))
			check1 = 1;
		else if (!ft_strcmp(temp->name, name2))
			check2 = 1;
		if (check1 && check2)
			return (1);
		temp = temp->next;
	}
	return (0);
}

/* 
* read each link and add each room to graph (if not already added)
*/

void	add_to_graph(t_data *data, char *line)
{
	char	**room;

	room = ft_strsplit(line, '-');
	if (room[2] || !room[1] || !names_in_list(data, room[0], room[1]))
	{
		free(line);
		free_str_arr(room);
		exit_error(data, "ERROR");
	}

	set_rooms(room, data);
	free_str_arr(room);
	store_data(data, line);
}
