/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:10:33 by wdonnell          #+#    #+#             */
/*   Updated: 2022/04/17 16:28:42 by wdonnell         ###   ########.fr       */
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

void	set_start_rooms(char *start_room, char *room_2, t_room **graph, int num_rooms)
{
	int index_start;
	int index_2in;
	int index_2out;

	char *name_start;
	char *name_2in;
	char *name_2out;

	name_start = ft_strdup(start_room);
	name_2in = ft_strjoin(room_2, "in");
	name_2out = ft_strjoin(room_2, "out");

	index_start = hash_map(name_start, num_rooms, graph);
	free(name_start);
	index_2in = hash_map(name_2in, num_rooms, graph);
	free(name_2in);
	index_2out = hash_map(name_2out, num_rooms, graph);
	free(name_2out);

	(*graph)[index_start].start = TRUE;
}

void	set_end_rooms(char *end_room, char *room_2, t_room **graph, int num_rooms)
{
	int index_end;
	int index_2in;
	int index_2out;

	char *name_end;
	char *name_2in;
	char *name_2out;

	name_end = ft_strdup(end_room);
	name_2in = ft_strjoin(room_2, "in");
	name_2out = ft_strjoin(room_2, "out");

	index_end = hash_map(name_end, num_rooms, graph);
	free(name_end);
	index_2in = hash_map(name_2in, num_rooms, graph);
	free(name_2in);
	index_2out = hash_map(name_2out, num_rooms, graph);
	free(name_2out);

	(*graph)[index_end].end = TRUE;
}

void	set_rooms(char **room, t_room **graph, int num_rooms)
{
	int index_1in;
	int index_1out;
	int index_2in;
	int index_2out;

	char *name_1in;
	char *name_1out;
	char *name_2in;
	char *name_2out;

	name_1in = ft_strjoin(room[0], "in");
	name_1out = ft_strjoin(room[0], "out");
	name_2in = ft_strjoin(room[1], "in");
	name_2out = ft_strjoin(room[1], "out");

	index_1in = hash_map(name_1in, num_rooms, graph);
	free(name_1in);
	index_1out = hash_map(name_1out, num_rooms, graph);
	free(name_1out);
	index_2in = hash_map(name_2in, num_rooms, graph);
	free(name_2in);
	index_2out = hash_map(name_2out, num_rooms, graph);
	free(name_2out);

	add_edge(&(*graph)[index_1in].neighbors, index_1out);
	add_edge(&(*graph)[index_1out].neighbors, index_2in);
	add_edge(&(*graph)[index_2in].neighbors, index_2out);
	add_edge(&(*graph)[index_2out].neighbors, index_1in);

}

void	create_graph(t_data *data, t_room **graph, char *line)
{
	char	**room;
	int		num_rooms;

	num_rooms = data->size;
	//printf("num_rooms: %d\n", num_rooms);
	room = ft_strsplit(line, '-');
	if (!ft_strcmp(room[0], data->start) && ft_strcmp(room[1], data->end))
		set_start_rooms(room[0], room[1], graph, num_rooms);
	else if (!ft_strcmp(room[1], data->start) && ft_strcmp(room[0], data->end))
		set_start_rooms(room[1], room[0], graph, num_rooms);
	else if (!ft_strcmp(room[0], data->end) && ft_strcmp(room[1], data->start))
		set_end_rooms(room[0], room[1], graph, num_rooms);
	else if (!ft_strcmp(room[1], data->end) && ft_strcmp(room[0], data->start))
		set_end_rooms(room[1], room[0], graph, num_rooms);

	else if ((!ft_strcmp(room[0], data->start) || !ft_strcmp(room[1], data->start)) \
	 && (ft_strcmp(room[0], data->end) || ft_strcmp(room[1], data->end)))
	 	return ;
	else
		set_rooms(room, graph, num_rooms);

	free_str_arr(room);
}
