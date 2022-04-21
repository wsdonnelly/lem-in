/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 10:01:55 by wdonnell          #+#    #+#             */
/*   Updated: 2022/04/21 15:58:00 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void set_start_end(t_data *data, char *line)
{
	char **all;

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


static int	get_number_ants(t_data *data, char **line)
{

	if (get_next_line(0, line) && *line[0] && is_valid_int(*line) && !ft_strchr(*line, (int)' '))
	{
		data->num_ants = ft_atoi(*line);
		if (data->num_ants <= 0)
			return (0);
		return (1);
	}
	return (0);
}

int	add_name_to_list(t_node **head, char *name)
{
	t_node *temp;

	temp = malloc(sizeof(t_node));
	if (!temp)
		return (0);
	temp->name = ft_strdup(name);
	temp->next = *head;
	*head = temp;
	return (1);
}

int	check_coordinate_errors(t_data *data, char *line)
{
	char **coordinate;

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
	//add name here
	if (!add_name_to_list(&data->name_list, coordinate[0]))
		return (0);
	//
	free_str_arr(coordinate);
	return (1);
}

void	check_rooms()
{

}


void	read_map(t_data *data, t_room **graph)
{
	char	*line;
	int		flag;

	flag = FALSE;

	if (!get_number_ants(data, &line))
	{
		free(line);
		exit_error(graph, data, "ERROR");
	}
	free(line);
	while (get_next_line(0, &line) > 0)
	{
		if (!line[0])
		{
			free(line);
			exit_error(graph, data, "ERROR empty line");
		}
		if (line[0] == '#')
		{
			//skip comments
			if (!ft_strcmp("##start", line))
				data->start_index = TRUE;
			else if (!ft_strcmp("##end", line))
				data->end_index = TRUE;
			free (line);
			continue ;
		}
		if (ft_strchr(line, (int)' '))
		{
			check_rooms();

			if (!check_coordinate_errors(data, line))
			{
				free(line);
				exit_error(graph, data, "ERROR coord");
			}
			set_start_end(data, line);
			data->num_rooms++;
			free (line);
			continue ;
		}
		if (ft_strchr(line, (int)'-'))
		{
			if (!flag)
			{
				*graph = malloc_graph(data);
				flag = TRUE;
			}
			create_graph(data, graph, line);
			free (line);
			continue;
		}
		free (line);
		exit_error(graph, data, "BAD LINE");
	}
}
