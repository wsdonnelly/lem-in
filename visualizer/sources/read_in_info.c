/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_in_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:53:46 by wdonnell          #+#    #+#             */
/*   Updated: 2022/05/10 11:33:12 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static void	get_first_line(t_data *data, t_info *info, char **line)
{
	if (get_next_line(0, line))
	{
		if (!ft_strcmp(*line, "no valid path found"))
		{
			ft_putendl("no valid path found");
			exit (0);
		}
		else if (!ft_strcmp(*line, "ERROR"))
		{
			ft_putendl("ERROR");
			exit(0);
		}
		info->num_ants = ft_atoi(*line);
		free (*line);
		return ;
	}
	exit_error(data, "GNL error");
}

void	get_comment(t_info *info, char *line)
{
	char	**list;

	list = ft_strsplit(line, ' ');
	if (!ft_strcmp(list[0], "#num_rooms"))
		info->num_rooms = ft_atoi(list[1]);
	else if (!ft_strcmp(list[0], "#start"))
		info->start = ft_strdup(list[1]);
	else if (!ft_strcmp(list[0], "#end"))
		info->end = ft_strdup(list[1]);
	free_str_arr(list);
}

t_room	*malloc_room_arr(t_info *info)
{
	t_room	*temp;
	int		i;

	temp = malloc(sizeof(t_room) * info->num_rooms);
	if (!temp)
		exit(0);
	i = 0;
	while (i < info->num_rooms)
	{
		temp[i].name = NULL;
		temp[i].link = NULL;
		temp[i].z = rand() % 23;
		temp[i].in_path = -1;
		i++;
	}
	return (temp);
}

void	read_in_info(t_data *data, t_info *info, t_room **room_arr)
{
	char	*line;
	int		start;
	int		end;
	int		flag;
	int		flag2;
	int		num_paths;

	flag = 0;
	flag2 = 0;
	start = FALSE;
	end = FALSE;
	get_first_line(data, info, &line);
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
			*room_arr = malloc_room_arr(info);
			flag = 1;
		}
		if (ft_strchr(line, (int) ' ') && !ft_strchr(line, (int) 'L'))
		{
			read_rooms(info, room_arr, line);
			free(line);
			continue ;
		}
		if (ft_strchr(line, (int) '-') && !ft_strchr(line, (int) 'L'))
		{
			add_links(room_arr, line, info->num_rooms);
			free (line);
			continue ;
		}
		if (ft_strchr(line, (int) 'L'))
		{	
			if (!flag2)
			{
				num_paths = color_paths_firstline(room_arr, line, info->num_rooms);
				flag2 = 1;
			}
			else
				color_paths(room_arr, line, info->num_rooms, num_paths);
			free (line);
			continue ;
		}
		free (line);
	}
}
