/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 10:01:55 by wdonnell          #+#    #+#             */
/*   Updated: 2022/05/09 13:12:08 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	get_start_end(t_data *data, char *line)
{
	if (data->start_index == -1 || data->end_index == -1)
		exit_error(data, "ERROR double start/end");
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
		free (line);
}

static void	init_parse(t_parse *parse)
{
	parse->room_check = FALSE;
	parse->flag = FALSE;
}

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
				exit_error(data, "ERROR links among rooms");
			check_rooms(data, parse.line);
			continue ;
		}
		if (ft_strchr(parse.line, (int) '-'))
		{
			parse.room_check = TRUE;
			if (data->start_index == -1 || data->end_index == -1 \
			|| !data->end || !data->start)
				exit_error(data, "ERROR start/end beofre link not room OR no end or start");
			make_graph(&parse.flag, data, graph);
			add_to_graph(data, parse.line);
			continue ;
		}
		free (parse.line);
		exit_error(data, "ERROR parse");
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
