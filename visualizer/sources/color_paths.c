/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:07:55 by wdonnell          #+#    #+#             */
/*   Updated: 2022/05/10 11:24:57 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int	color_paths_firstline(t_room **room_arr, char *line, int num_rooms)
{
	char	**list;
	char	**info;
	int		i;
	int		idx;
	int		num_paths;

	num_paths = 0;
	list = ft_strsplit(line, ' ');
	i = 0;
	while (list[i])
	{
		num_paths++;
		info = ft_strsplit(list[i], '-');
		idx = lookup(info[1], num_rooms, room_arr);
		(*room_arr)[idx].in_path = num_paths;
		free_str_arr(info);
		i++;
	}
	free_str_arr(list);
	return (num_paths);
}

void	color_paths(t_room **room_arr, char *line, int num_rooms, int num_paths)
{
	char	**list;
	char	**info;
	int		i;
	int		idx;

	list = ft_strsplit(line, ' ');
	i = 0;
	while (list[i])
	{
		info = ft_strsplit(list[i], '-');
		if (ft_atoi(&info[0][1]) <= num_paths)
		{
			idx = lookup(info[1], num_rooms, room_arr);
			(*room_arr)[idx].in_path = ft_atoi(&info[0][1]);
		}
		free_str_arr(info);
		i++;
	}
	free_str_arr(list);
}

/*
void	color_paths(t_room **room_arr, char *line, int num_rooms)
{
	char	**list;
	char	**info;
	int		i;
	int		idx;

	list = ft_strsplit(line, ' ');
	i = 0;
	while (list[i])
	{
		info = ft_strsplit(list[i], '-');
		idx = lookup(info[1], num_rooms, room_arr);
		(*room_arr)[idx].in_path = TRUE;
		free_str_arr(info);
		i++;
	}
	free_str_arr(list);
}
*/