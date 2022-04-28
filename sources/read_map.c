/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 10:01:55 by wdonnell          #+#    #+#             */
/*   Updated: 2022/04/28 10:52:33 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	get_start_end(t_data *data, char *line)
{
	if (!ft_strcmp("##start", line))
	{
		data->start_index = TRUE;
		store_data(data, line);
	}
	else if (!ft_strcmp("##end", line))
	{
		data->end_index = TRUE;
		store_data(data, line);
	}
	else
		free (line);
}

static void	parse_data(t_data *data, t_room **graph)
{
	char	*line;
	int		flag;

	flag = FALSE;
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == '#')
		{
			get_start_end(data, line);
			continue ;
		}
		if (ft_strchr(line, (int) ' '))
		{
			check_rooms(data, line);
			continue ;
		}
		if (ft_strchr(line, (int) '-'))
		{
			make_graph(&flag, data, graph);
			add_to_graph(data, line);
			continue ;
		}
		free (line);
		exit_error(data, "ERRORparse");
	}
}

static void	get_number_ants(t_data *data)
{
	char	*line;

	if (get_next_line(0, &line) && line[0] && is_valid_int(line) \
	&& !ft_strchr(line, (int) ' '))
	{
		data->num_ants = ft_atoi(line);
		free (line);
		if (data->num_ants > 0)
			return ;
	}
	exit_error(data, "ERRORants");
}

void	read_map(t_data *data, t_room **graph)
{
	get_number_ants(data);
	parse_data(data, graph);
}
