/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:46:53 by wdonnell          #+#    #+#             */
/*   Updated: 2022/05/24 12:24:36 by wdonnell         ###   ########.fr       */
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
* create and init graph array
*/

static t_room	*malloc_graph(t_data *data)
{
	int		size;
	int		i;
	t_room	*temp;

	size = (data->num_rooms - 2) * 2 + 2;
	data->size = size;
	temp = (t_room *)malloc(sizeof(t_room) * size);
	if (!temp)
		exit_error(data, "ERROR");
	i = 0;
	while (i < size)
	{
		temp[i].name = NULL;
		temp[i].neighbors = NULL;
		i++;
	}
	return (temp);
}

/*
* check that graph is only malloc'd once
*/

void	make_graph(int *flag, t_data *data, t_room **graph)
{
	*graph = malloc_graph(data);
	*flag = TRUE;
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
	if (!ft_strcmp(room[0], data->start) && ft_strcmp(room[1], data->end))
		set_start_rooms(room[0], room[1], data);
	else if (!ft_strcmp(room[1], data->start) && ft_strcmp(room[0], data->end))
		set_start_rooms(room[1], room[0], data);
	else if (!ft_strcmp(room[0], data->end) && ft_strcmp(room[1], data->start))
		set_end_rooms(room[0], room[1], data);
	else if (!ft_strcmp(room[1], data->end) && ft_strcmp(room[0], data->start))
		set_end_rooms(room[1], room[0], data);
	else if (!ft_strcmp(room[0], data->start) && !ft_strcmp(room[1], data->end))
		both_start_end(room[0], room[1], data);
	else if (!ft_strcmp(room[0], data->end) && !ft_strcmp(room[1], data->start))
		both_start_end(room[1], room[0], data);
	else
		set_rooms(room, data);
	free_str_arr(room);
	store_data(data, line);
}
