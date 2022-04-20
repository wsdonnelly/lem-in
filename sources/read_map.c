/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 10:01:55 by wdonnell          #+#    #+#             */
/*   Updated: 2022/04/20 20:50:02 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void set_start_end(int *start, int *end, t_data *data, char *line)
{
	char **all;

	if (*start || *end)
	{
		all = ft_strsplit(line, ' ');
		if (*start)
		{
			data->start = ft_strdup(all[0]);
			*start = FALSE;
		}
		else
		{
			data->end = ft_strdup(all[0]);
			*end = FALSE;
		}
		free_str_arr(all);
	}
}

//zero ants?
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

int	check_coordinate_errors(char *line)
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
	free_str_arr(coordinate);
	return (1);
}



void	read_map(t_data *data, t_room **graph)
{
	char	*line;
	int		start;
	int		end;
	int		flag;

	flag = FALSE;
	start = FALSE;
	end = FALSE;

	if (!get_number_ants(data, &line))
	{
		//free(line);
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
				start = TRUE;
			else if (!ft_strcmp("##end", line))
				end = TRUE;
			free (line);
			continue ;
		}
		if (ft_strchr(line, (int)' '))
		{
			if (!check_coordinate_errors(line))
			{
				free(line);
				exit_error(graph, data, "ERROR coord");
			}
			set_start_end(&start, &end, data, line);
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
