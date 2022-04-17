/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 10:01:55 by wdonnell          #+#    #+#             */
/*   Updated: 2022/04/17 12:01:01 by wdonnell         ###   ########.fr       */
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

static void	get_number_ants_rooms(t_data *data, char **line)
{
	//get number of ants //ADD ft_is_int()
	if (get_next_line(0, line))
	{
		if (data->num_ants < 0 && !ft_strchr(*line, (int)' '))
			data->num_ants = ft_atoi(*line);
		else
			data->num_ants = 0;
	}
	//else
		//return ERROR empty file
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

	get_number_ants_rooms(data, &line);
	free (line);
	while (get_next_line(0, &line) > 0)
	{
		if (!ft_strcmp("##start", line) || !ft_strcmp("##end", line))
		{
			if (!ft_strcmp("##start", line))
				start = TRUE;
			else
				end = TRUE;
			free (line);
			continue ;
		}
		if (line[0] == '#')
		{
			//get comment?
			free (line);
			continue ;
		}
		if (ft_strchr(line, (int)' '))//make better error checking
		{
			set_start_end(&start, &end, data, line);
			data->num_rooms++;
		}
		if (ft_strchr(line, (int)'-'))//make better
		{
			if (!flag)
			{
				//printf("malloc graph\n");
				*graph = malloc_graph(data);
				flag = TRUE;
			}
			
			create_graph(data, graph, line);
			free (line);
			continue;
		}
		free (line);
	}
}



