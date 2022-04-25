/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:10:33 by wdonnell          #+#    #+#             */
/*   Updated: 2022/04/22 16:50:43 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*malloc_graph(t_data *data)
{
	int		size;
	int		i;
	t_room	*temp;

	size = (data->num_rooms - 2) * 2 + 2;
	data->size = size;
	temp = (t_room *)malloc(sizeof(t_room) * size);
	if (!temp)
		exit_error(NULL, data, "ERROR");
	i = 0;
	while (i < size)
	{
		temp[i].name = NULL;
		temp[i].neighbors = NULL;
		i++;
	}
	return (temp);
}

void	add_edges(t_room **graph, t_data *data, int idx_a, int idx_b)
{
	t_edge	*forward;
	t_edge	*reverse;

	forward = add_edge(graph, data, idx_a, idx_b);
	if (forward)
	{
		reverse = add_reverse_edge(graph, data, idx_b, idx_a, forward);
		forward->reverse_edge = reverse;
	}
}

void	set_start_rooms(char *start_room, char *room_2, \
t_room **graph, t_data *data)
{
	t_name	name;

	name.two_in = ft_strjoin(room_2, "in");
	name.two_out = ft_strjoin(room_2, "out");
	name.index_start = hash_map(start_room, data->size, graph);
	data->start_index = name.index_start;
	name.index_2in = hash_map(name.two_in, data->size, graph);
	free(name.two_in);
	name.index_2out = hash_map(name.two_out, data->size, graph);
	free(name.two_out);
	add_edges(graph, data, name.index_start, name.index_2in);
	add_edges(graph, data, name.index_2in, name.index_2out);
	add_edges(graph, data, name.index_2out, name.index_start);
}

void	set_end_rooms(char *end_room, char *room_2, \
t_room **graph, t_data *data)
{
	t_name	name;

	name.two_in = ft_strjoin(room_2, "in");
	name.two_out = ft_strjoin(room_2, "out");
	name.index_end = hash_map(end_room, data->size, graph);
	data->end_index = name.index_end;
	name.index_2in = hash_map(name.two_in, data->size, graph);
	free(name.two_in);
	name.index_2out = hash_map(name.two_out, data->size, graph);
	free(name.two_out);
	add_edges(graph, data, name.index_end, name.index_2in);
	add_edges(graph, data, name.index_2in, name.index_2out);
	add_edges(graph, data, name.index_2out, name.index_end);
}

void	both_start_end(char *start_room, char *end_room, \
t_room **graph, t_data *data)
{
	int	index_start;
	int	index_end;

	index_start = hash_map(start_room, data->size, graph);
	index_end = hash_map(end_room, data->size, graph);
	add_edges(graph, data, index_start, index_end);
}

void	set_rooms(char **room, t_room **graph, t_data *data)
{
	t_name	name;

	name.one_in = ft_strjoin(room[0], "in");
	name.one_out = ft_strjoin(room[0], "out");
	name.two_in = ft_strjoin(room[1], "in");
	name.two_out = ft_strjoin(room[1], "out");
	name.index_1in = hash_map(name.one_in, data->size, graph);
	free(name.one_in);
	name.index_1out = hash_map(name.one_out, data->size, graph);
	free(name.one_out);
	name.index_2in = hash_map(name.two_in, data->size, graph);
	free(name.two_in);
	name.index_2out = hash_map(name.two_out, data->size, graph);
	free(name.two_out);
	add_edges(graph, data, name.index_1in, name.index_1out);
	add_edges(graph, data, name.index_1out, name.index_2in);
	add_edges(graph, data, name.index_2in, name.index_2out);
	add_edges(graph, data, name.index_2out, name.index_1in);
}

int	names_in_list(t_data *data, char *name1, char *name2)
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

void	create_graph(t_data *data, t_room **graph, char *line)
{
	char	**room;

	room = ft_strsplit(line, '-');
	if (room[2] || !room[1] || !names_in_list(data, room[0], room[1]))
	{
		free(line);
		free_str_arr(room);
		exit_error(graph, data, "ERROR link");
	}
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
	free (line);
}
