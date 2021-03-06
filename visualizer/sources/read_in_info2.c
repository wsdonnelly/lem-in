/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_in_info2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:43:24 by wdonnell          #+#    #+#             */
/*   Updated: 2022/05/25 21:10:30 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

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

	if (!ft_strcmp("##start", line) || !ft_strcmp("##end", line))
	{
		free(line);
		return ;
	}
	list = ft_strsplit(line, ' ');
	if (!ft_strcmp(list[0], "#num_rooms"))
		info->num_rooms = ft_atoi(list[1]);
	else if (!ft_strcmp(list[0], "#start"))
		info->start = ft_strdup(list[1]);
	else if (!ft_strcmp(list[0], "#end"))
		info->end = ft_strdup(list[1]);
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
