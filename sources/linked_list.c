/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 15:37:19 by wdonnell          #+#    #+#             */
/*   Updated: 2022/04/20 21:06:42 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_edge	*add_edge(t_room **graph, t_data *data, int index1, int index2)
{
	t_edge **head;
	t_edge	*temp;

	head = &(*graph)[index1].neighbors;
	temp = *head;
	while (temp)
	{
		if (temp->next_room_index == index2 && temp->capacity == 1)
			return NULL;
		temp = temp->next;
	}
	temp = malloc(sizeof(t_edge));
	if (!temp)
		exit_error(graph, data, "ERROR");
	temp->next_room_index = index2;
	temp->capacity = 1;
	temp->reverse_edge = NULL;
	temp->next = *head;
	*head = temp;

	return (temp);
}

t_edge	*add_reverse_edge(t_room **graph, t_data *data, int index1,  int next, t_edge *forward)
{
	t_edge	*temp;
	t_edge **head;

	head = &(*graph)[index1].neighbors;
	temp = malloc(sizeof(t_edge));
	if (!temp)
		exit_error(graph, data, "ERROR");
	temp->next_room_index = next;
	temp->capacity = 0;
	temp->reverse_edge = forward;
	temp->next = *head;
	*head = temp;
	return (temp);
}

/*
t_edge	*add_reverse_edge(t_edge **head, int next, t_edge *forward)
{
	t_edge	*temp;


	temp = malloc(sizeof(t_edge));
	if (!temp)
		return (NULL);
	temp->next_room_index = next;
	temp->capacity = 0;
	temp->reverse_edge = forward;
	temp->next = *head;
	*head = temp;
	return (temp);
}
*/