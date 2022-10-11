/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BFS_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:54:52 by wdonnell          #+#    #+#             */
/*   Updated: 2022/10/06 12:57:51 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	enqueue(t_queue *queue, int index)
{
	queue->tail++;
	queue->queue[queue->tail] = index;
}

int	dequeue(t_queue *queue)
{
	int	idx;

	idx = queue->queue[queue->head];
	queue->head++;
	return (idx);
}

void	init_visited(t_data *data, t_room *graph)
{
	int	i;

	i = 0;
	while (i < data->size)
		graph[i++].visited = 0;
}

int	*create_queue(t_data *data, t_queue *queue)
{
	int	*arr;

	arr = (int *)malloc(sizeof(int) * data->size);
	if (!arr)
		exit (0);
	queue->head = 0;
	queue->tail = -1;
	return (arr);
}
