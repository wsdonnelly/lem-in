/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 10:01:55 by wdonnell          #+#    #+#             */
/*   Updated: 2022/10/12 14:00:28 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	init_parse(t_parse *parse)
{
	parse->room_check = FALSE;
	parse->flag = FALSE;
}

/*
* activate a flag siginfying the "start" or "end" has been found
* if the next line is valid set as "end" or "start" and deactivte flag
*/

static void	get_start_end(t_data *data, char *line)
{
	if (data->start_index == -1 || data->end_index == -1)
		exit_error(data, "ERROR");
	if (!ft_strcmp("##start", line))
	{
		data->start_index = -1;
		store_data(data, line);
	}
	else if (!ft_strcmp("##end", line))
	{
		data->end_index = -1;
		store_data(data, line);
	}
	else
		store_data(data, line);
}

/*
* read input data line by line and check for errors
*/

static void	parse_data(t_data *data, t_room **graph)
{
	t_parse	parse;

	init_parse(&parse);
	while (get_next_line(0, &parse.line) > 0)
	{
		if (parse.line[0] == '#')
		{
			get_start_end(data, parse.line);
			continue ;
		}
		if (ft_strchr(parse.line, (int) ' '))
		{
			if (parse.room_check)
				exit_error(data, "ERROR");
			check_rooms(data, parse.line);
			continue ;
		}
		if (ft_strchr(parse.line, (int) '-'))
		{
			check_links(&parse, data, graph);
			continue ;
		}
		free(parse.line);
		exit_error(data, "ERROR");
	}
}

static void	get_number_ants(t_data *data)
{
	char	*line;

	if (get_next_line(0, &line) > 0 && line[0] && is_valid_int(line) \
	&& !ft_strchr(line, (int) ' '))
	{
		data->num_ants = ft_atoi(line);
		store_data(data, line);
		if (data->num_ants > 0)
			return ;
	}
	exit_error(data, "ERROR");
}

void	read_map(t_data *data, t_room **graph)
{
	get_number_ants(data);
	parse_data(data, graph);
}
