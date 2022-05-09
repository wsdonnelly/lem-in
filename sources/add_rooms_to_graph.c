/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_rooms_to_graph.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:10:33 by wdonnell          #+#    #+#             */
/*   Updated: 2022/05/09 12:42:56 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	add_edges(t_data *data, int idx_a, int idx_b)
{
	t_edge	*forward;
	t_edge	*reverse;

	forward = add_edge(data, idx_a, idx_b);
	if (forward)
	{
		reverse = add_reverse_edge(data, idx_b, idx_a, forward);
		forward->reverse_edge = reverse;
	}
}

void	set_start_rooms(char *start_room, char *room_2, t_data *data)
{
	t_name	name;

	name.two_in = ft_strjoin(room_2, "in");
	name.two_out = ft_strjoin(room_2, "out");
	name.index_start = hash_map(start_room, data->size, data->graph);
	data->start_index = name.index_start;
	name.index_2in = hash_map(name.two_in, data->size, data->graph);
	free(name.two_in);
	name.index_2out = hash_map(name.two_out, data->size, data->graph);
	free(name.two_out);
	add_edges(data, name.index_start, name.index_2in);
	add_edges(data, name.index_2in, name.index_2out);
	add_edges(data, name.index_2out, name.index_start);
}

void	set_end_rooms(char *end_room, char *room_2, t_data *data)
{
	t_name	name;

	name.two_in = ft_strjoin(room_2, "in");
	name.two_out = ft_strjoin(room_2, "out");
	name.index_end = hash_map(end_room, data->size, data->graph);
	data->end_index = name.index_end;
	name.index_2in = hash_map(name.two_in, data->size, data->graph);
	free(name.two_in);
	name.index_2out = hash_map(name.two_out, data->size, data->graph);
	free(name.two_out);
	add_edges(data, name.index_end, name.index_2in);
	add_edges(data, name.index_2in, name.index_2out);
	add_edges(data, name.index_2out, name.index_end);
}

void	both_start_end(char *start_room, char *end_room, \
t_data *data)
{
	int	index_start;
	int	index_end;

	index_start = hash_map(start_room, data->size, data->graph);
	index_end = hash_map(end_room, data->size, data->graph);
	add_edges(data, index_start, index_end);
}

void	set_rooms(char **room, t_data *data)
{
	t_name	name;

	name.one_in = ft_strjoin(room[0], "in");
	name.one_out = ft_strjoin(room[0], "out");
	name.two_in = ft_strjoin(room[1], "in");
	name.two_out = ft_strjoin(room[1], "out");
	name.index_1in = hash_map(name.one_in, data->size, data->graph);
	free(name.one_in);
	name.index_1out = hash_map(name.one_out, data->size, data->graph);
	free(name.one_out);
	name.index_2in = hash_map(name.two_in, data->size, data->graph);
	free(name.two_in);
	name.index_2out = hash_map(name.two_out, data->size, data->graph);
	free(name.two_out);
	add_edges(data, name.index_1in, name.index_1out);
	add_edges(data, name.index_1out, name.index_2in);
	add_edges(data, name.index_2in, name.index_2out);
	add_edges(data, name.index_2out, name.index_1in);
}
