/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_in_info2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:43:24 by wdonnell          #+#    #+#             */
/*   Updated: 2022/09/22 13:43:29 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"
#include <stdio.h>

void	get_first_line(t_info *info, char **line)
{
	if (get_next_line(0, line) > 0)
	{
		if (!ft_strcmp(*line, "no valid path found"))
		{
			ft_putendl("no valid path found");
			exit (0);
		}
		else if (!ft_strcmp(*line, "ERROR"))
			exit(0);
		info->num_ants = ft_atoi(*line);
		free (*line);
		return ;
	}
	exit(0);
}

void	get_comment(t_info *info, char *line)
{
	char	**list;

	list = ft_strsplit(line, ' ');
	//printf("list[0]: %s\n", list[0]);
	if (!ft_strcmp(list[0], "#num_rooms"))
	{
		//printf("list[1] %s\n", list[1]);
		info->num_rooms = ft_atoi(list[1]);
	}
	else if (!ft_strcmp(list[0], "#start"))
	{
		//printf("list[1] %s\n", list[1]);
		info->start = ft_strdup(list[1]);
	}
	else if (!ft_strcmp(list[0], "#end"))
	{
		//printf("list[1] %s\n", list[1]);
		info->end = ft_strdup(list[1]);
	}
	free_str_arr(list);
	free(line);
}

void	add_paths(t_info *info, t_room **room_arr, t_parse *parse)
{
	if (!parse->flag2)
	{
		parse->num_paths = \
		color_paths_firstline(room_arr, parse->line, info->num_rooms);
		parse->flag2 = 1;
	}
	else
		color_paths(room_arr, parse->line, info->num_rooms, parse->num_paths);
}
