/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_capacity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 09:17:15 by wdonnell          #+#    #+#             */
/*   Updated: 2022/09/19 13:36:02 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include<stdio.h>

void	change_capacity(t_room *graph, t_data *data)
{
	data->shortest_path = create_room_on_path(&graph[data->end_index]);
	//avoid setting capacity of edge connecting end to 0;
	int idx = graph[data->end_index].previous_idx;

	while (graph[idx].previous_idx >= 0)
	{
		data->shortest_path = create_room_on_path(&graph[data->end_index]);
		graph[idx].previous_edge->capacity ^= 1;
		graph[idx].previous_edge->reverse_edge->capacity ^= 1;
		idx = graph[idx].previous_idx;
	}
}

/*
static void	update_nbr(char *s, t_room *graph, t_edge **nbr)
{
	while (ft_strcmp(s, graph[(*nbr)->next_room_index].name) && (*nbr)->next)
		*nbr = (*nbr)->next;
}

static void	update_nbr_n(char *s, t_room *graph, t_edge **nbr, int len)
{
	while (ft_strncmp(s, graph[(*nbr)->next_room_index].name, len) \
		&& (*nbr)->next)
		*nbr = (*nbr)->next;
}

static void	get_in_or_out(char *cur, int *in_or_out)
{
	if (ft_strcmp("t", cur + ft_strlen(cur) - 1))
			*in_or_out = 2;
	else
		*in_or_out = 3;
}

static void	change_cap_2(char *cur, t_edge	*nbr, t_room *graph, t_path *path)
{
	int		ioo;
	t_edge	*neighbor2;

	get_in_or_out(cur, &ioo);
	if (ft_strncmp(cur, graph[nbr->next_room_index].name, ft_strlen(cur) - ioo))
	{
		if (ioo == 3)
		{
			neighbor2 = graph[nbr->next_room_index].neighbors;
			update_nbr_n(graph[nbr->next_room_index].name, graph, &neighbor2, \
				ft_strlen(graph[nbr->next_room_index].name) - 2);
			nbr = graph[neighbor2->next_room_index].neighbors;
			update_nbr_n(cur, graph, &nbr, ft_strlen(cur) - 3);
			nbr->capacity = 1;
		}
		else
		{
			neighbor2 = path->room->neighbors;
			update_nbr_n(cur, graph, &neighbor2, ft_strlen(cur) - 2);
			neighbor2 = graph[neighbor2->next_room_index].neighbors;
			update_nbr_n(graph[nbr->next_room_index].name, graph, &neighbor2, \
				ft_strlen(graph[nbr->next_room_index].name) - 3);
			neighbor2->capacity = 0;
		}
	}
}

void	change_capacity(t_path *path, t_room *graph, t_data *data)
{
	char	*current;
	t_edge	*neighbor;

	neighbor = path->room->neighbors;
	update_nbr(path->room->previous, graph, &neighbor);
	neighbor->capacity ^= 1;
	neighbor = graph[neighbor->next_room_index].neighbors;
	current = path->room->name;
	update_nbr(current, graph, &neighbor);
	neighbor->capacity ^= 1;
	neighbor = path->room->neighbors;
	update_nbr(path->room->previous, graph, &neighbor);
	if (ft_strcmp(current, data->start) && ft_strcmp(current, data->end) \
		&& ft_strcmp(graph[neighbor->next_room_index].name, data->start) \
		&& ft_strcmp(graph[neighbor->next_room_index].name, data->end))
	{
		change_cap_2(current, neighbor, graph, path);
	}
}
*/