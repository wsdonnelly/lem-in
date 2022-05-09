/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:31:28 by wdonnell          #+#    #+#             */
/*   Updated: 2022/05/09 12:44:05 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	set_start_end(t_data *data, char *line)
{
	char	**all;

	all = ft_strsplit(line, ' ');
	if (data->start_index == -1)
	{
		if (data->start)
			exit_error(data, "ERROR double start");
		data->start = ft_strdup(all[0]);
		data->start_index = -2;
	}
	else
	{
		if (data->end)
			exit_error(data, "ERROR double end");
		data->end = ft_strdup(all[0]);
		data->end_index = -2;
	}
	free_str_arr(all);
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

static int	name_in_list(t_data *data, char *name)
{
	t_node	*temp;

	temp = data->name_list;
	while (temp)
	{
		if (!ft_strcmp(temp->name, name))
			return (1);
		temp = temp->next;
	}
	return (0);
}

static int	check_coordinate_errors(t_data *data, char *line)
{
	char	**coordinate;

	coordinate = ft_strsplit(line, ' ');
	if (name_in_list(data, coordinate[0]))
		return (0);
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
		exit_error(data, "ERROR coord OR double name");
	}
	if (data->start_index == -1 || data->end_index == -1)
		set_start_end(data, line);
	store_data(data, line);
	data->num_rooms++;
}
