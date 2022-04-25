/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 14:27:42 by wdonnell          #+#    #+#             */
/*   Updated: 2022/04/25 13:26:15 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	free_str_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free (arr[i++]);
	free (arr);
}

void free_room_arr(t_data *data)
{
	int	i;
	t_link *temp;
	t_link *head;

	i = 0;
	while (i < data->info->num_rooms)
	{
		head = data->room_arr[i].link;
		free (data->room_arr[i].name);
		while (head)
		{
			temp = head;
			head = temp->next;
			free (temp);
		}
		i++;
	}
}

void free_info(t_info *info)
{
	free (info->start);
	free (info->end);
}

void free_data(t_data *data)
{
	if (data->room_arr)
		free_room_arr(data);
	free_info(data->info);
}

void exit_error(t_data *data, char *message)
{
	free (data);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	exit (EXIT_FAILURE);	
}
