/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_capacity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:21:17 by wdonnell          #+#    #+#             */
/*   Updated: 2022/10/11 11:54:36 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	create_path_group(t_data *data)
{
	t_path_group	*tmp;
	t_path_group	*last;

	tmp = malloc(sizeof(t_path_group));
	if (!tmp)
		exit(0);
	tmp->paths = NULL;
	tmp->next_path_group = NULL;
	last = data->path_group;
	if (!data->path_group)
		data->path_group = tmp;
	else
	{
		while (last->next_path_group)
			last = last->next_path_group;
		last->next_path_group = tmp;
	}
}

void	create_path_set(t_data *data, t_queue_node *path_to_add, int steps)
{
	t_path_set		*tmp_path;
	t_path_set		*last;
	t_path_group	*cur;

	tmp_path = malloc(sizeof(t_path_set));
	if (!tmp_path)
		exit(0);
	tmp_path->path = path_to_add;
	tmp_path->steps = steps;
	tmp_path->ants_on_path = 0;
	tmp_path->lines = 0;
	tmp_path->paths_total = 0;
	tmp_path->ant_nums = NULL;
	tmp_path->next_path = NULL;
	cur = data->path_group;
	while (cur->next_path_group)
		cur = cur->next_path_group;
	last = cur->paths;
	if (!cur->paths)
		cur->paths = tmp_path;
	else
	{
		while (last->next_path)
			last = last->next_path;
		last->next_path = tmp_path;
	}
}

static void	add_room_to_stack(int index, t_data *data, int *count)
{
	t_queue_node	*tmp;

	tmp = malloc(sizeof(t_queue_node));
	if (!tmp)
		exit(0);
	(*count)++;
	tmp->index = index;
	tmp->next = data->cur_path;
	data->cur_path = tmp;
}

static void	update_selected(t_data *data, t_room *graph, int idx, int flow)
{
	if (flow)
	{
		graph[idx].previous_edge->flow = 1;
		graph[idx].previous_edge->reverse_edge->flow = 0;
	}
	else if (!flow)
	{
		if (idx != data->end_index)
			graph[idx].in_path = 1;
		else
		{
			if (graph[idx].previous_idx == data->start_index)
				graph[idx].in_path = 1;
		}

	}
}

int	change_capacity(t_data *data, t_room *graph, int save, int flow)
{
	int		count;
	int		idx;
	char	*prev;

	count = 0;
	idx = data->end_index;
	prev = graph[data->end_index].name;
	graph[data->end_index].previous_edge->flow = 1;
	graph[data->end_index].previous_edge->reverse_edge->flow = 0;
	data->cur_path = NULL;
	if (save)
		add_room_to_stack(data->end_index, data, &count);
	while (graph[idx].previous_idx >= 0)
	{
		if (save)
		{
			if (ft_strcmp(prev, graph[idx].name))
				add_room_to_stack(idx, data, &count);
		}
		update_selected(data, graph, idx, flow);
		prev = graph[idx].name;
		idx = graph[idx].previous_idx;
	}
	return (count);
}
