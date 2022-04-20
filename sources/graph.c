/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:10:33 by wdonnell          #+#    #+#             */
/*   Updated: 2022/04/19 16:00:06 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room *malloc_graph(t_data *data)
{
	int	size = (data->num_rooms - 2) * 2 + 2;
	int	i;
	t_room *temp;
	
	//printf("size: %d\n", size);
	data->size = size;
	temp = (t_room *)malloc(sizeof(t_room ) * size);
	//if (!temp)
		//exit ERROR
	i = 0;
	while (i < size) //init here
	{
		temp[i].name = NULL;
		temp[i].start = FALSE;
		temp[i].end = FALSE;
		temp[i].neighbors = NULL;
		i++;
	}
	return (temp);
}

void	set_start_rooms(char *start_room, char *room_2, t_room **graph, t_data *data)
{
	int index_start;
	int index_2in;
	int index_2out;

	char *name_2in;
	char *name_2out;

	t_edge *forward;
	t_edge *reverse;

	name_2in = ft_strjoin(room_2, "in");
	name_2out = ft_strjoin(room_2, "out");

	index_start = hash_map(start_room, data->size, graph);
	data->start_index = index_start;
	index_2in = hash_map(name_2in, data->size, graph);
	free(name_2in);
	index_2out = hash_map(name_2out, data->size, graph);
	free(name_2out);

	(*graph)[index_start].start = TRUE;

	forward = add_edge(&(*graph)[index_start].neighbors, index_2in);
	if (forward)
	{
		reverse = add_reverse_edge(&(*graph)[index_2in].neighbors, index_start, forward);
		forward->reverse_edge = reverse;
	}

	forward = add_edge(&(*graph)[index_2in].neighbors, index_2out);
	if (forward)
	{
		reverse = add_reverse_edge(&(*graph)[index_2out].neighbors, index_2in, forward);
		forward->reverse_edge = reverse;
	}
	forward = add_edge(&(*graph)[index_2out].neighbors, index_start);
	if (forward)
	{
		reverse = add_reverse_edge(&(*graph)[index_start].neighbors, index_2out, forward);
		forward->reverse_edge = reverse;
	}

}

void	set_end_rooms(char *end_room, char *room_2, t_room **graph, t_data *data)
{
	int index_end;
	int index_2in;
	int index_2out;

	char *name_2in;
	char *name_2out;

	t_edge *forward;
	t_edge *reverse;

	name_2in = ft_strjoin(room_2, "in");
	name_2out = ft_strjoin(room_2, "out");

	index_end = hash_map(end_room, data->size, graph);
	data->end_index = index_end;
	index_2in = hash_map(name_2in, data->size, graph);
	free(name_2in);
	index_2out = hash_map(name_2out, data->size, graph);
	free(name_2out);

	(*graph)[index_end].end = TRUE;

	forward = add_edge(&(*graph)[index_end].neighbors, index_2in);
	if (forward)
	{
		reverse = add_reverse_edge(&(*graph)[index_2in].neighbors, index_end, forward);
		forward->reverse_edge = reverse;
	}

	forward = add_edge(&(*graph)[index_2in].neighbors, index_2out);
	if (forward)
	{
		reverse = add_reverse_edge(&(*graph)[index_2out].neighbors, index_2in, forward);
		forward->reverse_edge = reverse;
	}
	forward = add_edge(&(*graph)[index_2out].neighbors, index_end);
	if (forward)
	{
		reverse = add_reverse_edge(&(*graph)[index_end].neighbors, index_2out, forward);
		forward->reverse_edge = reverse;
	}
}

void	both_start_end(char *start_room, char *end_room, t_room **graph, t_data *data)
{
	int index_start;
	int index_end;
	
	t_edge *forward;
	t_edge *reverse;

	index_start = hash_map(start_room, data->size, graph);
	index_end = hash_map(end_room, data->size, graph);

	(*graph)[index_start].start = TRUE;
	(*graph)[index_end].end = TRUE;

	forward = add_edge(&(*graph)[index_start].neighbors, index_end);
	if (forward)
	{
		reverse = add_reverse_edge(&(*graph)[index_end].neighbors, index_start, forward);
		forward->reverse_edge = reverse;
	}

}

void	set_rooms(char **room, t_room **graph, t_data *data)
{
	int index_1in;
	int index_1out;
	int index_2in;
	int index_2out;

	char *name_1in;
	char *name_1out;
	char *name_2in;
	char *name_2out;

	t_edge *forward;
	t_edge *reverse;

	name_1in = ft_strjoin(room[0], "in");
	name_1out = ft_strjoin(room[0], "out");
	name_2in = ft_strjoin(room[1], "in");
	name_2out = ft_strjoin(room[1], "out");

	index_1in = hash_map(name_1in, data->size, graph);
	free(name_1in);
	index_1out = hash_map(name_1out, data->size, graph);
	free(name_1out);
	index_2in = hash_map(name_2in, data->size, graph);
	free(name_2in);
	index_2out = hash_map(name_2out, data->size, graph);
	free(name_2out);

	forward = add_edge(&(*graph)[index_1in].neighbors, index_1out);
	if (forward)
	{
		reverse = add_reverse_edge(&(*graph)[index_1out].neighbors, index_1in, forward);
		forward->reverse_edge = reverse;
	}

	forward = add_edge(&(*graph)[index_1out].neighbors, index_2in);
	if (forward)
	{
		reverse = add_reverse_edge(&(*graph)[index_2in].neighbors, index_1out, forward);
		forward->reverse_edge = reverse;
	}
	forward = add_edge(&(*graph)[index_2in].neighbors, index_2out);
	if (forward)
	{
		reverse = add_reverse_edge(&(*graph)[index_2out].neighbors, index_2in, forward);
		forward->reverse_edge = reverse;
	}
	forward = add_edge(&(*graph)[index_2out].neighbors, index_1in);
	if (forward)
	{
		reverse = add_reverse_edge(&(*graph)[index_1in].neighbors, index_2out, forward);
		forward->reverse_edge = reverse;
	}
}

void	create_graph(t_data *data, t_room **graph, char *line)
{
	char	**room;
	//int		data->size;

	//data->size = data->size;
	//printf("data->size: %d\n", data->size);
	room = ft_strsplit(line, '-');
	if (!ft_strcmp(room[0], data->start) && ft_strcmp(room[1], data->end))
		set_start_rooms(room[0], room[1], graph, data);
	else if (!ft_strcmp(room[1], data->start) && ft_strcmp(room[0], data->end))
		set_start_rooms(room[1], room[0], graph, data);
	else if (!ft_strcmp(room[0], data->end) && ft_strcmp(room[1], data->start))
		set_end_rooms(room[0], room[1], graph, data);
	else if (!ft_strcmp(room[1], data->end) && ft_strcmp(room[0], data->start))
		set_end_rooms(room[1], room[0], graph, data);

	else if (!ft_strcmp(room[0], data->start) && !ft_strcmp(room[1], data->end))
		both_start_end(room[0], room[1], graph, data);
	else if (!ft_strcmp(room[0], data->end) && !ft_strcmp(room[1], data->start))
	 	both_start_end(room[1], room[0], graph, data);
	else
		set_rooms(room, graph, data);

	free_str_arr(room);
}
