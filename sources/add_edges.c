/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_edges.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 15:37:19 by wdonnell          #+#    #+#             */
/*   Updated: 2022/10/18 13:31:13 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/* 
* functions related to adding edges and reverse edges to lists of edges
*/

t_edge	*add_edge(t_data *data, int index1, int index2)
{
	t_edge	**head;
	t_edge	*temp;

	head = &(*data->graph)[index1].neighbors;
	temp = *head;
	while (temp)
	{
		if (temp->next_room_index == index2 && temp->flow == 0)
			return (NULL);
		temp = temp->next;
	}
	temp = (t_edge *)malloc(sizeof(t_edge));
	if (!temp)
		exit_error(data, "ERROR");
	temp->next_room_index = index2;
	temp->is_forward = 1;
	temp->flow = 0;
	temp->reverse_edge = NULL;
	temp->next = *head;
	*head = temp;
	return (temp);
}

t_edge	*add_reverse_edge(t_data *data, int index1, int next, t_edge *forward)
{
	t_edge	*temp;
	t_edge	**head;

	head = &(*data->graph)[index1].neighbors;
	temp = (t_edge *)malloc(sizeof(t_edge));
	if (!temp)
		exit_error(data, "ERROR");
	temp->next_room_index = next;
	temp->is_forward = 0;
	temp->flow = 1;
	temp->reverse_edge = forward;
	temp->next = *head;
	*head = temp;
	return (temp);
}
