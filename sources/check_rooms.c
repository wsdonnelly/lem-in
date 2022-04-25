/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:31:28 by wdonnell          #+#    #+#             */
/*   Updated: 2022/04/25 11:27:12 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	set_start_end(t_data *data, char *line)
{
	char	**all;

	if (data->start_index || data->end_index)
	{
		all = ft_strsplit(line, ' ');
		if (data->start_index)
		{
			data->start = ft_strdup(all[0]);
			data->start_index = FALSE;
		}
		else
		{
			data->end = ft_strdup(all[0]);
			data->end_index = FALSE;
		}
		free_str_arr(all);
	}
}

static int	add_name_to_list(t_node **head, char *name)
{
	t_node	*temp;

	temp = malloc(sizeof(t_node));
	if (!temp)
		return (0);
	temp->name = ft_strdup(name);
	temp->next = *head;
	*head = temp;
	return (1);
}

static int	check_coordinate_errors(t_data *data, char *line)
{
	char	**coordinate;

	coordinate = ft_strsplit(line, ' ');
	if (!coordinate[1] || !coordinate[2] || coordinate[3])
	{
		free_str_arr(coordinate);
		return (0);
	}
	if (!is_valid_int(coordinate[1]) || !is_valid_int(coordinate[2]))
	{
		free_str_arr(coordinate);
		return (0);
	}
	if (ft_atoi(coordinate[1]) < 0 || ft_atoi(coordinate[2]) < 0)
	{
		free_str_arr(coordinate);
		return (0);
	}
	if (!add_name_to_list(&data->name_list, coordinate[0]))
		return (0);
	free_str_arr(coordinate);
	return (1);
}

void	check_rooms(t_data *data, char *line)
{
	if (!check_coordinate_errors(data, line))
	{
		free(line);
		exit_error(data, "ERROR coord");
	}
	set_start_end(data, line);
	data->num_rooms++;
	free (line);
}
