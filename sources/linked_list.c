/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 15:37:19 by wdonnell          #+#    #+#             */
/*   Updated: 2022/04/17 16:21:50 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_edge(t_edge **head, int next)
{
	//malloc new edge
	t_edge	*temp;

	temp = malloc(sizeof(t_edge));
	//ERROR
	temp->next_room_index = next;
	temp->capacity = 1;
	temp->reverse_edge = NULL;
	temp->next = *head;
	*head = temp;
}