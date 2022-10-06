/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:49:06 by jjuntune          #+#    #+#             */
/*   Updated: 2022/10/06 15:02:35 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	free_edge_list(t_edge *head)
{
	t_edge	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free (temp);
	}
}

void	free_graph(t_room **graph, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->size)
	{
		if ((*graph)[i].name)
			free((*graph)[i].name);
		free_edge_list((*graph)[i].neighbors);
		i++;
	}
	if (*graph)
		free (*graph);
}

static void	free_name_list(t_node *head)
{
	t_node	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free (temp->name);
		free (temp);
	}
}

void	free_data(t_data *data)
{
	if (data->start)
		free(data->start);
	if (data->end)
		free(data->end);
	if (data->name_list)
		free_name_list(data->name_list);
}
