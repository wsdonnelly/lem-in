/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_in_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:53:46 by wdonnell          #+#    #+#             */
/*   Updated: 2022/04/26 12:03:54 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static void	get_number_ants(t_data *data, t_info *info, char **line)
{
	if (get_next_line(0, line))
	{
		info->num_ants = ft_atoi(*line);
		printf("numantz: %d\n", info->num_ants);
		free (*line);
		return ;
	}
	exit_error(data, "GNL error");

}
void	get_comment(t_info *info, char *line)
{
	char **list;

	list = ft_strsplit(line, ' ');
	if (!ft_strcmp(list[1], "num_rooms"))
		info->num_rooms = ft_atoi(list[2]);
	else if (!ft_strcmp(list[1], "start"))
		info->start = ft_strdup(list[2]);
	else if (!ft_strcmp(list[1], "end"))
		info->end = ft_strdup(list[2]);
	free_str_arr(list);
}

t_room *malloc_room_arr(t_data *data, t_info *info)
{
	t_room *temp;
	int		i;
	//temp = malloc(sizeof(t_room) * info->num_rooms);
	temp = NULL;
	if (!temp)
		exit_error(data, "malloc error");
	i = 0;
	while (i < info->num_rooms)//init room array
	{
		temp[i].name = NULL;
		temp[i].link = NULL;
		temp[i].z = rand() % 23;
		i++;
	}
	return (temp);
}


void	read_in_info(t_data *data, t_info *info, t_room **room_arr)
{
	char	*line;
	int		start;
	int		end;
	int		flag = 0;
	int max_coordinate;

	start = FALSE;
	end = FALSE;
	max_coordinate = 0;
	get_number_ants(data, info, &line);
	//free (line);

	while (get_next_line(0, &line) > 0)
	{
		
		if (!ft_strcmp("##start", line) || !ft_strcmp("##end", line))
		{
			free (line);
			continue ;
		}
		if (line[0] == '#')
		{
			get_comment(info, line);
			free (line);
			continue ;
		}
		if (info->end != NULL && !flag)
		{
				
			*room_arr = malloc_room_arr(data, info);
			flag = 1;
		}

		if (ft_strchr(line, (int)' '))
		{
			read_rooms(info, room_arr, line, &max_coordinate);
			free(line);
			continue ;
		}
		if (ft_strchr(line, (int)'-'))//make better
		{
			add_links(room_arr, line, info->num_rooms);
			free (line);
			continue ;
		}
		free (line);
	}
	printf("MAx COOrdinate: %d\n", max_coordinate);

}
