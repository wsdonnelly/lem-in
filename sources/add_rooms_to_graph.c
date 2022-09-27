/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_rooms_to_graph.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:10:33 by wdonnell          #+#    #+#             */
/*   Updated: 2022/09/27 10:12:18 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>
/*
* Collection of funtions to create the duplicte rooms (eg. 1in 1out)
* or single rooms for start or end
* and all the edge connections between these rooms
*/

static void	add_edges(t_data *data, int idx_a, int idx_b)
{
	t_edge *edge1;
	t_edge *edge2;
	
	edge1 = add_edge(data, idx_a, idx_b);
	edge2 = add_edge(data, idx_b, idx_a);

	edge1->reverse_edge = edge2;
	edge2->reverse_edge = edge1;

}

void	set_rooms(char **room, t_data *data)
{
	int index1;
	int index2;

	
	index1 = hash_map(room[0], data->num_rooms, data->graph);
	index2 = hash_map(room[1], data->num_rooms, data->graph);
	if (!ft_strcmp(room[0], data->start))
		data->start_index = index1;
	else if (!ft_strcmp(room[1], data->start))
		data->start_index = index2;
	else if (!ft_strcmp(room[0], data->end))
		data->end_index = index1;
	else if (!ft_strcmp(room[1], data->end))
		data->end_index = index2;
	add_edges(data, index1, index2);

}
/*
void	set_rooms(char **room, t_data *data)
{
	t_name	name;

	name.one_in = ft_strjoin(room[0], "I");
	name.one_out = ft_strjoin(room[0], "O");
	name.two_in = ft_strjoin(room[1], "I");
	name.two_out = ft_strjoin(room[1], "O");
	name.index_1in = hash_map(name.one_in, data->num_rooms, data->graph);
	free(name.one_in);
	name.index_1out = hash_map(name.one_out, data->num_rooms, data->graph);
	free(name.one_out);
	name.index_2in = hash_map(name.two_in, data->num_rooms, data->graph);
	free(name.two_in);
	name.index_2out = hash_map(name.two_out, data->num_rooms, data->graph);
	free(name.two_out);
	add_edges(data, name.index_1in, name.index_1out);
	add_edges(data, name.index_1out, name.index_2in);
	add_edges(data, name.index_2in, name.index_2out);
	add_edges(data, name.index_2out, name.index_1in);
}
*/